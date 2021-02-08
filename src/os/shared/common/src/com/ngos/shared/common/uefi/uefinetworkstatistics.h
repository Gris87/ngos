#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFINETWORKSTATISTICS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFINETWORKSTATISTICS_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiNetworkStatistics
{
    u64 rxTotalFrames;
    u64 rxGoodFrames;
    u64 rxUndersizeFrames;
    u64 rxOversizeFrames;
    u64 rxDroppedFrames;
    u64 rxUnicastFrames;
    u64 rxBroadcastFrames;
    u64 rxMulticastFrames;
    u64 rxCrcErrorFrames;
    u64 rxTotalBytes;

    u64 txTotalFrames;
    u64 txGoodFrames;
    u64 txUndersizeFrames;
    u64 txOversizeFrames;
    u64 txDroppedFrames;
    u64 txUnicastFrames;
    u64 txBroadcastFrames;
    u64 txMulticastFrames;
    u64 txCrcErrorFrames;
    u64 txTotalBytes;

    u64 collisions;
    u64 unsupportedProtocol;

    u64 rxDuplicatedFrames;
    u64 rxDecryptErrorFrames;
    u64 txErrorFrames;
    u64 txRetryFrames;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFINETWORKSTATISTICS_H
