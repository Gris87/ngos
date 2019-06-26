#ifndef MBR_MBR_H
#define MBR_MBR_H



#include <mbr/mbrpartition.h>
#include <ngos/types.h>



#define MBR_BOOT_SIGNATURE 0xAA55



struct Mbr
{
    u8           code[440];
    u32          diskSignature;
    u16          __pad;
    MbrPartition partitions[4];
    u16          bootSignature;
} __attribute__((packed));



#endif // MBR_MBR_H
