#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct ZLibHeader
{
    union
    {
        struct
        {
            u8 compressionMethod: 4;
            u8 compressionInfo:   4;
            u8 checkBits:         5;
            u8 presetDictionary:  1;
            u8 compressionLevel:  2;
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H
