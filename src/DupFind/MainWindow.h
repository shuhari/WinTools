#pragma once

#include "resource.h"
#include "SettingsView.h"
#include "ResultView.h"


class MainWindow : public CFrameWindowImpl<MainWindow>,
	public CUpdateUI<MainWindow>,
	public CMessageFilter,
	public CIdleHandler
{
public:
	MainWindow();
	~MainWindow();

	DECLARE_FRAME_WND_CLASS(_T("DupFind_MainWindow"), IDR_MAINFRAME)

	BEGIN_UPDATE_UI_MAP(MainWindow)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_SETTINGS, UPDUI_MENUPOPUP | UPDUI_TOOLBAR)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP_EX(MainWindow)
		MSG_WM_CREATE(onCreate)
		MSG_WM_DESTROY(onDestroy)
		COMMAND_ID_HANDLER_EX(ID_FILE_EXIT, onFileExit)
		COMMAND_ID_HANDLER_EX(ID_VIEW_TOOLBAR, onViewToolbar)
		COMMAND_ID_HANDLER_EX(ID_VIEW_STATUS_BAR, onViewStatusBar)
		COMMAND_ID_HANDLER_EX(ID_VIEW_SETTINGS, onViewSettings)
		COMMAND_ID_HANDLER_EX(ID_PANE_CLOSE, onSettingsClose)
		COMMAND_ID_HANDLER_EX(ID_HELP_ABOUT, onHelpAbout)

		CHAIN_MSG_MAP(CUpdateUI<MainWindow>)
		CHAIN_MSG_MAP(CFrameWindowImpl<MainWindow>)
	END_MSG_MAP()

	BOOL PreTranslateMessage(MSG* pMsg);
	BOOL OnIdle();

private:
	CMultiPaneStatusBarCtrl		_statusBar;
	CSplitterWindow				_splitter;
	CPaneContainer				_settingsPane;
	SettingsView				_settingsView;
	ResultView					_resultView;

	int			onCreate(LPCREATESTRUCT pcs);
	void		onDestroy();

	void		onFileExit(UINT, int, CWindow);
	void		onViewToolbar(UINT, int, CWindow);
	void		onViewStatusBar(UINT, int, CWindow);
	void		onViewSettings(UINT, int, CWindow);
	void		onHelpAbout(UINT, int, CWindow);
	void		onSettingsClose(UINT, int, CWindow);

	void		switchBarVisible(HWND hChild, int nID);
};

