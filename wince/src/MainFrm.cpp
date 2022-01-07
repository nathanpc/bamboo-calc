/**
 * MainFrm.cpp
 * Main frame of the application.
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

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * Main frame constructor.
 */
CMainFrame::CMainFrame() {
}

/**
 * Main frame destructor.
 */
CMainFrame::~CMainFrame() {
}

/**
 * Frame creation event handler.
 */
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	// Only an Exit button in the CommandBar.
	const DWORD dwAdornmentFlags = 0; 

	// Try to actually create it.
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Create the CommandBar.
#if defined(_WIN32_WCE_PSPC)
	// MFC for Palm-Size PC.
	if(!m_wndCommandBar.Create(this) ||
			!m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME) ||
			!m_wndCommandBar.AddAdornments(dwAdornmentFlags) ||
			!m_wndCommandBar.LoadToolBar(IDR_MAINFRAME)) {
		TRACE0("Failed to create CommandBar\n");
		return -1;
	}
#else
	// MFC for Windows CE 2.1 or later.
	if(!m_wndCommandBar.Create(this) ||
			!m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME) ||
			!m_wndCommandBar.InsertSeparator(6) ||
			!m_wndCommandBar.LoadToolBar(IDR_MAINFRAME) ||
			!m_wndCommandBar.AddAdornments(dwAdornmentFlags)) {
		TRACE0("Failed to create CommandBar\n");
		return -1;
	}
#endif

	// Set the CommandBar style.
	m_wndCommandBar.SetBarStyle(m_wndCommandBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED);

	// Create a view to occupy the client area of the frame.
	m_wndView.SetCommandBar(&m_wndCommandBar);
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
			CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL)) {
		TRACE0("Failed to create view window\n");
		return -1;
	}

	return 0;
}

/**
 * Handle some things before the creation of the window.
 */
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) {
	if(!CFrameWnd::PreCreateWindow(cs))
		return false;

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.lpszClass = AfxRegisterWndClass(0);
	return true;
}


#ifdef _DEBUG
void CMainFrame::AssertValid() const {
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const {
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG

void CMainFrame::OnSetFocus(CWnd* pOldWnd) {
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra,
						  AFX_CMDHANDLERINFO* pHandlerInfo) {
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return true;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
