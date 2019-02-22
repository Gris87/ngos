#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIINPUTKEY_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIINPUTKEY_H



#include <ngos/types.h>

#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiInputKey
{
    u16        scanCode;
    efi_char16 unicodeChar;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIINPUTKEY_H
