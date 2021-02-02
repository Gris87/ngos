#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIMACADDRESS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIMACADDRESS_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiMacAddress
{
    bad_uint8 address[32];
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIMACADDRESS_H
