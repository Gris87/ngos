#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOMEDIA_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOMEDIA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>



struct UefiBlockIoMedia
{
    u32      mediaId;
    bool     removableMedia;
    bool     mediaPresent;
    bool     logicalPartition;
    bool     readOnly;
    bool     writeCaching;
    u32      blockSize;
    u32      ioAlign;
    uefi_lba lastBlock;
    uefi_lba lowestAlignedLba;
    u32      logicalBlocksPerPhysicalBlock;
    u32      optimalTransferLengthGranularity;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOMEDIA_H
