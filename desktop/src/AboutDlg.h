/**
 * AboutDlg.h
 * Application's standard about dialog.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#if !defined(AFX_ABOUTDLG_H__05E6DABF_121D_4928_8E91_0272B8D598F4__INCLUDED_)
#define AFX_ABOUTDLG_H__05E6DABF_121D_4928_8E91_0272B8D598F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

/**
 * Application's about dialog.
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUTDLG_H__05E6DABF_121D_4928_8E91_0272B8D598F4__INCLUDED_)
