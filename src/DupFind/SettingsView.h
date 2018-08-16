#pragma once

class SettingsView : public CWindowImpl<SettingsView>
{
public:
	DECLARE_WND_CLASS(L"DupFind_SettingsView")

	SettingsView();
	~SettingsView();

	BEGIN_MSG_MAP_EX(SettingsView)
	END_MSG_MAP()
};

