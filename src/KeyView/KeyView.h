#pragma once


#include "MsgRecord.h"
#include "KeyString.h"
#include "MouseFigure.h"
#include "KeyboardFigure.h"


class KeyView : public CWindowImpl<KeyView>
{
public:
	KeyView();
	~KeyView();

	HWND createView(HWND hwndParent);

	DECLARE_WND_CLASS(L"KeyView_KeyView")

	BEGIN_MSG_MAP_EX(KeyView)
		MSG_WM_CREATE(onCreate)
		MSG_WM_DESTROY(onDestroy)
		MSG_WM_PAINT(onPaint)
		MSG_WM_LBUTTONDOWN(onLButtonDown)
		MSG_WM_LBUTTONUP(onLButtonUp)
		MSG_WM_MBUTTONDOWN(onMButtonDown)
		MSG_WM_MBUTTONUP(onMButtonUp)
		MSG_WM_RBUTTONDOWN(onRButtonDown)
		MSG_WM_RBUTTONUP(onRButtonUp)
		MSG_WM_KEYDOWN(onKeyDown)
		MSG_WM_KEYUP(onKeyUp)
		MSG_WM_CHAR(onChar)
	END_MSG_MAP()

private:

	CFont			_font;
	TEXTMETRIC		_tm;
	MsgRecordVector _messages;
	KeyString		_keyString;
	MouseFigure		_mouseFigure;
	KeyboardFigure	_keyboardFigure;

	int  onCreate(LPCREATESTRUCT pCreateStruct);
	void onPaint(CDCHandle dc);
	void onDestroy();
	void onLButtonDown(UINT nFlags, CPoint pt);
	void onLButtonUp(UINT nFlags, CPoint pt);
	void onMButtonDown(UINT nFlags, CPoint pt);
	void onMButtonUp(UINT nFlags, CPoint pt);
	void onRButtonDown(UINT nFlags, CPoint pt);
	void onRButtonUp(UINT nFlags, CPoint pt);
	void onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void onKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	void onChar(TCHAR chChar, UINT nRepCnt, UINT nFlags);

	void refreshView(CDCHandle dc);
	void refreshView();
	void recordMsg(PCWSTR msg);
	void recordMouseMsg(PCWSTR msg, UINT nFlags, CPoint pt);
	void recordKeyMsg(PCWSTR msg, UINT nChar, UINT nRepCnt, UINT nFlags, bool isChar);
	void calcPos(CRect& rcClient, CRect& rcMouse, CRect& rcKeyboard, CRect& rcText);
};

