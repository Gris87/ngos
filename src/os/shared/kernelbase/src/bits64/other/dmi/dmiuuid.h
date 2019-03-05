#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIUUID_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIUUID_H



#include <ngos/types.h>



struct DmiUuid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4;
    u8  data5;
    u8  data6[6];
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIUUID_H
