#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_HEX_HEX_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_HEX_HEX_H



#include <common/src/com/ngos/shared/common/ngos/status.h>



class Hex
{
public:
    static NgosStatus toString(u8 *data, i64 size, char8 *buffer, i64 bufferSize, bool ellipsis);
    static NgosStatus toString(u8 *data, i64 size, char8 **buffer, i64 maxBufferSize, bool ellipsis);

private:
    static u16 sHexChars[256];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_HEX_HEX_H
