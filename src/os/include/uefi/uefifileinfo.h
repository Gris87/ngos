#ifndef UEFI_UEFIFILEINFO_H
#define UEFI_UEFIFILEINFO_H



#include <uefi/uefifileattributeflags.h>
#include <uefi/uefitime.h>



#define UEFI_FILE_INFO_GUID \
    { 0x09576E92, 0x6D3F, 0x11D2, {0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B} }



struct UefiFileInfo
{
    u64                       size;
    u64                       fileSize;
    u64                       physicalSize;
    UefiTime                  createTime;
    UefiTime                  lastAccessTime;
    UefiTime                  modificationTime;
    uefi_file_attribute_flags attributes;
    char16                    fileName[0];
};



#endif // UEFI_UEFIFILEINFO_H
