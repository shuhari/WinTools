#pragma once


class RegKey {
public:
    RegKey();
    ~RegKey();

    bool Open(HKEY rootKey, PCWSTR subKey, REGSAM samDesired);
    bool Create(HKEY rootKey, PCWSTR subKey, REGSAM samDesired, 
        const LPSECURITY_ATTRIBUTES pSecurityAttributes, PDWORD pdwDisposition = NULL);
    void Close();
    bool QueryValue(PCWSTR szValueName, PDWORD pType, PBYTE pData, PDWORD pcbData);
    bool SetValue(PCWSTR szValueName, DWORD dwType, const PBYTE pData, DWORD cbData);
    bool DeleteKey(PCWSTR subKey, REGSAM  samDesired);

private:
    HKEY _hKey;
};
