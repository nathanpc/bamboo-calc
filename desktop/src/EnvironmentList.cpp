/**
 * CEnvironmentList.cpp
 * An extension of the CListCtrl that automatically displays the state of the
 * environment in the Bamboo Lisp interpreter instance.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "stdafx.h"
#include "EnvironmentList.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * Handles the construction of the control.
 */
CEnvironmentList::CEnvironmentList() {
}

/**
 * Handles the destruction of the control.
 */
CEnvironmentList::~CEnvironmentList() {
}

/**
 * Sets up the columns for the data we'll be putting into the list.
 */
void CEnvironmentList::SetupColumns() {
	// Get control size to determine the column sizes.
	CRect rect;
	GetClientRect(&rect);
	int nColInterval = rect.Width() / 2;

	InsertColumn(0, _T("Name"), LVCFMT_LEFT, nColInterval);
	InsertColumn(1, _T("Value"), LVCFMT_LEFT, nColInterval);
}

/**
 * Initializes the environment list and associates an interpreter instance
 * with the control.
 *
 * @param pEnv Bamboo environment pointer.
 */
void CEnvironmentList::InitializeList(env_t *pEnv) {
	// Associate the interpreter instance.
	m_pEnv = pEnv;

	// Setup and populate the list.
	SetupColumns();
	Refresh();
}

/**
 * Clears the content of the list.
 */
void CEnvironmentList::Clear() {
	SetRedraw(false);
	DeleteAllItems();
	SetRedraw(true);
}

/**
 * Refreshes the content of the list.
 */
void CEnvironmentList::Refresh() {
	// Clear the list.
	Clear();

	// Populate the list without redrawing to make it faster.
	SetRedraw(false);

	// Iterate over the symbols in the environment list.
	env_t current = cdr(*m_pEnv);
	while (!nilp(current)) {
		atom_t item = car(current);
		atom_type_t item_type = cdr(item).type;

		// Filter out built-ins.
		if (item_type == ATOM_TYPE_BUILTIN)
			goto next_item;

		// Create a pair for the symbol and its value.
		pair_t pair;
		pair.atom[0] = car(item);
		pair.atom[1] = cdr(item);
		AddItem(pair);

next_item:
		// Go to the next item.
		current = cdr(current);
	}

	// Start redrawing the control.
	SetRedraw(true);
}

/**
 * Adds an symbol atom to the list.
 *
 * @param bprItem Item pair from an Bamboo::Environment.
 */
void CEnvironmentList::AddItem(pair_t bprItem) {
	LVITEM lvi;

	// Create the base item for the list.
	lvi.mask     = LVIF_TEXT; // | LVIF_IMAGE
	lvi.iItem    = GetItemCount();
	lvi.iSubItem = 0;
	lvi.pszText  = *bprItem.atom[0].value.symbol;
	//lvi.iImage = i;
	InsertItem(&lvi);

	// Add the value detail.
	TCHAR *pszValue;
	bamboo_expr_str(&pszValue, bprItem.atom[1]);
	lvi.iSubItem = 1;
	lvi.pszText  = pszValue;
	SetItem(&lvi);
	free(pszValue);
}

BEGIN_MESSAGE_MAP(CEnvironmentList, CListCtrl)
	//{{AFX_MSG_MAP(CEnvironmentList)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

