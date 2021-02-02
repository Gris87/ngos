#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKMODE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefimacaddress.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkinterfacetype.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkreceivefilterflags.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkstate.h>



#define MAXIMUM_MULTICAST_FILTER_COUNT 16



struct UefiSimpleNetworkMode
{
    UefiSimpleNetworkState              state;
    bad_uint32                                 hardwareAddressSize;
    bad_uint32                                 mediaHeaderSize;
    bad_uint32                                 maximumPacketSize;
    bad_uint32                                 nvramSize;
    bad_uint32                                 nvramAccessSize;
    UefiSimpleNetworkReceiveFilterFlags receiveFilterMask;
    UefiSimpleNetworkReceiveFilterFlags receiveFilterSetting;
    bad_uint32                                 maximumMulticastFilterCount;
    bad_uint32                                 multicastFilterCount;
    UefiMacAddress                      multicastFilter[MAXIMUM_MULTICAST_FILTER_COUNT];
    UefiMacAddress                      currentAddress;
    UefiMacAddress                      broadcastAddress;
    UefiMacAddress                      permanentAddress;
    UefiSimpleNetworkInterfaceType      interfaceType;
    bool                                macAddressChangeable;
    bool                                multipleTxSupported;
    bool                                mediaPresentSupported;
    bool                                mediaPresent;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKMODE_H
