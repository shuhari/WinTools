#include "stdafx.h"
#include "MainDialog.h"
#include "resource.h"
#include "TidyItem.h"
#include "Utils.h"


TidyItem tidyItems[] = {
    { IDC_CHECK_PICTURES,  L"{24AD3AD4-A569-4530-98E1-AB02F9417AA8}", L"{0DDD015D-B06C-45D5-8C4C-F59713854639}" },
    { IDC_CHECK_VIDEOS,    L"{F86FA3AB-70D2-4FC7-9C99-FCBF05467F3A}", L"{35286A68-3C57-41A1-BBB1-0EAE73D76C95}" },
    { IDC_CHECK_DOWNLOADS, L"{088E3905-0323-4B02-9826-5D99428E115F}", L"{7D83EE9B-2244-4E70-B1F5-5393042AF1E4}" },
    { IDC_CHECK_MUSIC,     L"{3DFDF296-DBEC-4FB4-81D1-6A3438BCF4DE}", L"{A0C69A99-21C8-4671-8703-7934162FCF1D}" },
    { IDC_CHECK_DESKTOP,   L"{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}", L"{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}" },
    { IDC_CHECK_DOCUMENTS, L"{D3162B92-9365-467A-956B-92703ACA08AF}", L"{F42EE2D3-909F-4907-8871-4C22FC0BF756}" },
    { IDC_CHECK_3DOBJECTS, L"{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}", NULL }
};


MainDialog::MainDialog(HWND hwnd)
    : _hwnd(hwnd) {
}


BOOL MainDialog::OnInitDialog(WPARAM wParam, LPARAM lParam) {
    HMODULE hInstance = GetModuleHandle(NULL);
    HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAIN));
    SendMessage(_hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    SendMessage(_hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    CenterOnScreen(_hwnd);
    RefreshStates();
    return TRUE;
}


void MainDialog::OnRefresh() {
    RefreshStates();
}


void MainDialog::OnApply() {
    SetDlgItemText(_hwnd, IDC_STATUS, L"");
    for (auto& item : tidyItems) {
        UINT uState = IsDlgButtonChecked(_hwnd, item.uID);
        bool bOn = (uState == BST_CHECKED);
        item.SetOn(bOn);
    }
    SetDlgItemText(_hwnd, IDC_STATUS, L"Apply finished. Please refresh explorer to take effect.");
}


void MainDialog::OnSelectAll() {
    for (auto& item : tidyItems) {
        CheckDlgButton(_hwnd, item.uID, BST_CHECKED);
    }
}


void MainDialog::OnSelectNone() {
    for (auto& item : tidyItems) {
        CheckDlgButton(_hwnd, item.uID, BST_UNCHECKED);
    }
}


void MainDialog::OnClose() {
    EndDialog(_hwnd, IDCANCEL);
}


void MainDialog::ShowModal() {
    DialogBox(NULL, MAKEINTRESOURCE(IDD), HWND_DESKTOP, DialogProc);
}


void MainDialog::RefreshStates() {
    SetDlgItemText(_hwnd, IDC_STATUS, L"");
    for (auto& item : tidyItems) {
        bool isOn = item.IsOn();
        CheckDlgButton(_hwnd, item.uID, isOn ? BST_CHECKED : BST_UNCHECKED);
    }
}


INT_PTR WINAPI MainDialog::DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    MainDialog dlg(hwnd);
    switch (uMsg) {
    case WM_INITDIALOG:
        return dlg.OnInitDialog(wParam, lParam);

    case WM_COMMAND:
        UINT uID = LOWORD(wParam);
        switch (uID) {
        case IDC_SELECT_ALL:
            dlg.OnSelectAll();
            return TRUE;

        case IDC_SELECT_NONE:
            dlg.OnSelectNone();
            return TRUE;

        case IDC_APPLY:
            dlg.OnApply();
            return TRUE;

        case IDC_REFRESH:
            dlg.OnRefresh();
            return TRUE;

        case IDCANCEL:
            dlg.OnClose();
            return TRUE;
        }
        break;
    }
    return FALSE;
}
