#include "stdafx.h"
#include "KeyString.h"


KeyString::KeyString() {
	define(VK_LBUTTON, L"VK_LBUTTON");
	define(VK_RBUTTON, L"VK_RBUTTON");
	define(VK_CANCEL, L"VK_CANCEL");
	define(VK_MBUTTON, L"VK_MBUTTON");
	define(VK_XBUTTON1, L"VK_XBUTTON1");
	define(VK_XBUTTON2, L"VK_XBUTTON2");
	define(VK_BACK, L"VK_BACK");
	define(VK_TAB, L"VK_TAB");
	define(VK_CLEAR, L"VK_CLEAR");
	define(VK_RETURN, L"VK_RETURN");
	define(VK_SHIFT, L"VK_SHIFT");
	define(VK_CONTROL, L"VK_CONTROL");
	define(VK_MENU, L"VK_MENU");
	define(VK_PAUSE, L"VK_PAUSE");
	define(VK_CAPITAL, L"VK_CAPITAL");
	define(VK_KANA, L"VK_KANA");
	define(VK_HANGEUL, L"VK_HANGEUL");
	define(VK_HANGUL, L"VK_HANGUL");
	define(VK_JUNJA, L"VK_JUNJA");
	define(VK_FINAL, L"VK_FINAL");
	define(VK_HANJA, L"VK_HANJA");
	define(VK_KANJI, L"VK_KANJI");
	define(VK_ESCAPE, L"VK_ESCAPE");
	define(VK_CONVERT, L"VK_CONVERT");
	define(VK_NONCONVERT, L"VK_NONCONVERT");
	define(VK_ACCEPT, L"VK_ACCEPT");
	define(VK_MODECHANGE, L"VK_MODECHANGE");
	define(VK_SPACE, L"VK_SPACE");
	define(VK_PRIOR, L"VK_PRIOR");
	define(VK_NEXT, L"VK_NEXT");
	define(VK_END, L"VK_END");
	define(VK_HOME, L"VK_HOME");
	define(VK_LEFT, L"VK_LEFT");
	define(VK_UP, L"VK_UP");
	define(VK_RIGHT, L"VK_RIGHT");
	define(VK_DOWN, L"VK_DOWN");
	define(VK_SELECT, L"VK_SELECT");
	define(VK_PRINT, L"VK_PRINT");
	define(VK_EXECUTE, L"VK_EXECUTE");
	define(VK_SNAPSHOT, L"VK_SNAPSHOT");
	define(VK_INSERT, L"VK_INSERT");
	define(VK_DELETE, L"VK_DELETE");
	define(VK_HELP, L"VK_HELP");
	define(VK_LWIN, L"VK_LWIN");
	define(VK_RWIN, L"VK_RWIN");
	define(VK_APPS, L"VK_APPS");
	define(VK_SLEEP, L"VK_SLEEP");
	define(VK_NUMPAD0, L"VK_NUMPAD0");
	define(VK_NUMPAD1, L"VK_NUMPAD1");
	define(VK_NUMPAD2, L"VK_NUMPAD2");
	define(VK_NUMPAD3, L"VK_NUMPAD3");
	define(VK_NUMPAD4, L"VK_NUMPAD4");
	define(VK_NUMPAD5, L"VK_NUMPAD5");
	define(VK_NUMPAD6, L"VK_NUMPAD6");
	define(VK_NUMPAD7, L"VK_NUMPAD7");
	define(VK_NUMPAD8, L"VK_NUMPAD8");
	define(VK_NUMPAD9, L"VK_NUMPAD9");
	define(VK_MULTIPLY, L"VK_MULTIPLY");
	define(VK_ADD, L"VK_ADD");
	define(VK_SEPARATOR, L"VK_SEPARATOR");
	define(VK_SUBTRACT, L"VK_SUBTRACT");
	define(VK_DECIMAL, L"VK_DECIMAL");
	define(VK_DIVIDE, L"VK_DIVIDE");
	define(VK_F1, L"VK_F1");
	define(VK_F2, L"VK_F2");
	define(VK_F3, L"VK_F3");
	define(VK_F4, L"VK_F4");
	define(VK_F5, L"VK_F5");
	define(VK_F6, L"VK_F6");
	define(VK_F7, L"VK_F7");
	define(VK_F8, L"VK_F8");
	define(VK_F9, L"VK_F9");
	define(VK_F10, L"VK_F10");
	define(VK_F11, L"VK_F11");
	define(VK_F12, L"VK_F12");
	define(VK_F13, L"VK_F13");
	define(VK_F14, L"VK_F14");
	define(VK_F15, L"VK_F15");
	define(VK_F16, L"VK_F16");
	define(VK_F17, L"VK_F17");
	define(VK_F18, L"VK_F18");
	define(VK_F19, L"VK_F19");
	define(VK_F20, L"VK_F20");
	define(VK_F21, L"VK_F21");
	define(VK_F22, L"VK_F22");
	define(VK_F23, L"VK_F23");
	define(VK_F24, L"VK_F24");
	define(VK_NUMLOCK, L"VK_NUMLOCK");
	define(VK_SCROLL, L"VK_SCROLL");
	define(VK_OEM_NEC_EQUAL, L"VK_OEM_NEC_EQUAL");
	define(VK_OEM_FJ_JISHO, L"VK_OEM_FJ_JISHO");
	define(VK_OEM_FJ_MASSHOU, L"VK_OEM_FJ_MASSHOU");
	define(VK_OEM_FJ_TOUROKU, L"VK_OEM_FJ_TOUROKU");
	define(VK_OEM_FJ_LOYA, L"VK_OEM_FJ_LOYA");
	define(VK_OEM_FJ_ROYA, L"VK_OEM_FJ_ROYA");
	define(VK_LSHIFT, L"VK_LSHIFT");
	define(VK_RSHIFT, L"VK_RSHIFT");
	define(VK_LCONTROL, L"VK_LCONTROL");
	define(VK_RCONTROL, L"VK_RCONTROL");
	define(VK_LMENU, L"VK_LMENU");
	define(VK_RMENU, L"VK_RMENU");
	define(VK_BROWSER_BACK, L"VK_BROWSER_BACK");
	define(VK_BROWSER_FORWARD, L"VK_BROWSER_FORWARD");
	define(VK_BROWSER_REFRESH, L"VK_BROWSER_REFRESH");
	define(VK_BROWSER_STOP, L"VK_BROWSER_STOP");
	define(VK_BROWSER_SEARCH, L"VK_BROWSER_SEARCH");
	define(VK_BROWSER_FAVORITES, L"VK_BROWSER_FAVORITES");
	define(VK_BROWSER_HOME, L"VK_BROWSER_HOME");
	define(VK_VOLUME_MUTE, L"VK_VOLUME_MUTE");
	define(VK_VOLUME_DOWN, L"VK_VOLUME_DOWN");
	define(VK_VOLUME_UP, L"VK_VOLUME_UP");
	define(VK_MEDIA_NEXT_TRACK, L"VK_MEDIA_NEXT_TRACK");
	define(VK_MEDIA_PREV_TRACK, L"VK_MEDIA_PREV_TRACK");
	define(VK_MEDIA_STOP, L"VK_MEDIA_STOP");
	define(VK_MEDIA_PLAY_PAUSE, L"VK_MEDIA_PLAY_PAUSE");
	define(VK_LAUNCH_MAIL, L"VK_LAUNCH_MAIL");
	define(VK_LAUNCH_MEDIA_SELECT, L"VK_LAUNCH_MEDIA_SELECT");
	define(VK_LAUNCH_APP1, L"VK_LAUNCH_APP1");
	define(VK_LAUNCH_APP2, L"VK_LAUNCH_APP2");
	define(VK_OEM_1, L"VK_OEM_1");
	define(VK_OEM_PLUS, L"VK_OEM_PLUS");
	define(VK_OEM_COMMA, L"VK_OEM_COMMA");
	define(VK_OEM_MINUS, L"VK_OEM_MINUS");
	define(VK_OEM_PERIOD, L"VK_OEM_PERIOD");
	define(VK_OEM_2, L"VK_OEM_2");
	define(VK_OEM_3, L"VK_OEM_3");
	define(VK_OEM_4, L"VK_OEM_4");
	define(VK_OEM_5, L"VK_OEM_5");
	define(VK_OEM_6, L"VK_OEM_6");
	define(VK_OEM_7, L"VK_OEM_7");
	define(VK_OEM_8, L"VK_OEM_8");
	define(VK_OEM_AX, L"VK_OEM_AX");
	define(VK_OEM_102, L"VK_OEM_102");
	define(VK_ICO_HELP, L"VK_ICO_HELP");
	define(VK_ICO_00, L"VK_ICO_00");
	define(VK_PROCESSKEY, L"VK_PROCESSKEY");
	define(VK_ICO_CLEAR, L"VK_ICO_CLEAR");
	define(VK_PACKET, L"VK_PACKET");
	define(VK_OEM_RESET, L"VK_OEM_RESET");
	define(VK_OEM_JUMP, L"VK_OEM_JUMP");
	define(VK_OEM_PA1, L"VK_OEM_PA1");
	define(VK_OEM_PA2, L"VK_OEM_PA2");
	define(VK_OEM_PA3, L"VK_OEM_PA3");
	define(VK_OEM_WSCTRL, L"VK_OEM_WSCTRL");
	define(VK_OEM_CUSEL, L"VK_OEM_CUSEL");
	define(VK_OEM_ATTN, L"VK_OEM_ATTN");
	define(VK_OEM_FINISH, L"VK_OEM_FINISH");
	define(VK_OEM_COPY, L"VK_OEM_COPY");
	define(VK_OEM_AUTO, L"VK_OEM_AUTO");
	define(VK_OEM_ENLW, L"VK_OEM_ENLW");
	define(VK_OEM_BACKTAB, L"VK_OEM_BACKTAB");
	define(VK_ATTN, L"VK_ATTN");
	define(VK_CRSEL, L"VK_CRSEL");
	define(VK_EXSEL, L"VK_EXSEL");
	define(VK_EREOF, L"VK_EREOF");
	define(VK_EREOF, L"VK_EREOF");
	define(VK_ZOOM, L"VK_ZOOM");
	define(VK_NONAME, L"VK_NONAME");
	define(VK_PA1, L"VK_PA1");
	define(VK_OEM_CLEAR, L"VK_OEM_CLEAR");
}


KeyString::~KeyString() {
	_keyMap.clear();
}


void KeyString::define(UINT nChar, PCWSTR name) {
	_keyMap[nChar] = name;
}


CString KeyString::toString(UINT nChar) {
	CString result;
	if ((nChar >= 'A' && nChar <= 'Z') ||
		(nChar >= '0' && nChar <= '9')) {
		result.Format(L"%c", nChar);
		return result;
	}

	auto it = _keyMap.find(nChar);
	if (it != _keyMap.end()) {
		return it->second;
	}

	result.Format(L"0x%02X", nChar);
	return result;
}