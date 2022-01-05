/**
 * CodeEditor.cpp
 * An extension of the classic CRichEdit control to turn it into a code editor.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "CodeEditor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * Code editor constructor.
 */
CCodeEditor::CCodeEditor() {
}

/**
 * Code editor destructor.
 */
CCodeEditor::~CCodeEditor() {
}


BEGIN_MESSAGE_MAP(CCodeEditor, CRichEditCtrl)
	//{{AFX_MSG_MAP(CCodeEditor)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
