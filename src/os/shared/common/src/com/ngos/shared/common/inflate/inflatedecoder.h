#ifndef COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H
#define COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H



#include <com/ngos/shared/common/ngos/types.h>



struct InflateDecoder
{
    bad_uint8  *in;
    bad_uint64  inPosition;

    bad_uint8  *out;
    bad_uint64  outPosition;

    struct
    {
        bad_uint32 bitBuffer;
        bad_uint8  bitsAvailable;
    } temp;
};



#endif // COM_NGOS_SHARED_COMMON_INFLATE_INFLATEDECODER_H
