#pragma once

#include <vector>


struct MsgRecord {
public:
	CString		msg;
	CString		flags;
	CString		ch;
	CString		coord;
	CString		scan;
	enum {
		ColumnCount = 80,
		RowCount = 20,
		OffsetMsg = 0,
		OffsetFlags = 20,
		OffsetCh = 30,
		OffsetCoord = 50,
		OffsetScan = 70,
	};

	MsgRecord();
	MsgRecord(const MsgRecord&);
	MsgRecord& operator=(const MsgRecord&);

	CString toString();
	static CString headerText();
	static CString separatorText();
	static void appendLeftAlignedText(PWSTR dest, PCWSTR str, size_t fieldWidth);

private:
	void	copyFrom(const MsgRecord& src);
};


class MsgRecordVector : public std::vector<MsgRecord> {
public:
	MsgRecordVector();
	~MsgRecordVector();

	void append(MsgRecord record);

	CString toString();

private:
	PWSTR appendLine(PWSTR szOffset, const CString& text);
};