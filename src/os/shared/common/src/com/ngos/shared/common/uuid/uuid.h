#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UUID_UUID_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UUID_UUID_H



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UUID_UUID_H
