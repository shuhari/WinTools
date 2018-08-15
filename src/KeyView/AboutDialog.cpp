#include "stdafx.h"
#include "AboutDialog.h"
#include "VersionReader.h"


AboutDialog::AboutDialog() {
}


AboutDialog::~AboutDialog() {
}


BOOL AboutDialog::onInitDialog(CWindow wndFocus, LPARAM lParam) {
	CenterWindow();

	HICON hIcon = LoadIcon(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME));
	CStatic lblIcon = GetDlgItem(IDS_APPICON);
	lblIcon.SetWindowLong(GWL_STYLE, lblIcon.GetStyle() | SS_ICON);
	lblIcon.SetIcon(hIcon);

	WCHAR szExePath[_MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szExePath, _MAX_PATH);
	VersionInfo version;
	VersionReader reader;
	if (reader.read(szExePath, version)) {
		CString strName;
		strName.Format(L"%s %s", version.ProductName, version.ProductVersion);
		SetDlgItemText(IDS_APP_NAME, strName);
		SetDlgItemText(IDS_APP_COPYRIGHT, version.LegalCopyright);
	}
	return TRUE;
}


void AboutDialog::onOk(UINT, int, CWindow) {
	EndDialog(IDOK);
}


void AboutDialog::onCancel(UINT, int, CWindow) {
	EndDialog(IDCANCEL);
}
