#ifndef COM_NGOS_SHARED_COMMON_MBR_MBR_H
#define COM_NGOS_SHARED_COMMON_MBR_MBR_H



#include <com/ngos/shared/common/mbr/mbrpartition.h>
#include <com/ngos/shared/common/ngos/types.h>



#define MBR_BOOT_SIGNATURE 0xAA55



struct Mbr
{
    bad_uint8           code[440];
    bad_uint32          diskSignature;
    bad_uint16          __pad;
    MbrPartition partitions[4];
    bad_uint16          bootSignature;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_MBR_MBR_H
