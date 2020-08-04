#ifndef COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H
#define COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H
