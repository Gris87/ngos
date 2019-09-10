#ifndef UEFI_UEFIFILEINFO_H
#define UEFI_UEFIFILEINFO_H



#include <uefi/uefifileattributeflags.h>
#include <uefi/uefitime.h>



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
