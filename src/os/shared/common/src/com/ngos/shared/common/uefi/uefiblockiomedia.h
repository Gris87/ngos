#ifndef UEFI_UEFIBLOCKIOMEDIA_H
#define UEFI_UEFIBLOCKIOMEDIA_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>



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



#endif // UEFI_UEFIBLOCKIOMEDIA_H
