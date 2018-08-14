#include "stdafx.h"
#include "KeyView.h"
#include "EnumString.h"
#include <ctype.h>


#define MARGIN						8
#define DEVICE_MARGIN				20


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
	_focusBrush = CreateSolidBrush(RGB(0xFF, 0x99, 0x33));
	_unFocusBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);

	_font.CreateFontW(15, 10, 0, 0,
		FW_NORMAL,
		FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"FixedSys");
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
	_focusBrush.DeleteObject();
	SetMsgHandled(FALSE);
}


void KeyView::onPaint(CDCHandle) {

	PAINTSTRUCT ps;
	CDCHandle dcPaint = BeginPaint(&ps);
	refreshView(dcPaint);
	EndPaint(&ps);
}


void KeyView::onLButtonDown(UINT nFlags, CPoint pt) {
	recordMouseMsg(L"WM_LBUTTONDOWN", nFlags, pt, VK_LBUTTON, true);
	SetMsgHandled(TRUE);
}


void KeyView::onLButtonUp(UINT nFlags, CPoint pt) {
	recordMouseMsg(L"WM_LBUTTONUP", nFlags, pt, VK_LBUTTON, false);
	SetMsgHandled(TRUE);
}


void KeyView::onMButtonDown(UINT nFlags, CPoint pt) {
	recordMouseMsg(L"WM_MBUTTONDOWN", nFlags, pt, VK_MBUTTON, true);
	SetMsgHandled(TRUE);
}


void KeyView::onMButtonUp(UINT nFlags, CPoint pt) {
	recordMouseMsg(L"WM_MBUTTONUP", nFlags, pt, VK_MBUTTON, false);
	SetMsgHandled(TRUE);
}


void KeyView::onRButtonDown(UINT nFlags, CPoint pt) {
	recordMouseMsg(L"WM_RBUTTONDOWN", nFlags, pt, VK_RBUTTON, true);
	SetMsgHandled(TRUE);
}


void KeyView::onRButtonUp(UINT nFlags, CPoint pt) {
	recordMouseMsg(L"WM_RBUTTONUP", nFlags, pt, VK_RBUTTON, false);
	SetMsgHandled(TRUE);
}


void KeyView::onKeyDown(UINT nChar, UINT nRepCount, UINT nFlags) {
	recordKeyMsg(L"WM_KEYDOWN", nChar, nRepCount, nFlags, false, true);
	SetMsgHandled(TRUE);
}


void KeyView::onKeyUp(UINT nChar, UINT nRepCount, UINT nFlags) {
	recordKeyMsg(L"WM_KEYUP", nChar, nRepCount, nFlags, false, false);
	SetMsgHandled(TRUE);
}


void KeyView::onChar(TCHAR chChar, UINT nRepCount, UINT nFlags) {
	recordKeyMsg(L"WM_CHAR", chChar, nRepCount, nFlags, true, false);
	SetMsgHandled(TRUE);
}


void KeyView::calcPos(CRect& rcClient, CRect& rcMouse, CRect& rcKeyboard, CRect& rcText) {
	GetClientRect(rcClient);

	CRect rcDraw = rcClient;
	rcDraw.DeflateRect(MARGIN, MARGIN);
	CSize mouseSize = _mouseFigure.size();
	CSize keyboardSize = _keyboardFigure.size();
	int deviceMargin = (rcDraw.Width() - mouseSize.cx - keyboardSize.cx - DEVICE_MARGIN) / 2;
	int mouseYMargin = (keyboardSize.cy - mouseSize.cy) / 2;
	
	CPoint ptMouse(rcDraw.left + deviceMargin, rcDraw.top + mouseYMargin);
	rcMouse.SetRect(ptMouse.x, ptMouse.y,
		ptMouse.x + mouseSize.cx, ptMouse.y + mouseSize.cy);
	CPoint ptKeyboard(rcMouse.right + DEVICE_MARGIN, rcDraw.top);
	rcKeyboard.SetRect(ptKeyboard.x, ptKeyboard.y,
		ptKeyboard.x + keyboardSize.cx, ptKeyboard.y + keyboardSize.cy);
	
	int nCharWidth = _tm.tmAveCharWidth;
	int nLineHeight = _tm.tmHeight + _tm.tmExternalLeading;
	int nTextWidth = nCharWidth * MsgRecord::ColumnCount;
	int textMargin = (rcDraw.Width() - nTextWidth) / 2;
	rcText.SetRect(rcDraw.left + textMargin, 
		rcKeyboard.bottom + MARGIN,
		rcDraw.left + textMargin + nTextWidth, 
		rcDraw.bottom);
}


void KeyView::refreshView(CDCHandle dc) {
	
	CRect rcClient, rcMouse, rcKeyboard, rcText;
	calcPos(rcClient, rcMouse, rcKeyboard, rcText);

	preDraw(dc);

	dc.FillRect(rcClient, _focused ? _focusBrush : _unFocusBrush);

	_mouseFigure.draw(dc, rcMouse);
	_keyboardFigure.draw(dc, rcKeyboard);
	drawText(dc, rcText);

	postDraw(dc);
}


