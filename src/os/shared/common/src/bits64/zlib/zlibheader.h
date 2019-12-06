#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBHEADER_H



#include <ngos/types.h>



struct ZLibHeader
{
    u8 compressionMethod: 4;
    u8 compressionInfo:   4;

    u8 checkBits:        5;
    u8 presetDictionary: 1;
    u8 compressionLevel: 2;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBHEADER_H
