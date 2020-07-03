#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUID_GUID_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUID_GUID_H



#include <com/ngos/shared/common/ngos/types.h>



struct Guid
{
    u32 data1;
    u16 data2;
    u16 data3;
    u8  data4[8];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUID_GUID_H
