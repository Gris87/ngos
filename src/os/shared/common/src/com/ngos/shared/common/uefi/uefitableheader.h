#ifndef UEFI_UEFITABLEHEADER_H
#define UEFI_UEFITABLEHEADER_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiTableHeader
{
    u64 signature;
    u32 revision;
    u32 headerSize;
    u32 crc32;
    u32 __reserved;
};



#endif // UEFI_UEFITABLEHEADER_H
