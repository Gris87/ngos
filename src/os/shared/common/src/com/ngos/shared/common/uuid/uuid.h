#ifndef COM_NGOS_SHARED_COMMON_UUID_UUID_H
#define COM_NGOS_SHARED_COMMON_UUID_UUID_H



#include <com/ngos/shared/common/ngos/types.h>



struct Uuid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4;
    u8  data5;
    u8  data6[6];
};



#endif // COM_NGOS_SHARED_COMMON_UUID_UUID_H
