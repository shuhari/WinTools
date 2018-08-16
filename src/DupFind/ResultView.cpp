#include "stdafx.h"
#include "ResultView.h"


ResultView::ResultView() {
}


ResultView::~ResultView() {
}


int ResultView::onCreate(LPCREATESTRUCT pcs) {
	SetView(LV_VIEW_DETAILS);
	SetExtendedListViewStyle(LVS_EX_TRACKSELECT | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	insertColumn(0, LVCFMT_LEFT, 200, L"File name");
	insertColumn(1, LVCFMT_LEFT, 200, L"Path");
	insertColumn(2, LVCFMT_RIGHT, 160, L"Size");
	insertColumn(3, LVCFMT_LEFT, 200, L"Time");

	SetMsgHandled(FALSE);
	return 0;
}


void ResultView::insertColumn(int iSubItem, int fmt, int width, PCWSTR text) {
	LVCOLUMN lvc;
	memset(&lvc, 0, sizeof(lvc));
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.fmt = fmt;
	lvc.cx = width;
	lvc.pszText = (PWSTR)text;
	lvc.iSubItem = iSubItem;
	InsertColumn(0, &lvc);
}