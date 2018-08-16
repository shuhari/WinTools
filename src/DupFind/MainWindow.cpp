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

	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != nullptr);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddToolBar(m_hWndToolBar);
	UIAddStatusBar(m_hWndStatusBar);
	UISetCheck(ID_VIEW_TOOLBAR, true);
	UISetCheck(ID_VIEW_STATUS_BAR, true);

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