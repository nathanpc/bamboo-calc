/**
 * CommandEdit.cpp
 * An extension of the classic CEdit control to mimic a REPL environment.
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
	SetPrompt(_T("> "));
}

/**
 * Destroys the control.
 */
CCommandEdit::~CCommandEdit() {
}

/**
 * Initializes the REPL prompt. Must be called whenever the application is
 * ready to start accepting commands.
 *
 * @param pdlgParent     Parent dialog.
 * @param pBamboo        Bamboo Lisp instance.
 * @param lstEnvironment Environment list object.
 */
void CCommandEdit::InitializePrompt(CDialog *pdlgParent,
									Bamboo::Lisp *pBamboo,
									CEnvironmentList& lstEnvironment) {
	// Grab our parent dialog.
	m_pdlgParent = pdlgParent;

	// Grab our Bamboo instance and environment list control.
	m_pBamboo = pBamboo;
	m_plstEnvironment = &lstEnvironment;

	// Append the prompt in the control.
	ReplaceSel((LPCTSTR)GetPrompt(), false);
}

/**
 * Executes the expression currently under the cursor.
 */
void CCommandEdit::HandleExpression() {
	// Get the expression and go to the next line.
	CString strExpression = GetCurrentExpression();
	ReplaceSel(_T("\r\n"), false);

	CString strResult;
	try {
		// Parse and evaluate the expression.
		atom_t batParsed = m_pBamboo->parse_expr((LPCTSTR)strExpression);
		atom_t batResult = m_pBamboo->eval_expr(batParsed);

		// Return the evaluated result.
		TCHAR *pszBuffer = m_pBamboo->expr_str(batResult);
		strResult = pszBuffer;
		free(pszBuffer);

		// Update the environment list.
		m_plstEnvironment->Refresh();
	} catch (Bamboo::BambooException& e) {
		// Check if the user just wants to quit the application.
		if (e.error_code() == (bamboo_error_t)BAMBOO_REPL_QUIT) {
			m_pdlgParent->EndDialog(0);
			return;
		}

		// Return the error encountered.
		strResult.Format(_T("(%d) %s: %s"), e.error_code(), e.error_type(),
			e.error_detail());
	}

	// Show the result of the evaluated expression.
	ReplaceSel((LPCTSTR)strResult, false);
	
	// Prompt the user for more.
	ReplaceSel(_T("\r\n"), false);
	ReplaceSel((LPCTSTR)GetPrompt(), false);
}

/**
 * Gets the current expression under the cursor.
 *
 * @return Expression line under the cursor.
 */
CString CCommandEdit::GetCurrentExpression() {
	CString strExpression;

	// Get the cursor position and lengths.
	int idxCursor = CharFromPos(GetCaretPos());
	int nLine = HIWORD(idxCursor);
	int nChar = LOWORD(idxCursor);
	int nLen = LineLength(nChar);

	// Get the entire line buffer.
	GetLine(nLine, strExpression.GetBuffer(nLen), nLen);
	strExpression.ReleaseBuffer();

	// Remove the prompt from the expression.
	int nPromptLen = GetPrompt().GetLength();
	if (strExpression.Left(nPromptLen) == GetPrompt())
		strExpression.Delete(0, nPromptLen);

	return strExpression;
}

/**
 * Gets the prompt string.
 *
 * @return Prompt string.
 */
CString CCommandEdit::GetPrompt() {
	return m_strPrompt;
}

/**
 * Sets the prompt string.
 *
 * @param strPrompt Prompt string.
 */
void CCommandEdit::SetPrompt(CString strPrompt) {
	m_strPrompt = strPrompt;
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
		HandleExpression();
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
