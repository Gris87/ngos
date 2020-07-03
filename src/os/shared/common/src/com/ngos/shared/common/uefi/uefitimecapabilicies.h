#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFITIMECAPABILICIES_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFITIMECAPABILICIES_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiTimeCapabilities
{
    u32  resolution; // 1e-6 parts per million
    u32  accuracy;   // hertz
    bool setsToZero; // Set clears sub-second time
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFITIMECAPABILICIES_H
