#include "stdafx.h"
#include "MsgRecord.h"


MsgRecord::MsgRecord() {

}


MsgRecord::MsgRecord(const MsgRecord& src) {
	copyFrom(src);
}


MsgRecord& MsgRecord::operator=(const MsgRecord& src) {
	copyFrom(src);
	return *this;
}


void MsgRecord::copyFrom(const MsgRecord& src) {
	msg = src.msg;
	flags = src.flags;
	ch = src.ch;
	coord = src.coord;
	scan = src.scan;
}


CString MsgRecord::headerText() {
	WCHAR sz[ColumnCount + 1] = { 0 };
	appendLeftAlignedText(sz, L"Message", OffsetFlags - OffsetMsg);
	appendLeftAlignedText(sz, L"Flags", OffsetCh - OffsetFlags);
	appendLeftAlignedText(sz, L"Char", OffsetCoord - OffsetCh);
	appendLeftAlignedText(sz, L"Coord", OffsetScan - OffsetCoord);
	appendLeftAlignedText(sz, L"Scan", ColumnCount - OffsetScan);
	return CString(sz);
}


CString MsgRecord::separatorText() {
	return CString(L'-', ColumnCount);
}


CString MsgRecord::toString() {
	WCHAR sz[ColumnCount + 1] = { 0 };
	appendLeftAlignedText(sz, msg, OffsetFlags - OffsetMsg);
	appendLeftAlignedText(sz, flags, OffsetCh - OffsetFlags);
	appendLeftAlignedText(sz, ch, OffsetCoord - OffsetCh);
	appendLeftAlignedText(sz, coord, OffsetScan - OffsetCoord);
	appendLeftAlignedText(sz, scan, ColumnCount - OffsetScan);
	return CString(sz);
}


void MsgRecord::appendLeftAlignedText(PWSTR dest, PCWSTR str, size_t fieldWidth) {
	wcscat_s(dest, ColumnCount + 1, str);
	if (fieldWidth > wcslen(str)) {
		CString fill(' ', fieldWidth - wcslen(str));
		wcscat_s(dest, ColumnCount + 1, fill);
	}
}


MsgRecordVector::MsgRecordVector() {
}


MsgRecordVector::~MsgRecordVector() {
}


void MsgRecordVector::append(MsgRecord record) {
	if (size() >= MsgRecord::RowCount) {
		erase(begin());
	}
	push_back(record);
}


CString MsgRecordVector::toString() {
	int rowCount = size() + 2;
	int colWidth = MsgRecord::ColumnCount + 1;
	int charCount = rowCount * colWidth + 1;
	PWSTR psz = new WCHAR[charCount];
	assert(psz);
	memset(psz, 0, charCount * sizeof(WCHAR));
	PWSTR pszNext = appendLine(psz, MsgRecord::headerText());
	pszNext = appendLine(pszNext, MsgRecord::separatorText());
	for (size_t i = 0; i < size(); i++) {
		pszNext = appendLine(pszNext, at(i).toString());
	}
	CString result = psz;
	delete[]psz;
	return result;
}


PWSTR MsgRecordVector::appendLine(PWSTR szOffset, const CString& text) {
	assert(text.GetLength() == MsgRecord::ColumnCount);
	wcscpy_s(szOffset, MsgRecord::ColumnCount + 1, text);
	wcscpy_s(szOffset + MsgRecord::ColumnCount, 2, L"\n");
	return szOffset + (MsgRecord::ColumnCount + 1);
}
