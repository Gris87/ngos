#ifndef OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATECODE_H
#define OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATECODE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct InflateCode
{
    u8  operation;
    u8  bits;
    u16 value;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATECODE_H
