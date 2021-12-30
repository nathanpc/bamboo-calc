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
 * @param pBamboo Bamboo Lisp instance.
 */
void CEnvironmentList::InitializeList(Bamboo::Lisp *pBamboo) {
	// Associate the interpreter instance.
	m_pBamboo = pBamboo;

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
	
	// Populate the list.
	std::vector<pair_t> items = m_pBamboo->env().list(
		Bamboo::Environment::ListFilter::FilterNothing);
		//Bamboo::Environment::ListFilter::FilterUserGenerated);
	for (size_t i = 0; i < items.size(); i++) {
		AddItem(items[i]);
	}
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
	//lvi.iImage = i%8;
	InsertItem(&lvi);

	// Add the value detail.
	TCHAR *pszValue = m_pBamboo->expr_str(bprItem.atom[1]);
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

