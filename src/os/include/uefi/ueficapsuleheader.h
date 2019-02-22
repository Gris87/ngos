#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFICAPSULEHEADER_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFICAPSULEHEADER_H



#include "src/bits64/a_uefi/uefi/lib/efiguid.h"



struct EfiCapsuleHeader
{
    EfiGuid capsuleGuid;
    u32     headerSize;
    u32     flags;
    u32     capsuleImageSize;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFICAPSULEHEADER_H
