#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIIPADDRESS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIIPADDRESS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiipv4address.h>
#include <com/ngos/shared/common/uefi/uefiipv6address.h>



union UefiIpAddress
{
    u32             address[4];
    UefiIpV4Address v4;
    UefiIpV6Address v6;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIIPADDRESS_H
