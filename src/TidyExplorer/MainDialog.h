#pragma once


#include "resource.h"


class MainDialog {
public:
    enum { IDD = IDD_MAIN };

    MainDialog(HWND hwnd);

    static void ShowModal();

private:
    HWND   _hwnd;

    BOOL    OnInitDialog(WPARAM, LPARAM);
    void    OnRefresh();
    void    OnApply();
    void    OnSelectAll();
    void    OnSelectNone();
    void    OnClose();

    void    RefreshStates();

    static INT_PTR WINAPI DialogProc(HWND, UINT, WPARAM, LPARAM);
};
