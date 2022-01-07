// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "BambooApp.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
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

void CChildView::SetCommandBar(CCeCommandBar *pwndCommandBar) {
	m_pwndCommandBar = pwndCommandBar;
}

BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		NULL, HBRUSH(COLOR_WINDOW), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

BOOL CChildView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	int ret = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	CRect rectBar;
	m_pwndCommandBar->GetWindowRect(&rectBar);

	CRect rectEdit;
	pParentWnd->GetWindowRect(&rectEdit);
	rectEdit.right -= 205;
	rectEdit.bottom -= rectBar.bottom - 1;
	m_edtCommand.Create(WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE |
		WS_VSCROLL | ES_WANTRETURN, rectEdit, this, 10002);

	CRect rectList;
	pParentWnd->GetWindowRect(&rectList);
	rectList.left = rectList.right - 200;
	rectList.bottom -= rectBar.bottom - 1;
	m_lstEnvironment.Create(WS_CHILD | WS_BORDER | WS_VISIBLE, rectList, this, 10003);

	InitializeEnvironment();

	return ret;
}

void CChildView::OnClose() 
{
	// Clean up Bamboo.
	bamboo_error_t err = bamboo_destroy(&m_pEnv);
	IF_BAMBOO_ERROR(err) {
		MessageBox(bamboo_error_detail(),
			_T("Unable to initialize Bamboo environment"),
			MB_OK | MB_ICONERROR);
	}
	
	CWnd ::OnClose();
}
