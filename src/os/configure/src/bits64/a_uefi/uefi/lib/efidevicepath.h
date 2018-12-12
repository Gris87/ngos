#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIDEVICEPATH_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIDEVICEPATH_H



#include <ngos/types.h>



struct EfiDevicePath
{
    u8 type;
    u8 subType;
    u8 length[2];
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIDEVICEPATH_H
