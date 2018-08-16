#pragma once


#include "resource.h"


class AboutDialog : public CDialogImpl<AboutDialog>
{
public:
	enum { IDD = IDD_ABOUT };

	AboutDialog();
	~AboutDialog();

	BEGIN_MSG_MAP_EX(AboutDialog)
		MSG_WM_INITDIALOG(onInitDialog)
		MSG_WM_DESTROY(onDestroy)

		COMMAND_ID_HANDLER_EX(IDOK, onCancel)
		COMMAND_ID_HANDLER_EX(IDCANCEL, onCancel)
	END_MSG_MAP()

private:
	BOOL onInitDialog(CWindow wndFocus, LPARAM lParam);
	void onDestroy();

	void onCancel(UINT, int, CWindow);
};

