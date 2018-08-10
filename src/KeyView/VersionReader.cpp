#include "stdafx.h"
#include "VersionReader.h"


bool VersionReader::read(PCWSTR szPath, VersionInfo& version) {
	DWORD dwHandle;
	DWORD dwSize = GetFileVersionInfoSize(szPath, &dwHandle);
	if (dwSize == 0)
		return false;

	PBYTE pVersion = new BYTE[dwSize];
	if (pVersion == nullptr)
		goto error_exit;
	if (GetFileVersionInfo(szPath, dwHandle, dwSize, pVersion)) {
		PVOID pData = nullptr;
		UINT dwDataSize = 0;
		if (VerQueryValue(pVersion, L"\\VarFileInfo\\Translation", &pData, &dwDataSize) && dwDataSize == sizeof(DWORD)) {
			DWORD langId = *(DWORD*)pData;
			WORD wLanguage = LOWORD(langId);
			WORD wCodePage = HIWORD(langId);
			wchar_t langName[100] = { 0 };
			wsprintf(langName, L"%04X%04X", wLanguage, wCodePage);

			version.CompanyName = queryString(pVersion, langName, L"CompanyName");
			version.FileDescription =  queryString(pVersion, langName, L"FileDescription");
			version.FileVersion =  queryString(pVersion, langName, L"FileVersion");
			version.InternalName = queryString(pVersion, langName, L"InternalName");
			version.LegalCopyright = queryString(pVersion, langName, L"LegalCopyright");
			version.OriginalFilename = queryString(pVersion, langName, L"OriginalFilename");
			version.ProductName = queryString(pVersion, langName, L"ProductName");
			version.ProductVersion = queryString(pVersion, langName, L"ProductVersion");

			delete[]pVersion;
			return true;
		}
	}

error_exit:
	delete[]pVersion;
	return false;
}


CString VersionReader::queryString(PVOID pVersion, PCWSTR langName, PCWSTR itemName) {
	wchar_t entry[100] = { 0 };
	wsprintf(entry, L"\\StringFileInfo\\%s\\%s", langName, itemName);
	PVOID pData = nullptr;
	UINT dwDataSize = 0;
	BOOL bRet = VerQueryValue(pVersion, entry, &pData, &dwDataSize);
	if (bRet && dwDataSize > 0) {
		return CString((PWSTR)pData);
	}
	return "";
}