#include "stdafx.h"
#include "MainWindow.h"
#include "AboutDialog.h"


MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}


int MainWindow::onCreate(LPCREATESTRUCT pCreateStruct) {
	m_hWndClient = _view.createView(m_hWnd);
	_view.SetFocus();

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

