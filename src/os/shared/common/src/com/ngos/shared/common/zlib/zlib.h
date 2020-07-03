#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIB_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIB_H



#include <com/ngos/shared/common/ngos/status.h>



class ZLib
{
public:
    static NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIB_H
