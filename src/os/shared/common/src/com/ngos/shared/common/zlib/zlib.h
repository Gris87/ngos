#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIB_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIB_H



#include <common/src/com/ngos/shared/common/ngos/status.h>



class ZLib
{
public:
    static NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIB_H
