#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefiipaddress.h>
#include <com/ngos/shared/common/uefi/uefinetworkstatistics.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkinterruptflags.h>
#include <com/ngos/shared/common/uefi/uefisimplenetworkmode.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_SIMPLE_NETWORK_PROTOCOL_GUID \
    { 0xA19832B9, 0xAC25, 0x11D3, { 0x9A, 0x2D, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }



#define UEFI_SIMPLE_NETWORK_PROTOCOL_REVISION 0x00010000



struct UefiSimpleNetworkProtocol // TODO: is it needed?
{
    bad_uint64 revision;

    UefiStatus (UEFI_API *start)(UefiSimpleNetworkProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *stop)(UefiSimpleNetworkProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *initialize)(UefiSimpleNetworkProtocol *obj, bad_uint64 extraRxBufferSize, bad_uint64 extraTxBufferSize); // TEST: NO
    UefiStatus (UEFI_API *reset)(UefiSimpleNetworkProtocol *obj, bool extendedVerification); // TEST: NO
    UefiStatus (UEFI_API *shutdown)(UefiSimpleNetworkProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *receiveFilters)(UefiSimpleNetworkProtocol *obj, UefiSimpleNetworkReceiveFilterFlags enable, UefiSimpleNetworkReceiveFilterFlags disable, bool resetMulticastFilter, bad_uint64 multicastFilterCount, UefiMacAddress *multicastFilter); // TEST: NO
    UefiStatus (UEFI_API *stationAddress)(UefiSimpleNetworkProtocol *obj, bool reset, UefiMacAddress *newAddress); // TEST: NO
    UefiStatus (UEFI_API *statistics)(UefiSimpleNetworkProtocol *obj, bool reset, bad_uint64 *statisticsSize, UefiNetworkStatistics *statisticsTable); // TEST: NO
    UefiStatus (UEFI_API *multicastIpToMac)(UefiSimpleNetworkProtocol *obj, bool isIpV6, UefiIpAddress *ip, UefiMacAddress *mac); // TEST: NO
    UefiStatus (UEFI_API *nvData)(UefiSimpleNetworkProtocol *obj, bool isReadOperation, bad_uint64 offset, bad_uint64 bufferSize, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *getStatus)(UefiSimpleNetworkProtocol *obj, UefiSimpleNetworkInterruptFlags *interruptStatus, void **txBuffer); // TEST: NO
    UefiStatus (UEFI_API *transmit)(UefiSimpleNetworkProtocol *obj, bad_uint64 headerSize, bad_uint64 bufferSize, void *buffer, UefiMacAddress *sourceAddress, UefiMacAddress *destinationAddress, bad_uint16 *protocol); // TEST: NO
    UefiStatus (UEFI_API *receive)(UefiSimpleNetworkProtocol *obj, bad_uint64 *headerSize, bad_uint64 *bufferSize, void *buffer, UefiMacAddress *sourceAddress, UefiMacAddress *destinationAddress, bad_uint16 *protocol); // TEST: NO

    uefi_event             waitForPacket;
    UefiSimpleNetworkMode *mode;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKPROTOCOL_H
