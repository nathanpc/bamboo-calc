/**
 * CommandEdit.cpp
 * An extension of the classic CEdit control with some helpful things already
 * implemented for your convinience.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "CommandEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * Creates a new control.
 */
CCommandEdit::CCommandEdit() {
}

/**
 * Destroys the control.
 */
CCommandEdit::~CCommandEdit() {
}

BEGIN_MESSAGE_MAP(CCommandEdit, CEdit)
	//{{AFX_MSG_MAP(CCommandEdit)
	ON_WM_GETDLGCODE()
	ON_WM_CHAR()
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillFocus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * Handles the WM_GETDLGCODE message and in this case enables the return key
 * to be captured by the OnChar event handler.
 *
 * @return Dialog code mask.
 */
UINT CCommandEdit::OnGetDlgCode() {
	// Assure that single-line a edit control will receive Return key by
	// handling WM_GETDLGCODE message this specific way.
	return CEdit::OnGetDlgCode() | DLGC_WANTALLKEYS;
}

/**
 * Handles a character input in the edit control and can ignore certain key
 * codes.
 *
 * @param nChar   Input character key code.
 * @param nRepCnt Key repetition count.
 * @param nFlags  Special flags.
 */
void CCommandEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	// Check if we actually got a Return key.
	if (VK_RETURN == nChar) {
		AfxGetMainWnd()->SetFocus();
		return;
	}
	
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}

/**
 * Handling this in order to make the the Return key submit thing work.
 */
void CCommandEdit::OnKillFocus() {
	// Handling this in order to make the the Return key thing work.
}
