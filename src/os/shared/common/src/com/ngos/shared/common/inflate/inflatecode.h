#ifndef COM_NGOS_SHARED_COMMON_INFLATE_INFLATECODE_H
#define COM_NGOS_SHARED_COMMON_INFLATE_INFLATECODE_H



#include <com/ngos/shared/common/ngos/types.h>



struct InflateCode
{
    bad_uint8  operation;
    bad_uint8  bits;
    bad_uint16 value;
};



#endif // COM_NGOS_SHARED_COMMON_INFLATE_INFLATECODE_H
