#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFITABLEHEADER_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFITABLEHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiTableHeader
{
    u64 signature;
    u32 revision;
    u32 headerSize;
    u32 crc32;
    u32 __reserved;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFITABLEHEADER_H
