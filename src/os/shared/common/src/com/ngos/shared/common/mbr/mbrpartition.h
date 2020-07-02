#ifndef MBR_MBRPARTITION_H
#define MBR_MBRPARTITION_H



#include <common/src/com/ngos/shared/common/mbr/mbrpartitiontype.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct MbrPartition
{
    u8               flags;
    u8               startChs[3];
    MbrPartitionType type;
    u8               endChs[3];
    u32              startLba;
    u32              size;
} __attribute__((packed));



#endif // MBR_MBRPARTITION_H
