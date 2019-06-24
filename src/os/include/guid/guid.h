#ifndef GUID_GUID_H
#define GUID_GUID_H



#include <ngos/types.h>



struct Guid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4[8];
};



#endif // GUID_GUID_H
