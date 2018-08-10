#include "stdafx.h"
#include "KeyboardFigure.h"
#include "Public.h"


KeyButton::KeyButton() {

}


KeyButton::KeyButton(const KeyButton& src) {
	copyFrom(src);
}


KeyButton& KeyButton::operator=(const KeyButton& src) {
	copyFrom(src);
	return *this;
}


void KeyButton::copyFrom(const KeyButton& src) {
	pos = src.pos;
	vk = src.vk;
	down = src.down;
	text = src.text;
}


KeyboardFigure::KeyboardFigure() {
	define(VK_ESCAPE, L"Esc", 10, 10, 63, 63);
	define(VK_F1, L"F1", 117, 10, 171, 63);
	define(VK_F2, L"F2", 172, 10, 226, 63);
	define(VK_F3, L"F3", 227, 10, 280, 63);
	define(VK_F4, L"F4", 281, 10, 332, 63);
	define(VK_F5, L"F5", 362, 10, 415, 63);
	define(VK_F6, L"F6", 416, 10, 469, 63);
	define(VK_F7, L"F7", 470, 10, 522, 63);
	define(VK_F8, L"F8", 523, 10, 576, 63);
	define(VK_F9, L"F9", 603, 10, 658, 63);
	define(VK_F10, L"F10", 659, 10, 712, 63);
	define(VK_F11, L"F11", 713, 10, 766, 63);
	define(VK_F12, L"F12", 767, 10, 820, 63);

	define(VK_OEM_3, L"~", 10, 91, 63, 143);
	define('1', L"1", 64, 91, 116, 143);
	define('2', L"2", 117, 91, 171, 143);
	define('3', L"3", 172, 91, 226, 143);
	define('4', L"4", 227, 91, 280, 143);
	define('5', L"5", 281, 91, 332, 143);
	define('6', L"6", 333, 91, 387, 143);
	define('7', L"7", 388, 91, 442, 143);
	define('8', L"8", 443, 91, 495, 143);
	define('9', L"9", 496, 91, 547, 143);
	define('0', L"0", 548, 91, 603, 143);
	define(VK_OEM_MINUS, L"-", 604, 91, 657, 143);
	define(VK_OEM_PLUS, L"+", 658, 91, 712, 143);
	define(VK_BACK, L"Backspace", 713, 91, 820, 143);

	define(VK_TAB, L"Tab", 10, 144, 90, 198);
	define('Q', L"Q", 91, 144, 145, 198);
	define('W', L"W", 146, 144, 199, 198);
	define('E', L"E", 200, 144, 252, 198);
	define('R', L"R", 253, 144, 307, 198);
	define('T', L"T", 308, 144, 360, 198);
	define('Y', L"Y", 361, 144, 415, 198);
	define('U', L"U", 416, 144, 468, 198);
	define('I', L"I", 469, 144, 522, 198);
	define('O', L"O", 523, 144, 576, 198);
	define('P', L"P", 577, 144, 631, 198);
	define(VK_OEM_4, L"[", 632, 144, 684, 198);
	define(VK_OEM_6, L"]", 685, 144, 738, 198);
	define(VK_OEM_5, L"\\", 739, 144, 820, 198);

	define(VK_CAPITAL, L"Caps Lock", 10, 198, 104, 252);
	define('A', L"A", 105, 198, 158, 252);
	define('S', L"S", 159, 198, 211, 252);
	define('D', L"D", 212, 198, 267, 252);
	define('F', L"F", 268, 198, 320, 252);
	define('G', L"G", 321, 198, 371, 252);
	define('H', L"H", 372, 198, 427, 252);
	define('J', L"J", 428, 198, 482, 252);
	define('K', L"K", 483, 198, 536, 252);
	define('L', L"L", 537, 198, 590, 252);
	define(VK_OEM_1, L";", 591, 198, 645, 252);
	define(VK_OEM_7, L"'", 646, 198, 698, 252);
	define(VK_MAIN_RETURN, L"Enter", 699, 198, 820, 252);
	
	define(VK_LSHIFT, L"Shift", 10, 253, 130, 306);
	define('Z', L"Z", 131, 253, 186, 306);
	define('X', L"X", 187, 253, 240, 306);
	define('C', L"C", 241, 253, 293, 306);
	define('V', L"V", 294, 253, 347, 306);
	define('B', L"B", 348, 253, 402, 306);
	define('N', L"N", 403, 253, 456, 306);
	define('M', L"M", 457, 253, 508, 306);
	define(VK_OEM_COMMA, L",", 509, 253, 563, 306);
	define(VK_OEM_PERIOD, L".", 564, 253, 617, 306);
	define(VK_OEM_2, L"/", 618, 253, 672, 306);
	define(VK_RSHIFT, L"Shift", 673, 253, 820, 306);

	define(VK_LCONTROL, L"Ctrl", 10, 307, 77, 360);
	define(VK_LWIN, L"Win", 78, 307, 143, 360);
	define(VK_LMENU, L"Alt", 144, 307, 213, 360);
	define(VK_SPACE, L"", 214, 307, 550, 360);
	define(VK_RMENU, L"Alt", 551, 307, 615, 360);
	define(VK_RWIN, L"Win", 616, 307, 684, 360);
	define(VK_APPS, L"Apps", 685, 307, 751, 360);
	define(VK_RCONTROL, L"Ctrl", 752, 307, 820, 360);

	define(VK_SNAPSHOT, L"PrtSc", 833, 10, 887, 62);
	define(VK_SCROLL, L"Scroll", 888, 10, 942, 62);
	define(VK_PAUSE, L"Pause", 943, 10, 995, 62);

	define(VK_INSERT, L"Insert", 833, 91, 887, 144);
	define(VK_HOME, L"Home", 888, 91, 942, 144);
	define(VK_PRIOR, L"PgUp", 943, 91, 995, 144);

	define(VK_DELETE, L"Delete", 833, 145, 887, 199);
	define(VK_END, L"End", 888, 145, 942, 199);
	define(VK_NEXT, L"PgDn", 943, 145, 995, 199);

	define(VK_UP, L"Up", 888, 254, 942, 307);
	define(VK_LEFT, L"Left", 833, 308, 887, 360);
	define(VK_DOWN, L"Dn", 888, 308, 942, 360);
	define(VK_RIGHT, L"Right", 943, 308, 995, 360);

	define(VK_NUMLOCK, L"NumLock", 1009, 90, 1063, 143);
	define(VK_DIVIDE, L"/", 1064, 90, 1116, 143);
	define(VK_MULTIPLY, L"*", 1117, 90, 1170, 143);
	define(VK_SUBTRACT, L"-", 1171, 90, 1225, 143);
	define(VK_NUMPAD7, L"7", 1009, 144, 1063, 198);
	define(VK_NUMPAD8, L"8", 1064, 144, 1116, 198);
	define(VK_NUMPAD9, L"9", 1117, 144, 1170, 198);
	define(VK_ADD, L"+", 1171, 144, 1225, 252);
	define(VK_NUMPAD4, L"4", 1009, 199, 1063, 252);
	define(VK_NUMPAD5, L"5", 1064, 199, 1116, 252);
	define(VK_NUMPAD6, L"6", 1117, 199, 1170, 252);
	define(VK_NUMPAD1, L"1", 1009, 253, 1063, 307);
	define(VK_NUMPAD2, L"2", 1064, 253, 1116, 307);
	define(VK_NUMPAD3, L"3", 1117, 253, 1170, 307);
	define(VK_NUMPAD0, L"0", 1009, 308, 1116, 360);
	define(VK_DECIMAL, L".", 1117, 308, 1170, 360);
	define(VK_NUMPAD_RETURN, L"Enter", 1171, 253, 1225, 360);
}


