#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIIPV6ADDRESS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIIPV6ADDRESS_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiIpV6Address
{
    bad_uint8 address[16];
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIIPV6ADDRESS_H
