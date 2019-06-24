#ifndef MBR_MBR_H
#define MBR_MBR_H



#include <mbr/mbrpartition.h>
#include <ngos/types.h>




struct Mbr
{
   u8           code[440];
   u32          diskSignature;
   u16          __pad;
   MbrPartition partitions[4];
   u16          mbrSignature;
};



#endif // MBR_MBR_H
