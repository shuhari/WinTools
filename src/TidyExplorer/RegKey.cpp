#include "stdafx.h"
#include "RegKey.h"


RegKey::RegKey() : _hKey(NULL) {

}


RegKey::~RegKey() {
    Close();
}


void RegKey::Close() {
    if (_hKey != NULL) {
        RegCloseKey(_hKey);
        _hKey = NULL;
    }
}


bool RegKey::Open(HKEY rootKey, PCWSTR subKey, REGSAM samDesired) {
    Close();

    LSTATUS lRet = RegOpenKeyEx(rootKey, subKey, 0, samDesired, &_hKey);
    return lRet == ERROR_SUCCESS;
}

bool RegKey::Create(HKEY rootKey, PCWSTR subKey, REGSAM samDesired,
    const LPSECURITY_ATTRIBUTES pSecurityAttributes, PDWORD pdwDisposition) {
    Close();

    LSTATUS lRet = RegCreateKeyEx(rootKey, subKey, 0, NULL, 0, samDesired, pSecurityAttributes, &_hKey, pdwDisposition);
    return lRet == ERROR_SUCCESS;
}


bool RegKey::QueryValue(PCWSTR szValueName, PDWORD pType, PBYTE pData, PDWORD pcbData) {
    LSTATUS lRet = RegQueryValueEx(_hKey, szValueName, NULL, pType, pData, pcbData);
    return lRet == ERROR_SUCCESS;
}


bool RegKey::SetValue(PCWSTR szValueName, DWORD dwType, const PBYTE pData, DWORD cbData) {
    LSTATUS lRet = RegSetValueEx(_hKey, szValueName, 0, dwType, pData, cbData);
    return lRet == ERROR_SUCCESS;
}


bool RegKey::DeleteKey(PCWSTR subKey, REGSAM  samDesired) {
    LSTATUS lRet = RegDeleteKeyEx(_hKey, subKey, samDesired, 0);
    return lRet == ERROR_SUCCESS;
}
