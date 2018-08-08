#pragma once


#include <vector>

using std::vector;


struct MsgData {
public:
	CString		msg;

	MsgData();
	MsgData(const MsgData&);
	MsgData& operator=(const MsgData&);

private:
	void	copyFrom(const MsgData& src);
};


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
	END_MSG_MAP()

private:

	CFont			_font;
	TEXTMETRIC		_tm;
	vector<MsgData> _messages;

	int  onCreate(LPCREATESTRUCT pCreateStruct);
	void onPaint(CDCHandle dc);
	void onDestroy();
	void onLButtonDown(UINT nFlags, CPoint pt);
	void onLButtonUp(UINT nFlags, CPoint pt);
	void onMButtonDown(UINT nFlags, CPoint pt);
	void onMButtonUp(UINT nFlags, CPoint pt);
	void onRButtonDown(UINT nFlags, CPoint pt);
	void onRButtonUp(UINT nFlags, CPoint pt);

	void drawMessages(CDCHandle dc);
	void drawMessages();
	void addMsg(PCWSTR msg);
};

