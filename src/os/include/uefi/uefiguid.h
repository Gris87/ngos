#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGUID_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGUID_H



#include <ngos/types.h>



struct EfiGuid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4[8];
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGUID_H
