#pragma once

struct VersionInfo {
	CString CompanyName;
	CString FileDescription;
	CString FileVersion;
	CString InternalName;
	CString LegalCopyright;
	CString OriginalFilename;
	CString ProductName;
	CString ProductVersion;
};


class VersionReader
{
public:
	bool read(PCWSTR szPath, VersionInfo& version);

private:
	CString queryString(PVOID pVersion, PCWSTR langName, PCWSTR itemName);
};

