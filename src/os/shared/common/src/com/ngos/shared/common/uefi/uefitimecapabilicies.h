#ifndef UEFI_UEFITIMECAPABILICIES_H
#define UEFI_UEFITIMECAPABILICIES_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiTimeCapabilities
{
    u32  resolution; // 1e-6 parts per million
    u32  accuracy;   // hertz
    bool setsToZero; // Set clears sub-second time
};



#endif // UEFI_UEFITIMECAPABILICIES_H
