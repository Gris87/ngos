#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H



#include <com/ngos/shared/common/ngos/types.h>



struct InflateDecoder
{
    u8  *in;
    u64  inPosition;

    u8  *out;
    u64  outPosition;

    struct
    {
        u32 bitBuffer;
        u8  bitsAvailable;
    } temp;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H
