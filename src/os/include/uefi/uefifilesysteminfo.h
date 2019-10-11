#ifndef UEFI_UEFIFILESYSTEMINFO_H
#define UEFI_UEFIFILESYSTEMINFO_H



#include <ngos/types.h>



#define UEFI_FILESYSTEM_INFO_GUID \
    { 0x09576E93, 0x6D3F, 0x11D2, {0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B} }



struct UefiFileSystemInfo
{
    u64    size;
    bool   readOnly;
    u64    volumeSize;
    u64    freeSpace;
    u32    blockSize;
    char16 volumeLabel[0];
};



#endif // UEFI_UEFIFILESYSTEMINFO_H
