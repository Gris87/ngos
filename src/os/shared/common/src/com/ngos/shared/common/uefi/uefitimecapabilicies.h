#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFITIMECAPABILICIES_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFITIMECAPABILICIES_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiTimeCapabilities
{
    bad_uint32  resolution; // 1e-6 parts per million
    bad_uint32  accuracy;   // hertz
    bool setsToZero; // Set clears sub-second time
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFITIMECAPABILICIES_H