KeyboardFigure::~KeyboardFigure() {
	_buttons.clear();
}


CSize KeyboardFigure::size() {
	return CSize(1235, 371);
}


void KeyboardFigure::define(UINT vk, PCWSTR text,
	int left, int top, int right, int bottom) {
	auto current = _buttons.find(vk);
	assert(current == _buttons.end());
		
	KeyButton btn;
	btn.vk = vk;
	btn.down = false;
	btn.text = text;
	btn.pos.SetRect(left, top, right, bottom);
	_buttons[vk] = btn;
}


void KeyboardFigure::draw(CDCHandle dc, CRect& rc) {
	CBrush brush = CreateSolidBrush(RGB(216, 216, 216));
	CBrush oldBrush = dc.SelectBrush(brush);
	CPen oldPen = dc.SelectStockPen(WHITE_PEN);

	dc.RoundRect(rc, CPoint(8, 8));

	dc.SelectBrush(oldBrush);
	dc.SelectPen(oldPen);
	oldBrush.DeleteObject();

	for (auto it = _buttons.begin(); it != _buttons.end(); it++) {
		KeyButton& btn = it->second;
		CRect rcBtn = btn.pos;
		rcBtn.OffsetRect(rc.left, rc.top);
		UINT uState = DFCS_BUTTONPUSH;
		if (btn.down)
			uState |= DFCS_PUSHED;
		dc.DrawFrameControl(rcBtn, DFC_BUTTON, uState);
		CRect rcText = rcBtn;
		rcText.DeflateRect(4, 4);
		dc.DrawText(btn.text, -1, rcText, DT_SINGLELINE | DT_LEFT | DT_TOP);
	}
}


bool KeyboardFigure::isMultiKey(UINT nKey, std::vector<UINT>& keys) {
	if (nKey == VK_CONTROL) {
		keys.push_back(VK_LCONTROL);
		keys.push_back(VK_RCONTROL);
		return true;
	}
	else if (nKey == VK_MENU) {
		keys.push_back(VK_LMENU);
		keys.push_back(VK_RMENU);
		return true;
	}
	else if (nKey == VK_SHIFT) {
		keys.push_back(VK_LSHIFT);
		keys.push_back(VK_RSHIFT);
		return true;
	}
	else if (nKey == VK_RETURN) {
		keys.push_back(VK_MAIN_RETURN);
		keys.push_back(VK_NUMPAD_RETURN);
		return true;
	}
	return false;
}


void KeyboardFigure::setKey(UINT nKey, bool down) {
	std::vector<UINT> vks;
	if (isMultiKey(nKey, vks)) {
		for (UINT vk : vks) {
			setKey(vk, down);
		}
	}
	else {
		auto it = _buttons.find(nKey);
		if (it != _buttons.end()) {
			KeyButton& btn = it->second;
			btn.down = down;
		}
	}
}