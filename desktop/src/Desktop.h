/**
 * Bamboo IDE
 * A simple IDE to work with the Bamboo Lisp implementation.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#if !defined(AFX_DESKTOP_H__91380568_E959_464B_B77D_A73D8A1212E9__INCLUDED_)
#define AFX_DESKTOP_H__91380568_E959_464B_B77D_A73D8A1212E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"

/**
 * Bamboo IDE application instance.
 */
class CBambooApp : public CWinApp {
public:
	CBambooApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBambooApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBambooApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKTOP_H__91380568_E959_464B_B77D_A73D8A1212E9__INCLUDED_)
