/**
 * CommandEdit.h
 * An extension of the classic CEdit control with some helpful things already
 * implemented for your convinience.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef _COMMANDEDIT_H
#define _COMMANDEDIT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../resource.h"

class CCommandEdit : public CEdit {
public:
	CCommandEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCommandEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCommandEdit)
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif  // _COMMANDEDIT_H
