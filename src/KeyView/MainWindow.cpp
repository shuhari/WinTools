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
	return FALSE;
}


int MainWindow::onCreate(LPCREATESTRUCT pCreateStruct) {
	m_hWndClient = _view.createView(m_hWnd);
	_view.SetFocus();

	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != nullptr);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

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


void MainWindow::onHelpAbout(UINT uNotify, int nID, CWindow wnd) {
	AboutDialog dlg;
	dlg.DoModal(m_hWnd);
}

