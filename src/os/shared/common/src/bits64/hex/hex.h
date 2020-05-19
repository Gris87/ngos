#ifndef OS_SHARED_COMMON_SRC_BITS64_HEX_HEX_H
#define OS_SHARED_COMMON_SRC_BITS64_HEX_HEX_H



#include <ngos/status.h>



class Hex
{
public:
    static NgosStatus toString(u8 *data, u64 size, char8 *buffer, u64 bufferSize, bool ellipsis);
    static NgosStatus toString(u8 *data, u64 size, char8 **buffer, u64 maxBufferSize, bool ellipsis);
};



#endif // OS_SHARED_COMMON_SRC_BITS64_HEX_HEX_H
