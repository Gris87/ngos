#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOMEDIA_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOMEDIA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>



struct UefiBlockIoMedia
{
    bad_uint32      mediaId;
    bool     removableMedia;
    bool     mediaPresent;
    bool     logicalPartition;
    bool     readOnly;
    bool     writeCaching;
    bad_uint32      blockSize;
    bad_uint32      ioAlign;
    uefi_lba lastBlock;
    uefi_lba lowestAlignedLba;
    bad_uint32      logicalBlocksPerPhysicalBlock;
    bad_uint32      optimalTransferLengthGranularity;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIBLOCKIOMEDIA_H
