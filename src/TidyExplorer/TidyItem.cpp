#include "stdafx.h"
#include "TidyItem.h"
#include "RegKey.h"


const PCWSTR KEY_PREFIX = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer";


bool TidyItem::IsOn() {
    WCHAR szKey[_MAX_PATH] = { 0 };
    wsprintf(szKey, L"%s\\MyComputer\\NameSpace\\%s", KEY_PREFIX, nsGuid);
    RegKey rk;
    if (!rk.Open(HKEY_LOCAL_MACHINE, szKey, KEY_READ)) {
        return false;
    }

    if (folderGuid) {
        wsprintf(szKey, L"%s\\FolderDescriptions\\%s\\PropertyBag", KEY_PREFIX, folderGuid);
        if (rk.Open(HKEY_LOCAL_MACHINE, szKey, KEY_READ)) {
            WCHAR szValue[100] = { 0 };
            memset(szValue, 0, sizeof(szValue));
            DWORD dwType = REG_SZ;
            DWORD dwSize = sizeof(szValue);
            if (rk.QueryValue(L"ThisPCPolicy", &dwType, (PBYTE)szValue, &dwSize)) {
                if (_wcsicmp(szValue, L"hide") == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}


void TidyItem::SetOn(bool on) {
    WCHAR szKey[_MAX_PATH] = { 0 };
    RegKey rk;
    if (on) {
        wsprintf(szKey, L"%s\\MyComputer\\NameSpace\\%s", KEY_PREFIX, nsGuid);
        if (!rk.Create(HKEY_LOCAL_MACHINE, szKey, KEY_ALL_ACCESS, NULL, NULL)) {
            return;
        }
    }
    else {
        wsprintf(szKey, L"%s\\MyComputer\\NameSpace", KEY_PREFIX);
        if (!rk.Open(HKEY_LOCAL_MACHINE, szKey, KEY_ALL_ACCESS))
            return;
        if (!rk.DeleteKey(nsGuid, KEY_WOW64_64KEY)) {
            return;
        }
    }

    if (folderGuid) {
        wsprintf(szKey, L"%s\\FolderDescriptions\\%s\\PropertyBag", KEY_PREFIX, folderGuid);
        if (rk.Open(HKEY_LOCAL_MACHINE, szKey, KEY_READ | KEY_SET_VALUE)) {
            PCWSTR szValue = on ? L"Show" : L"Hide";
            DWORD dwSize = (DWORD)((wcslen(szValue) + 1) * sizeof(WCHAR));
            rk.SetValue(L"ThisPCPolicy", REG_SZ, (PBYTE)szValue, dwSize);
        }
    }
}

