#include "stdafx.h"
#include "MainWindow.h"


MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}


int MainWindow::onCreate(LPCREATESTRUCT pCreateStruct) {
	SetMsgHandled(FALSE);
	return 0;
}


void MainWindow::onDestroy() {
	PostQuitMessage(0);
	SetMsgHandled(FALSE);
}
