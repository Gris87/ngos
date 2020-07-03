#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MBR_MBRPARTITION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MBR_MBRPARTITION_H



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_MBR_MBRPARTITION_H
