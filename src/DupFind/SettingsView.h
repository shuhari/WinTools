#pragma once

#include "resource.h"

class SettingsView : public CDialogImpl<SettingsView>
{
public:
	enum { IDD = IDD_SETTINGS };
	
	SettingsView();
	~SettingsView();

	BEGIN_MSG_MAP_EX(SettingsView)
	END_MSG_MAP()
};

