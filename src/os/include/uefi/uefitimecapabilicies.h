#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFITIMECAPABILICIES_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFITIMECAPABILICIES_H



#include <ngos/types.h>



struct EfiTimeCapabilities
{
    u32  resolution; // 1e-6 parts per million
    u32  accuracy;   // hertz
    bool setsToZero; // Set clears sub-second time
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFITIMECAPABILICIES_H
