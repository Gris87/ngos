#ifndef COM_NGOS_SHARED_COMMON_MBR_MBRPARTITION_H
#define COM_NGOS_SHARED_COMMON_MBR_MBRPARTITION_H



#include <com/ngos/shared/common/mbr/mbrpartitiontype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct MbrPartition
{
    bad_uint8               flags;
    bad_uint8               startChs[3];
    MbrPartitionType type;
    bad_uint8               endChs[3];
    bad_uint32              startLba;
    bad_uint32              size;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_MBR_MBRPARTITION_H
