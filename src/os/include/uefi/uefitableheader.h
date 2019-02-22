#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFITABLEHEADER_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFITABLEHEADER_H



#include <ngos/types.h>



struct EfiTableHeader
{
    u64 signature;
    u32 revision;
    u32 headerSize;
    u32 crc32;
    u32 reserved;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFITABLEHEADER_H
