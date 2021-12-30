/**
 * MainDlg.h
 * Main application's dialog window.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#if !defined(AFX_MAINDLG_H__05E6DABF_121D_4928_8E91_0272B8D598F4__INCLUDED_)
#define AFX_MAINDLG_H__05E6DABF_121D_4928_8E91_0272B8D598F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../resource.h"
#include "CommandEdit.h"
#include "EnvironmentList.h"

/**
 * Application's main dialog window.
 */
class CMainDlg : public CDialog {
protected:
	Bamboo::Lisp *m_pBamboo;
	CMenu m_menu;
	HACCEL m_hAccel;

	// Initialization stuff.
	void InitializeEnvironment();

public:
	CMainDlg(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_DESKTOP_DIALOG };
	CEnvironmentList	m_lstEnvironment;
	CCommandEdit	m_edtCommand;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	void ShowAboutDialog();

    virtual void OnCancel();
    virtual void OnOK();

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnMenuFileExit();
	afx_msg void OnMenuHelpAbout();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__05E6DABF_121D_4928_8E91_0272B8D598F4__INCLUDED_)
