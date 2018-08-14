#include "stdafx.h"
#include "MouseFigure.h"


#define MARGIN 4
#define BTN_WIDTH 40
#define BTN_HEIGHT 40
#define BODY_HEIGHT 160


MouseFigure::MouseFigure() {
	_leftDown = false;
	_middleDown = false;
	_rightDown = false;
}


MouseFigure::~MouseFigure() {
}


CSize MouseFigure::size() {
	int width = BTN_WIDTH * 3 + MARGIN * 2;
	int height = BTN_HEIGHT + MARGIN + BODY_HEIGHT;
	return CSize(width, height);
}


void MouseFigure::calcPos(const CRect& rc, CRect& rcLeft,
	CRect& rcMid, CRect& rcRight, CRect& rcBody) {
	rcLeft.SetRect(rc.left, rc.top,
		rc.left + BTN_WIDTH,
		rc.top + BTN_HEIGHT);
	rcMid = rcLeft;
	rcMid.OffsetRect(BTN_WIDTH + MARGIN, 0);
	rcRight = rcMid;
	rcRight.OffsetRect(BTN_WIDTH + MARGIN, 0);
	rcBody.SetRect(rc.left, 
		rcLeft.bottom + MARGIN,
		rc.right,
		rc.bottom);
}


void MouseFigure::draw(CDCHandle dc, const CRect& rc) {
	CRect rcLeft, rcMid, rcRight, rcBody;
	calcPos(rc, rcLeft, rcMid, rcRight, rcBody);
	CPoint radius(4, 4);
	
	drawButton(dc, rcLeft, _leftDown, L"L");
	drawButton(dc, rcMid, _middleDown, L"M");
	drawButton(dc, rcRight, _rightDown, L"R");
	drawButton(dc, rcBody, false);
}


void MouseFigure::drawVButton(CDCHandle dc, CRect& rc, UINT nBtn, bool down) {
	CRect rcLeft, rcMid, rcRight, rcBody;
	calcPos(rc, rcLeft, rcMid, rcRight, rcBody);
	switch (nBtn) {
	case VK_LBUTTON:
		drawButton(dc, rcLeft, _leftDown, L"L");
		break;
	case VK_MBUTTON:
		drawButton(dc, rcMid, _middleDown, L"M");
		break;
	case VK_RBUTTON:
		drawButton(dc, rcRight, _rightDown, L"R");
		break;
	}
}


void MouseFigure::drawButton(CDCHandle dc, CRect& rc, bool down,
	PCWSTR szText/*=nullptr*/) {
	CPoint radius(8, 8);
	CPen pen = (HPEN)GetStockObject(BLACK_PEN);
	CPen oldPen = dc.SelectPen(pen);
	CBrush brush = down ? (HBRUSH)GetStockObject(WHITE_BRUSH) :
		(HBRUSH) GetStockObject(LTGRAY_BRUSH);
	CBrush oldBrush = dc.SelectBrush(brush);

	dc.RoundRect(rc, radius);

	if (szText) {
		dc.DrawText(szText, -1, rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	dc.SelectPen(oldPen);
	dc.SelectBrush(oldBrush);
}


void MouseFigure::setButton(UINT nBtn, bool down) {
	switch (nBtn) {
	case VK_LBUTTON:
		_leftDown = down;
		break;

	case VK_MBUTTON:
		_middleDown = down;
		break;

	case VK_RBUTTON:
		_rightDown = down;
		break;
	}
}
