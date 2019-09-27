#include "stdafx.h"
#include "Utils.h"


void CenterOnScreen(HWND hwnd) {
    RECT rc;
    GetWindowRect(hwnd, &rc);
    int width = rc.right - rc.left,
        height = rc.bottom - rc.top;
    int cxScreen = GetSystemMetrics(SM_CXSCREEN),
        cyScreen = GetSystemMetrics(SM_CYSCREEN);
    int x = (cxScreen - width) / 2;
    int y = (cyScreen - height) / 2;
    SetWindowPos(hwnd, HWND_NOTOPMOST, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

}