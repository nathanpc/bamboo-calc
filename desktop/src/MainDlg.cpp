/**
 * MainDlg.cpp
 * Main application's dialog window.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "Desktop.h"
#include "MainDlg.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * Dialog's standard constructor.
 *
 * @param pParent Parent window.
 */
CMainDlg::CMainDlg(CWnd* pParent) : CDialog(CMainDlg::IDD, pParent) {
	//{{AFX_DATA_INIT(CMainDlg)
	//}}AFX_DATA_INIT

	// Load the window's icon.
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

/**
 * Initializes the Bamboo Lisp interpreter environment in the window.
 */
void CMainDlg::InitializeEnvironment() {
	// Initialize the Bamboo Lisp interpreter environment.
	try {
		m_pBamboo = new Bamboo::Lisp();
	} catch (Bamboo::BambooException& e) {
		MessageBox(e.what(), _T("Unable to initialize Bamboo environment"),
			MB_OK | MB_ICONERROR);
		ExitProcess(static_cast<unsigned int>(e.error_code()));
	}
	
	// Initialize our prompt and variables list.
	m_lstEnvironment.InitializeList(m_pBamboo);
	m_edtCommand.InitializePrompt(m_pBamboo);

}

/**
 * Show's the about dialog.
 */
void CMainDlg::ShowAboutDialog() {
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_COMMAND(IDM_MENU_FILE_EXIT, OnMenuFileExit)
	ON_COMMAND(IDM_MENU_HELP_ABOUT, OnMenuHelpAbout)
	ON_WM_DESTROY()
	ON_COMMAND(IDA_ACCEL_QUIT, OnMenuFileExit)
	ON_COMMAND(IDA_ACCEL_HELP, OnMenuHelpAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * Dialog's standard DoDataExchange event handler.
 */
void CMainDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
	DDX_Control(pDX, IDC_LIST_ENV, m_lstEnvironment);
	DDX_Control(pDX, IDC_EDIT_COMMAND, m_edtCommand);
	//}}AFX_DATA_MAP
}

/**
 * Handles the dialog messages before they are translated via MFC.
 */
BOOL CMainDlg::PreTranslateMessage(MSG* pMsg) {
	if (m_hAccel) {
		if (::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
			return true;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

/**
 * Dialog's OnInit event handler.
 *
 * @return TRUE unless the focus was set to a control.
 */
BOOL CMainDlg::OnInitDialog() {
	// Call the parent's initialize event.
	CDialog::OnInitDialog();

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	// Add "About..." menu item to system menu.
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL) {
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);

		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.
	SetIcon(m_hIcon, TRUE);   // Set big icon
	SetIcon(m_hIcon, FALSE);  // Set small icon

	// Add a menu bar and load accelerators.
	m_menu.LoadMenu(IDR_MENU_MAIN);
	SetMenu(&m_menu);
	m_hAccel = ::LoadAccelerators(AfxGetResourceHandle(),
		MAKEINTRESOURCE(IDR_ACCEL_MAIN));

	// Initialize the Bamboo Lisp interpreter environment.
	InitializeEnvironment();
	
	return true;
}

/**
 * Dialog's OnSysCommand event handler.
 *
 * @param nID    ID of the command.
 * @param lParam Optional parameter.
 */
void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	switch (LOWORD(nID)) {
	case IDM_ABOUTBOX:
		ShowAboutDialog();
		break;
	default:
		CDialog::OnSysCommand(nID, lParam);
	}
}

/**
 * Dialog's OnPaint event handler.
 */
void CMainDlg::OnPaint()  {
	// Handle the drawing of the application's icon while minimized.
	if (IsIconic()) {
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

		// Center icon in client rectangle.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon.
		dc.DrawIcon(x, y, m_hIcon);
		return;
	}

	// Delegate to the base OnPaint handler.
	CDialog::OnPaint();
}

/**
 * Dialog's OnQueryDragIcon event handler.
 */
HCURSOR CMainDlg::OnQueryDragIcon() {
	// The system calls this to obtain the cursor to display while the user
	// drags the minimized window.
	return (HCURSOR) m_hIcon;
}

/**
 * Handles the IDOK command event.
 */
void CMainDlg::OnOK() {
	// Prevents hitting Return from closing the dialog.
}

/**
 * Handles the IDCANCEL command event.
 */
void CMainDlg::OnCancel() {
	// Prevents hitting Escape from closing the dialog.
}

/**
 * Handles the closing of the dialog when the user presses the close button.
 */
void CMainDlg::OnClose() {
	// Simulate the close event by calling the original dialog cancel event.
	CDialog::OnCancel();
}

/**
 * Handles the window destruction.
 */
void CMainDlg::OnDestroy() {
	// Clean up our allocations.
	VERIFY(DestroyAcceleratorTable(m_hAccel));
	delete this->m_pBamboo;
	
	// Continue destroying the window.
	CDialog::OnDestroy();
}

/**
 * File -> Exit menu item command event handler.
 */
void CMainDlg::OnMenuFileExit() {
	EndDialog(0);
}

/**
 * Help -> About menu item command event handler.
 */
void CMainDlg::OnMenuHelpAbout() {
	ShowAboutDialog();
}
