#pragma once


#include <vector>

class EnumString
{
public:
	EnumString();
	~EnumString();

	EnumString& addIf(UINT value, UINT flag, PCWSTR name);
	CString toString();

private:
	std::vector<CString> _names;
};

