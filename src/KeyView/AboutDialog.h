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

		COMMAND_ID_HANDLER_EX(IDOK, onOk)
		COMMAND_ID_HANDLER_EX(IDCANCEL, onCancel)
	END_MSG_MAP()

private:
	BOOL onInitDialog(CWindow wndFocus, LPARAM lParam);

	void onOk(UINT, int, CWindow);
	void onCancel(UINT, int, CWindow);
};

