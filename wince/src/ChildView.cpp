/**
 * ChildView.cpp
 * Main window of the application.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "BambooApp.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * Main window constructor.
 */
CChildView::CChildView() {
}

/**
 * Main window destructor.
 */
CChildView::~CChildView() {
}

/**
 * Initializes the Bamboo Lisp interpreter environment in the window.
 */
void CChildView::InitializeEnvironment() {
	bamboo_error_t err;

	// Initialize the Bamboo Lisp interpreter environment.
	err = bamboo_init(&m_pEnv);
	IF_BAMBOO_ERROR(err) {
		MessageBox(bamboo_error_detail(),
			_T("Unable to initialize Bamboo environment"),
			MB_OK | MB_ICONERROR);
		//ExitProcess(static_cast<unsigned int>(err));
	}

	// Populate the environment with built-ins from the REPL.
	err = repl_populate_builtins(&m_pEnv);
	IF_BAMBOO_ERROR(err) {
		MessageBox(bamboo_error_detail(),
			_T("Unable to initialize Bamboo environment"),
			MB_OK | MB_ICONERROR);
		//ExitProcess(static_cast<unsigned int>(err));
	}
	
	// Initialize our prompt and variables list.
	m_lstEnvironment.InitializeList(&m_pEnv);
	m_edtCommand.InitializePrompt(this, m_lstEnvironment, &m_pEnv);
}

/**
 * Associates the parent window's CommandBar control.
 *
 * @param pwndCommandBar Pointer to the CommandBar window.
 */
void CChildView::SetCommandBar(CCeCommandBar *pwndCommandBar) {
	m_pwndCommandBar = pwndCommandBar;
}

BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * Handle some things before the creation of the window.
 */
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) {
	if (!CWnd::PreCreateWindow(cs))
		return false;

	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, 
		NULL, HBRUSH(COLOR_WINDOW), NULL);

	return true;
}

/**
 * Handles the painting of the window.
 */
void CChildView::OnPaint() {
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

/**
 * Actually creates the window.
 */
BOOL CChildView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
						DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
						UINT nID, CCreateContext* pContext)  {
	// Create the window.
	int ret = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect,
		pParentWnd, nID, pContext);

	// Get the parent window's CommandBar rectangle.
	CRect rectBar;
	m_pwndCommandBar->GetWindowRect(&rectBar);

	// Create the command editor control.
	CRect rectEdit;
	pParentWnd->GetWindowRect(&rectEdit);
	rectEdit.right -= 205;
	rectEdit.bottom -= rectBar.bottom - 1;
	m_edtCommand.Create(WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE |
		WS_VSCROLL | ES_WANTRETURN, rectEdit, this, 10002);

	// Create the environment list control.
	CRect rectList;
	pParentWnd->GetWindowRect(&rectList);
	rectList.left = rectList.right - 200;
	rectList.bottom -= rectBar.bottom - 1;
	m_lstEnvironment.Create(WS_CHILD | WS_BORDER | WS_VISIBLE, rectList, this, 10003);

	// Initialize the Bamboo Lisp interpreter environment.
	InitializeEnvironment();

	return ret;
}

/**
 * Handles the WM_CLOSE window message.
 */
void CChildView::OnClose() {
	// Clean up Bamboo.
	bamboo_error_t err = bamboo_destroy(&m_pEnv);
	IF_BAMBOO_ERROR(err) {
		MessageBox(bamboo_error_detail(),
			_T("Unable to initialize Bamboo environment"),
			MB_OK | MB_ICONERROR);
	}
	
	// Close the window.
	CWnd ::OnClose();
}
