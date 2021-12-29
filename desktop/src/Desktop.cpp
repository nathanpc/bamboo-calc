/**
 * Bamboo IDE
 * A simple IDE to work with the Bamboo Lisp implementation.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "Desktop.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CBambooApp, CWinApp)
	//{{AFX_MSG_MAP(CBambooApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/**
 * Application's instance contructor.
 */
CBambooApp::CBambooApp() {
}

/**
 * Application's instace destructor.
 */
CBambooApp::~CBambooApp() {
}

// The one and only CBambooApp object.
CBambooApp theApp;

/**
 * Initializes an instance of the application.
 *
 * @return FALSE when it comes time to exit the application.
 */
BOOL CBambooApp::InitInstance() {
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need.
#ifdef _AFXDLL
	Enable3dControls();        // Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();  // Call this when linking to MFC statically
#endif

	// Initialize the main dialog window.
	CMainDlg dlg;
	m_pMainWnd = &dlg;

	// Show the dialog window.
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK) {
		// TODO: Place code here to handle when the dialog is
		// dismissed with OK
	} else if (nResponse == IDCANCEL) {
		// TODO: Place code here to handle when the dialog is
		// dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	// application, rather than start the application's message pump.
	return FALSE;
}
