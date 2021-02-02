#ifndef COM_NGOS_SHARED_COMMON_HEX_HEX_H
#define COM_NGOS_SHARED_COMMON_HEX_HEX_H



#include <com/ngos/shared/common/ngos/status.h>



class Hex
{
public:
    static NgosStatus toString(bad_uint8 *data, bad_int64 size, char8 *buffer, bad_int64 bufferSize, bool ellipsis);
    static NgosStatus toString(bad_uint8 *data, bad_int64 size, char8 **buffer, bad_int64 maxBufferSize, bool ellipsis);

private:
    static bad_uint16 sHexChars[256];
};



#endif // COM_NGOS_SHARED_COMMON_HEX_HEX_H