void KeyView::preDraw(CDCHandle dc) {
	dc.SaveDC();
	dc.SetBkMode(TRANSPARENT);
	dc.SelectFont(_font);
}


void KeyView::postDraw(CDCHandle dc) {
	dc.RestoreDC(-1);
}


void KeyView::drawText(CDCHandle dc, const CRect& rcText) {
	int nCharWidth = _tm.tmAveCharWidth;
	int nLineHeight = _tm.tmHeight + _tm.tmExternalLeading;
	COLORREF currTextColor = dc.GetTextColor();

	int x = rcText.left, y = rcText.top;
	dc.TextOut(x, y, MsgRecord::headerText());
	y += nLineHeight;
	dc.TextOut(x, y, MsgRecord::separatorText());
	y += nLineHeight;
	for (size_t i = 0; i < _messages.size(); i++) {
		CRect rcLine(x, y, x + nCharWidth * MsgRecord::ColumnCount, y + nLineHeight);
		dc.FillRect(rcLine, _focused ? _focusBrush : _unFocusBrush);
		MsgRecord& record = _messages.at(i);
		if (record.type == MsgRecord::MsgKeyboard)
			dc.SetTextColor(RGB(0, 128, 0));
		else
			dc.SetTextColor(RGB(0, 0, 128));
		dc.TextOut(x, y, record.toString());
		y += nLineHeight;
	}

	dc.SetTextColor(currTextColor);
}


void KeyView::refreshView() {
	CDCHandle dc = GetDC();
	refreshView(dc);
	ReleaseDC(dc);
}


void KeyView::recordMsg(PCWSTR msg) {
	MsgRecord record;
	record.name = msg;
	_messages.append(record);
	refreshView();
}


void KeyView::recordMouseMsg(PCWSTR msg, UINT nFlags, CPoint pt,
	UINT nBtn, bool down) {
	MsgRecord record;
	record.type = MsgRecord::MsgMouse;
	record.name = msg;
	EnumString mk;
	mk.addIf(nFlags, MK_CONTROL, L"Ctrl")
		.addIf(nFlags, MK_SHIFT, L"Shift")
		.addIf(nFlags, MK_XBUTTON1, L"XBTN1")
		.addIf(nFlags, MK_XBUTTON2, L"XBTN2")
		.addIf(nFlags, MK_LBUTTON, L"LMB")
		.addIf(nFlags, MK_MBUTTON, L"MMB")
		.addIf(nFlags, MK_RBUTTON, L"RMB");
	record.flags = mk.toString();
	record.coord.Format(L"%d, %d", pt.x, pt.y);
	_messages.append(record);
	_mouseFigure.setButton(nBtn, down);
	
	CRect rcClient, rcText, rcKeyboard, rcMouse;
	calcPos(rcClient, rcMouse, rcKeyboard, rcText);
	CDCHandle dc = GetDC();
	preDraw(dc);
	drawText(dc, rcText);
	_mouseFigure.setButton(nBtn, down);
	_mouseFigure.drawVButton(dc, rcMouse, nBtn, down);
	postDraw(dc);
	ReleaseDC(dc);

}


bool KeyView::isPrintable(UINT nChar) {
	if (nChar >= '0' && nChar <= '9')
		return true;
	if (nChar >= 'A' && nChar <= 'Z')
		return true;
	if (nChar >= 'a' && nChar <= 'z')
		return true;
	return false;
}


void KeyView::recordKeyMsg(PCWSTR msg, UINT nChar, UINT nRepCnt, 
	UINT nFlags, bool isChar, bool down) {
	MsgRecord record;
	record.type = MsgRecord::MsgKeyboard;
	record.name = msg;
	record.flags = L"";
	if (isChar) {
		if (isPrintable(nChar))
			record.ch.Format(L"%c (0x%02X)", nChar, nChar);
		else
			record.ch.Format(L"0x%02X", nChar);
	}
	else {
		record.ch = _keyString.toString(nChar);
	}
	record.scan.Format(L"0x%02X", (nFlags & 0xFF));
	_messages.append(record);

	CRect rcClient, rcText, rcKeyboard, rcMouse;
	calcPos(rcClient, rcMouse, rcKeyboard, rcText);
	CDCHandle dc = GetDC();
	preDraw(dc);
	drawText(dc, rcText);
	if (!isChar) {
		_keyboardFigure.setKey(nChar, down);
		_keyboardFigure.drawKey(dc, rcKeyboard, nChar, down);
	}
	postDraw(dc);
	ReleaseDC(dc);
}


void KeyView::onSetFocus(CWindow wndOld) {
	_focused = true;
	refreshView();
}


void KeyView::onKillFocus(CWindow wndFocus) {
	_focused = false;
	refreshView();
}


void KeyView::clear() {
	_messages.clear();
	refreshView();
}

