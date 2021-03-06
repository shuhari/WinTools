#pragma once

class MouseFigure
{
public:
	MouseFigure();
	~MouseFigure();

	CSize size();
	void draw(CDCHandle dc, const CRect& rc);

	void setButton(UINT nBtn, bool down);
	void drawVButton(CDCHandle dc, CRect& rc, UINT nBtn, bool down);

private:
	bool _leftDown;
	bool _middleDown;
	bool _rightDown;

	void calcPos(const CRect& rc, CRect& rcLeft,
		CRect& rcMid, CRect& rcRight, CRect& rcBody);
	void drawButton(CDCHandle dc, CRect& rc, bool down,
		PCWSTR szText = nullptr);
};

