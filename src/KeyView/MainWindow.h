#pragma once


#include "resource.h"
#include "KeyView.h"


class MainWindow : public CFrameWindowImpl<MainWindow, CWindow, CFrameWinTraits>
{
public:
	MainWindow();
	~MainWindow();

	DECLARE_FRAME_WND_CLASS(_T("KeyView_MainWindow"), IDR_MAINFRAME)

	BEGIN_MSG_MAP_EX(MainWindow)
		MSG_WM_CREATE(onCreate)
		MSG_WM_DESTROY(onDestroy)

		COMMAND_ID_HANDLER_EX(ID_FILE_CLEAR, onFileClear)
		COMMAND_ID_HANDLER_EX(ID_FILE_EXIT, onFileExit)
		COMMAND_ID_HANDLER_EX(ID_HELP_ABOUT, onHelpAbout)

		CHAIN_MSG_MAP(CFrameWindowImpl<MainWindow>)
	END_MSG_MAP()

private:
	KeyView			_view;

	int onCreate(LPCREATESTRUCT pCreateStruct);
	void onDestroy();

	void onFileClear(UINT, int, CWindow);
	void onFileExit(UINT, int, CWindow);
	void onHelpAbout(UINT, int, CWindow);
};

