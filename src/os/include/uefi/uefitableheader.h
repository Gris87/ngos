#ifndef UEFI_UEFITABLEHEADER_H
#define UEFI_UEFITABLEHEADER_H



#include <ngos/types.h>



struct UefiTableHeader
{
    u64 signature;
    u32 revision;
    u32 headerSize;
    u32 crc32;
    u32 reserved;
};



#endif // UEFI_UEFITABLEHEADER_H
