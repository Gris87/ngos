#ifndef COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H
#define COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H



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



#endif // COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H
