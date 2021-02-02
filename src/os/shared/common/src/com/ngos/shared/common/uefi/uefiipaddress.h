#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIIPADDRESS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIIPADDRESS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiipv4address.h>
#include <com/ngos/shared/common/uefi/uefiipv6address.h>



union UefiIpAddress
{
    bad_uint32             address[4];
    UefiIpV4Address v4;
    UefiIpV6Address v6;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIIPADDRESS_H
