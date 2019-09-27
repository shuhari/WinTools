#pragma once


struct TidyItem {
    UINT uID;
    PCWSTR nsGuid;
    PCWSTR folderGuid;

    bool IsOn();
    void SetOn(bool on);
};
