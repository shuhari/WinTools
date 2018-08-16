#include "stdafx.h"
#include "MainWindow.h"
#include "AboutDialog.h"


MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}


BOOL MainWindow::PreTranslateMessage(MSG* pMsg) {
	return FALSE;
}


BOOL MainWindow::OnIdle() {
	UIUpdateToolBar();
	UIUpdateStatusBar();
	return FALSE;
}


int MainWindow::onCreate(LPCREATESTRUCT pcs) {
	CreateSimpleToolBar(0, ATL_SIMPLE_TOOLBAR_STYLE | TBSTYLE_FLAT | TBSTYLE_LIST);

	m_hWndStatusBar = _statusBar.Create(*this);
	int panes[] = {
		ID_DEFAULT_PANE,
	};
	_statusBar.SetPanes(panes, _countof(panes));

	m_hWndClient = _splitter.Create(m_hWnd, rcDefault, NULL, 0, WS_EX_CLIENTEDGE);
	_settingsPane.Create(_splitter, IDS_SETTINGS);
	_settingsView.Create(_settingsPane, rcDefault);
	_settingsPane.SetClient(_settingsView);

	_resultView.Create(m_hWndClient, rcDefault);
	_splitter.SetSplitterPanes(_settingsPane, _resultView, false);

	UpdateLayout();
	_splitter.SetSplitterPos(200);

	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != nullptr);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddToolBar(m_hWndToolBar);
	UIAddStatusBar(m_hWndStatusBar);
	UISetCheck(ID_VIEW_TOOLBAR, true);
	UISetCheck(ID_VIEW_STATUS_BAR, true);
	UISetCheck(ID_VIEW_SETTINGS, true);

	SetMsgHandled(FALSE);
	return 0;
}


void MainWindow::onDestroy() {
	PostQuitMessage(0);
	SetMsgHandled(FALSE);
}


void MainWindow::onFileExit(UINT, int, CWindow) {
	PostMessage(WM_CLOSE);
}


void MainWindow::onViewToolbar(UINT, int, CWindow) {
	switchBarVisible(m_hWndToolBar, ID_VIEW_TOOLBAR);
}


void MainWindow::onViewStatusBar(UINT, int, CWindow) {
	switchBarVisible(m_hWndStatusBar, ID_VIEW_STATUS_BAR);
}


void MainWindow::onViewSettings(UINT, int, CWindow) {
	int mode = _splitter.GetSinglePaneMode();
	if (mode == SPLIT_PANE_NONE) {
		_splitter.SetSinglePaneMode(SPLIT_PANE_RIGHT);
		UISetCheck(ID_VIEW_SETTINGS, false);
	}
	else {
		_splitter.SetSinglePaneMode(SPLIT_PANE_NONE);
		UISetCheck(ID_VIEW_SETTINGS, true);
	}
}


void MainWindow::onSettingsClose(UINT, int, CWindow) {
	_splitter.SetSinglePaneMode(SPLIT_PANE_RIGHT);
	UISetCheck(ID_VIEW_SETTINGS, false);
}


void MainWindow::onHelpAbout(UINT, int, CWindow) {
	AboutDialog dlg;
	dlg.DoModal(m_hWnd);
}


void MainWindow::switchBarVisible(HWND hChild, int nID) {
	CWindow child = hChild;
	if (child.IsWindow()) {
		BOOL visible = !child.IsWindowVisible();
		child.ShowWindow(visible ? SW_SHOWNOACTIVATE : SW_HIDE);
		UISetCheck(nID, visible);
		UpdateLayout();
	}
}