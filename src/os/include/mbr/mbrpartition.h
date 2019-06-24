#ifndef MBR_MBRPARTITION_H
#define MBR_MBRPARTITION_H



#include <ngos/types.h>



struct MbrPartition
{
   u8  flags;
   u8  startChs[3];
   u8  type;
   u8  endChs[3];
   u32 startLba;
   u32 size;
};



#endif // MBR_MBRPARTITION_H
