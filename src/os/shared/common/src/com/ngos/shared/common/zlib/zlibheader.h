#ifndef COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H
#define COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



struct ZLibHeader
{
    union
    {
        struct
        {
            bad_uint8 compressionMethod: 4;
            bad_uint8 compressionInfo:   4;
            bad_uint8 checkBits:         5;
            bad_uint8 presetDictionary:  1;
            bad_uint8 compressionLevel:  2;
        };

        bad_uint16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_ZLIB_ZLIBHEADER_H
