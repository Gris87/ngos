#ifndef UEFI_UEFIGUID_H
#define UEFI_UEFIGUID_H



#include <ngos/types.h>



struct UefiGuid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4[8];
};



#endif // UEFI_UEFIGUID_H
