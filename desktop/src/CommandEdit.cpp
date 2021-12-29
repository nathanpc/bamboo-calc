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
	// Set the default prompt.
	this->SetPrompt(_T("> "));
}

/**
 * Destroys the control.
 */
CCommandEdit::~CCommandEdit() {
}

/**
 * Initializes the REPL prompt. Must be called whenever the application is
 * ready to start accepting commands.
 */
void CCommandEdit::InitializePrompt(Bamboo::Lisp *bamboo) {
	// Grab our Bamboo instance.
	this->m_bamboo = bamboo;

	// Append the prompt in the control.
	this->ReplaceSel((LPCTSTR)this->GetPrompt(), false);
}

/**
 * Executes the expression currently under the cursor.
 */
void CCommandEdit::HandleExpression() {
	// Get the expression and go to the next line.
	CString strExpression = this->GetCurrentExpression();
	this->ReplaceSel(_T("\r\n"), false);

	CString strResult;
	try {
		// Parse and evaluate the expression.
		atom_t parsed = this->m_bamboo->parse_expr((LPCTSTR)strExpression);
		atom_t result = this->m_bamboo->eval_expr(parsed);

		// Return the evaluated result.
		TCHAR *buf = this->m_bamboo->expr_str(result);
		strResult = buf;
		free(buf);
	} catch (Bamboo::BambooException& e) {
		// Return the error encountered.
		strResult.Format(_T("(%d) %s: %s"), e.error_code(), e.error_type(),
			e.error_detail());
	}

	// Show the result of the evaluated expression.
	this->ReplaceSel((LPCTSTR)strResult, false);
	
	// Prompt the user for more.
	this->ReplaceSel(_T("\r\n"), false);
	this->ReplaceSel((LPCTSTR)this->GetPrompt(), false);
}

/**
 * Gets the current expression under the cursor.
 *
 * @return Expression line under the cursor.
 */
CString CCommandEdit::GetCurrentExpression() {
	CString strExpression;

	// Get the cursor position and lengths.
	int idxCursor = this->CharFromPos(this->GetCaretPos());
	int nLine = HIWORD(idxCursor);
	int nChar = LOWORD(idxCursor);
	int nLen = this->LineLength(nChar);

	// Get the entire line buffer.
	this->GetLine(nLine, strExpression.GetBuffer(nLen), nLen);
	strExpression.ReleaseBuffer();

	// Remove the prompt from the expression.
	int nPromptLen = this->GetPrompt().GetLength();
	if (strExpression.Left(nPromptLen) == this->GetPrompt())
		strExpression.Delete(0, nPromptLen);

	return strExpression;
}

/**
 * Gets the prompt string.
 *
 * @return Prompt string.
 */
CString CCommandEdit::GetPrompt() {
	return this->m_prompt;
}

/**
 * Sets the prompt string.
 *
 * @param prompt Prompt string.
 */
void CCommandEdit::SetPrompt(CString prompt) {
	this->m_prompt = prompt;
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
		//AfxGetMainWnd()->SetFocus();
		this->HandleExpression();
		return;
	}
	
	// Let the system do its thing.
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}

/**
 * Handling this in order to make the the Return key submit thing work.
 */
void CCommandEdit::OnKillFocus() {
	// Handling this in order to make the the Return key thing work.
}
