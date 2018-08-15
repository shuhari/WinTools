#include "stdafx.h"
#include "MainWindow.h"


CAppModule _Module;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int nCmdShow) {
	
	AtlInitCommonControls(ICC_WIN95_CLASSES);
	HRESULT hr = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hr));

	int nRet = 0;
	{
		CMessageLoop msgLoop;
		_Module.AddMessageLoop(&msgLoop);

		MainWindow mainWin;
		if (!mainWin.CreateEx())
			return -1;
		mainWin.ShowWindow(nCmdShow);
		mainWin.UpdateWindow();

		nRet = msgLoop.Run();
		_Module.RemoveMessageLoop();
	}

	_Module.Term();
	return nRet;
}
