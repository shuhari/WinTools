#include "stdafx.h"
#include "EnumString.h"


EnumString::EnumString() {
}


EnumString::~EnumString() {
}


EnumString& EnumString::addIf(UINT value, UINT flag, PCWSTR name) {
	if ((value & flag) == flag) {
		_names.push_back(name);
	}
	return *this;
}


CString EnumString::toString() {
	CString result;
	for (size_t i = 0; i < _names.size(); i++) {
		result += _names.at(i);
		if (i < _names.size() - 1) {
			result += L",";
		}
	}
	return result;
}