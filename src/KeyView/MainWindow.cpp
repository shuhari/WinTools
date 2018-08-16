#include "stdafx.h"
#include "MainWindow.h"
#include "AboutDialog.h"
#include "resource.h"


MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}


BOOL MainWindow::PreTranslateMessage(MSG* pMsg) {
	return FALSE;
}


BOOL MainWindow::OnIdle() {
	BOOL capLock = GetKeyState(VK_CAPITAL) & 0x1;
	BOOL numLock = GetKeyState(VK_NUMLOCK) & 0x1;
	BOOL scrLock = GetKeyState(VK_SCROLL) & 0x1;
	UISetText(1, capLock ? L"CAPS" : L"");
	UISetText(2, numLock ? L"NUMLOCK" : L"");
	UISetText(3, scrLock ? L"SCRLOCK" : L"");

	UIUpdateToolBar();
	UIUpdateStatusBar();
	return FALSE;
}


int MainWindow::onCreate(LPCREATESTRUCT pCreateStruct) {

	CreateSimpleToolBar(0, ATL_SIMPLE_TOOLBAR_STYLE | TBSTYLE_FLAT | TBSTYLE_LIST);

	m_hWndStatusBar = _statusBar.Create(*this);
	int panes[] = {
		ID_DEFAULT_PANE,
		ID_PANE_CAPS,
		ID_PANE_NUMLOCK,
		ID_PANE_SCROLLLOCK,
	};
	_statusBar.SetPanes(panes, _countof(panes));

	m_hWndClient = _view.createView(m_hWnd);
	_view.SetFocus();

	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != nullptr);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddToolBar(m_hWndToolBar);
	UIAddStatusBar(m_hWndStatusBar);
	UISetCheck(ID_VIEW_TOOLBAR, true);
	UISetCheck(ID_VIEW_STATUS_BAR, true);
	UISetText(1, L"");
	UISetText(2, L"");
	UISetText(3, L"");

	SetMsgHandled(FALSE);
	return 0;
}


void MainWindow::onDestroy() {
	PostQuitMessage(0);
	SetMsgHandled(FALSE);
}


void MainWindow::onFileClear(UINT uNotify, int nID, CWindow wnd) {
	_view.clear();
}


void MainWindow::onFileExit(UINT uNotify, int nID, CWindow wnd) {
	PostMessage(WM_CLOSE);
}


void MainWindow::onViewToolbar(UINT uNotify, int nID, CWindow wnd) {
	CWindow toolbar = m_hWndToolBar;
	if (toolbar.IsWindow()) {
		BOOL visible = !toolbar.IsWindowVisible();
		toolbar.ShowWindow(visible ? SW_SHOWNOACTIVATE : SW_HIDE);
		UISetCheck(ID_VIEW_TOOLBAR, visible);
		UpdateLayout();
	}
}


void MainWindow::onViewStatusBar(UINT uNotify, int nID, CWindow wnd) {
	CWindow statusBar = m_hWndStatusBar;
	if (statusBar.IsWindow()) {
		BOOL visible = !statusBar.IsWindowVisible();
		statusBar.ShowWindow(visible ? SW_SHOWNOACTIVATE : SW_HIDE);
		UISetCheck(ID_VIEW_STATUS_BAR, visible);
		UpdateLayout();
	}
}


void MainWindow::onHelpAbout(UINT uNotify, int nID, CWindow wnd) {
	AboutDialog dlg;
	dlg.DoModal(m_hWnd);
}

