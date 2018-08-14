#pragma once

#include <vector>


struct MsgRecord {
public:
	enum MsgType {
		MsgKeyboard = 1,
		MsgMouse = 2,
	};

	enum {
		ColumnCount = 80,
		RowCount = 20,
		OffsetMsg = 0,
		OffsetFlags = 20,
		OffsetCh = 35,
		OffsetCoord = 55,
		OffsetScan = 70,
	};

	MsgType		type;
	CString		name;
	CString		flags;
	CString		ch;
	CString		coord;
	CString		scan;

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

private:
	PWSTR appendLine(PWSTR szOffset, const CString& text);
};