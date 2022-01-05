/**
 * CodeEditor.h
 * An extension of the classic CRichEdit control to turn it into a code editor.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#if !defined(AFX_CODEEDITOR_H__841ADDF8_A2F7_4175_95D0_B19F221B2892__INCLUDED_)
#define AFX_CODEEDITOR_H__841ADDF8_A2F7_4175_95D0_B19F221B2892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../resource.h"

/**
 * An extension of the classic CRichEdit control to turn it into a code editor.
 */
class CCodeEditor : public CRichEditCtrl {
protected:


public:
	// Initialization.
	CCodeEditor();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCodeEditor)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCodeEditor();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCodeEditor)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CODEEDITOR_H__841ADDF8_A2F7_4175_95D0_B19F221B2892__INCLUDED_)
