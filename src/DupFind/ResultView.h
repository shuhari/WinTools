#pragma once

typedef CWinTraits<WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | 
	LVS_REPORT | LVS_NOSORTHEADER | LVS_SHOWSELALWAYS | LVS_SHAREIMAGELISTS> ResultViewTraits;


class ResultView : public CWindowImpl<ResultView, CListViewCtrl, ResultViewTraits>,
	public CCustomDraw<ResultView>
{
public:
	ResultView();
	~ResultView();

	DECLARE_WND_SUPERCLASS(NULL, WC_LISTVIEW)

	BEGIN_MSG_MAP_EX(ResultView)
		MSG_WM_CREATE(onCreate)

		CHAIN_MSG_MAP_ALT(CCustomDraw<ResultView>, 1)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

private:
	int		onCreate(LPCREATESTRUCT pcs);

	void	insertColumn(int iSubItem, int fmt, int width, PCWSTR text);
};

