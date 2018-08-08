#include "stdafx.h"
#include "KeyView.h"


#define MSG_LIMIT					20
#define COL_OFFSET_MSG				0
#define MARGIN						8


MsgData::MsgData() {

}


MsgData::MsgData(const MsgData& src) {
	copyFrom(src);
}


MsgData& MsgData::operator=(const MsgData& src) {
	copyFrom(src);
	return *this;
}


void MsgData::copyFrom(const MsgData& src) {
	msg = src.msg;
}


KeyView::KeyView() {
}


KeyView::~KeyView() {
}


HWND KeyView::createView(HWND hwndParent) {
	return Create(hwndParent, 
		rcDefault, 
		NULL,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 
		WS_EX_CLIENTEDGE);
}


int KeyView::onCreate(LPCREATESTRUCT pCreateStruct) {
	_font.CreateFontW(15, 10, 0, 0,
		FW_NORMAL,
		FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"Courier New");
	CDC dc = GetDC();
	CFont oldFont = dc.SelectFont(_font);
	dc.GetTextMetrics(&_tm);
	dc.SelectFont(oldFont);
	ReleaseDC(dc);

	SetMsgHandled(FALSE);
	return 0;
}


void KeyView::onDestroy() {
	_font.DeleteObject();
	SetMsgHandled(FALSE);
}


void KeyView::onPaint(CDCHandle) {

	PAINTSTRUCT ps;
	CDCHandle dcPaint = BeginPaint(&ps);
	drawMessages(dcPaint);
	EndPaint(&ps);
}


void KeyView::onLButtonDown(UINT nFlags, CPoint pt) {
	addMsg(L"WM_LBUTTONDOWN");
}


void KeyView::onLButtonUp(UINT nFlags, CPoint pt) {
	addMsg(L"WM_LBUTTONUP");
}


void KeyView::onMButtonDown(UINT nFlags, CPoint pt) {
	addMsg(L"WM_MBUTTONDOWN");
}


void KeyView::onMButtonUp(UINT nFlags, CPoint pt) {
	addMsg(L"WM_MBUTTONUP");
}


void KeyView::onRButtonDown(UINT nFlags, CPoint pt) {
	addMsg(L"WM_RBUTTONDOWN");
}


void KeyView::onRButtonUp(UINT nFlags, CPoint pt) {
	addMsg(L"WM_RBUTTONUP");
}


void KeyView::drawMessages(CDCHandle dc) {
	CRect rcClient;
	GetClientRect(rcClient);
	int nCharWidth = _tm.tmMaxCharWidth;
	int nLineHeight = _tm.tmHeight + _tm.tmExternalLeading;
	CBrush brBkgnd = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	CBrush brOld = dc.SelectBrush(brBkgnd);
	CFont oldFont = dc.SelectFont(_font);

	dc.SetBkMode(TRANSPARENT);
	dc.FillRect(rcClient, brBkgnd);
	int y = MARGIN;
	dc.TextOut(MARGIN + COL_OFFSET_MSG * nCharWidth, y, L"Message");
	y += nLineHeight;

	dc.TextOut(MARGIN + COL_OFFSET_MSG * nCharWidth, y, L"---------------------------------------------------------------------");
	y += nLineHeight;
	
	for (int i = 0; i < _messages.size(); i++) {
		MsgData& msgData = _messages[i];
		dc.TextOutW(MARGIN + COL_OFFSET_MSG * nCharWidth, y, msgData.msg);
		y += nLineHeight;
	}

	dc.SelectBrush(brOld);
	dc.SelectFont(oldFont);
}


void KeyView::drawMessages() {
	CDCHandle dc = GetDC();
	drawMessages(dc);
	ReleaseDC(dc);
}


void KeyView::addMsg(PCWSTR msg) {
	MsgData msgData;
	msgData.msg = msg;
	if (_messages.size() >= MSG_LIMIT) {
		// TODO: pop front _messages.pop_front();
	}
	_messages.push_back(msgData);
	drawMessages();
}
