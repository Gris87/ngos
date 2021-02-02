#ifndef COM_NGOS_SHARED_COMMON_ZLIB_ZLIB_H
#define COM_NGOS_SHARED_COMMON_ZLIB_ZLIB_H



#include <com/ngos/shared/common/ngos/status.h>



class ZLib
{
public:
    static NgosStatus decompress(bad_uint8 *compressedAddress, bad_uint8 *decompressedAddress, bad_uint64 expectedCompressedSize, bad_uint64 expectedDecompressedSize); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_ZLIB_ZLIB_H
