#pragma once


#include <map>


class KeyString
{
public:
	KeyString();
	~KeyString();

	CString toString(UINT nChar);

private:
	std::map<UINT, CString> _keyMap;

	void define(UINT nChar, PCWSTR name);
};

