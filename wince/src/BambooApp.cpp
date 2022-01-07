/**
 * BambooApp.cpp
 * Bamboo Lisp IDE for Windows CE.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "BambooApp.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CBambooApp, CWinApp)
	//{{AFX_MSG_MAP(CBambooApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
END_MESSAGE_MAP()

/**
 * Application's constructor.
 */
CBambooApp::CBambooApp() : CWinApp() {
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/**
 * The one and only application object.
 */
CBambooApp theApp;

/**
 * Initializes the application instance.
 *
 * @return TRUE if everything worked.
 */
BOOL CBambooApp::InitInstance() {
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Set the root registry key.
	SetRegistryKey(_T("Innove Workshop"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object.
	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	// Create and load the frame with its resources.
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL, NULL);

	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return true;
}

/**
 * About dialog.
 */
class CAboutDlg : public CDialog {
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();		// Added for WCE apps
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD) {
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CBambooApp::OnAppAbout() {
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

BOOL CAboutDlg::OnInitDialog() {
	CDialog::OnInitDialog();
	
	CenterWindow();
	return true;  // Return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
