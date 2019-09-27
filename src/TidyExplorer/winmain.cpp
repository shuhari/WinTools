#include "stdafx.h"
#include "MainDialog.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int ncmdShow) {
    MainDialog::ShowModal();
    return 0;
}
