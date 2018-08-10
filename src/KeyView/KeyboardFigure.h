#pragma once


#include <map>
#include <vector>


struct KeyButton {
public:
	CRect pos;
	UINT  vk;
	bool  down;
	CString text;

	KeyButton();
	KeyButton(const KeyButton& src);
	KeyButton& operator=(const KeyButton& src);

private:
	void copyFrom(const KeyButton& src);
};


class KeyboardFigure {
public:
	KeyboardFigure();
	~KeyboardFigure();

	CSize size();
	void draw(CDCHandle dc, CRect& rc);
	void setKey(UINT nKey, bool down);

private:
	std::map<UINT, KeyButton> _buttons;

	void define(UINT vk, PCWSTR text, int left, int top, int right, int bottom);
	bool isMultiKey(UINT nKey, std::vector<UINT>& keys);
};

