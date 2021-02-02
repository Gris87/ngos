#ifndef COM_NGOS_SHARED_COMMON_GUID_GUID_H
#define COM_NGOS_SHARED_COMMON_GUID_GUID_H



#include <com/ngos/shared/common/ngos/types.h>



struct Guid
{
    bad_uint32 data1;
    bad_uint16 data2;
    bad_uint16 data3;
    bad_uint8  data4[8];
};



#endif // COM_NGOS_SHARED_COMMON_GUID_GUID_H
