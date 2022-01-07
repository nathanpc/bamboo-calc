/**
 * EnvironmentList.h
 * An extension of the CListCtrl that automatically displays the state of the
 * environment in the Bamboo Lisp interpreter instance.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef AFX_ENVIRONMENTLIST_H__F473D243_7A2B_4FEC_80C8_961108B30D9A__INCLUDED_
#define AFX_ENVIRONMENTLIST_H__F473D243_7A2B_4FEC_80C8_961108B30D9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../resource.h"

/**
 * An extension of the CListCtrl that automatically displays the state of the
 * environment in the Bamboo Lisp interpreter instance.
 */
class CEnvironmentList : public CListCtrl {
protected:
	env_t *m_pEnv;

	// Setup and configuration.
	void SetupColumns();

public:
	// Initialization.
	CEnvironmentList();
	void InitializeList(env_t *pEnv);

	// Items and attributes.
	void Clear();
	void Refresh();
	void AddItem(pair_t bprItem);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnvironmentList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEnvironmentList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEnvironmentList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENVIRONMENTLIST_H__F473D243_7A2B_4FEC_80C8_961108B30D9A__INCLUDED_)
