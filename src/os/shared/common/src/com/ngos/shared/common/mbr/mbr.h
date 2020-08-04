#ifndef COM_NGOS_SHARED_COMMON_MBR_MBR_H
#define COM_NGOS_SHARED_COMMON_MBR_MBR_H



#include <com/ngos/shared/common/mbr/mbrpartition.h>
#include <com/ngos/shared/common/ngos/types.h>



#define MBR_BOOT_SIGNATURE 0xAA55



struct Mbr
{
    u8           code[440];
    u32          diskSignature;
    u16          __pad;
    MbrPartition partitions[4];
    u16          bootSignature;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_MBR_MBR_H
