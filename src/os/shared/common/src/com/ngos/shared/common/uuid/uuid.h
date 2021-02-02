#ifndef COM_NGOS_SHARED_COMMON_UUID_UUID_H
#define COM_NGOS_SHARED_COMMON_UUID_UUID_H



#include <com/ngos/shared/common/ngos/types.h>



struct Uuid
{
    bad_uint32 data1;
    bad_uint16 data2;
    bad_uint16 data3;
    bad_uint8  data4;
    bad_uint8  data5;
    bad_uint8  data6[6];
};



#endif // COM_NGOS_SHARED_COMMON_UUID_UUID_H
