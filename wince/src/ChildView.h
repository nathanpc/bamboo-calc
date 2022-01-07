// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__89C5681C_2943_4816_8CD8_128B99CEF8E5__INCLUDED_)
#define AFX_CHILDVIEW_H__89C5681C_2943_4816_8CD8_128B99CEF8E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../../desktop/src/CommandEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd {
protected:
	CCommandEdit m_edtCommand;
	CEnvironmentList m_lstEnvironment;
	CCeCommandBar *m_pwndCommandBar;
	env_t m_pEnv;

// Construction
public:
	CChildView();

	void InitializeEnvironment();
	void SetCommandBar(CCeCommandBar *pwndCommandBar);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__89C5681C_2943_4816_8CD8_128B99CEF8E5__INCLUDED_)
