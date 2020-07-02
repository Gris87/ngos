#ifndef UUID_UUID_H
#define UUID_UUID_H



#include <ngos/types.h>



struct Uuid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4;
    u8  data5;
    u8  data6[6];
};



#endif // UUID_UUID_H
