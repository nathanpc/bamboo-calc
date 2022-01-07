/**
 * BambooApp.h
 * Bamboo Lisp IDE for Windows CE.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#if !defined(AFX_BAMBOO_H__B6301BFC_4D2B_4771_B188_925DDFA56785__INCLUDED_)
#define AFX_BAMBOO_H__B6301BFC_4D2B_4771_B188_925DDFA56785__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "../resource.h"

/**
 * Bamboo Lisp IDE for Windows CE.
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
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAMBOO_H__B6301BFC_4D2B_4771_B188_925DDFA56785__INCLUDED_)
