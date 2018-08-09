#include "stdafx.h"
#include "MouseFigure.h"


#define MARGIN 4
#define BTN_WIDTH 40
#define BTN_HEIGHT 40
#define BODY_HEIGHT 80


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
	
	drawButton(dc, rcLeft, _leftDown);
	drawButton(dc, rcMid, _middleDown);
	drawButton(dc, rcRight, _rightDown);
	drawButton(dc, rcBody, false);
}


void MouseFigure::drawButton(CDCHandle dc, const CRect& rc, bool down) {
	CPoint radius(8, 8);
	CPen pen = (HPEN)GetStockObject(BLACK_PEN);
	CPen oldPen = dc.SelectPen(pen);
	CBrush brush = down ? (HBRUSH)GetStockObject(WHITE_BRUSH) :
		(HBRUSH) GetStockObject(LTGRAY_BRUSH);
	CBrush oldBrush = dc.SelectBrush(brush);

	// dc.FillRect(rc, brush);
	dc.RoundRect(rc, radius);

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
