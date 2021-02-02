#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFINETWORKSTATISTICS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFINETWORKSTATISTICS_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiNetworkStatistics
{
    bad_uint64 rxTotalFrames;
    bad_uint64 rxGoodFrames;
    bad_uint64 rxUndersizeFrames;
    bad_uint64 rxOversizeFrames;
    bad_uint64 rxDroppedFrames;
    bad_uint64 rxUnicastFrames;
    bad_uint64 rxBroadcastFrames;
    bad_uint64 rxMulticastFrames;
    bad_uint64 rxCrcErrorFrames;
    bad_uint64 rxTotalBytes;

    bad_uint64 txTotalFrames;
    bad_uint64 txGoodFrames;
    bad_uint64 txUndersizeFrames;
    bad_uint64 txOversizeFrames;
    bad_uint64 txDroppedFrames;
    bad_uint64 txUnicastFrames;
    bad_uint64 txBroadcastFrames;
    bad_uint64 txMulticastFrames;
    bad_uint64 txCrcErrorFrames;
    bad_uint64 txTotalBytes;

    bad_uint64 collisions;
    bad_uint64 unsupportedProtocol;

    bad_uint64 rxDuplicatedFrames;
    bad_uint64 rxDecryptErrorFrames;
    bad_uint64 txErrorFrames;
    bad_uint64 txRetryFrames;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFINETWORKSTATISTICS_H
