#include "stdafx.h"
#include "MainWindow.h"


CAppModule _Module;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR szCmdLine, int nCmdShow) {

	AtlInitCommonControls(ICC_WIN95_CLASSES);
	HRESULT hr = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hr));

	int nRet = 0;
	{
		CMessageLoop msgLoop;
		_Module.AddMessageLoop(&msgLoop);

		MainWindow mainWin;
		if (mainWin.CreateEx()) {
			mainWin.ShowWindow(nCmdShow);
			mainWin.UpdateWindow();
			nRet = msgLoop.Run();
		}
		else {
			// create main window failed
			AtlMessageBox(HWND_DESKTOP, 
				L"Create main window failed", 
				L"DupFind", 
				MB_OK | MB_ICONEXCLAMATION);
		}

		_Module.RemoveMessageLoop();
	}

	_Module.Term();
	return nRet;
}
