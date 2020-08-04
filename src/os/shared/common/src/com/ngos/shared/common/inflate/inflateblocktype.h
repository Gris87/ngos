#ifndef COM_NGOS_SHARED_COMMON_INFLATE_INFLATEBLOCKTYPE_H
#define COM_NGOS_SHARED_COMMON_INFLATE_INFLATEBLOCKTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class InflateBlockType: u8
{
    NO_COMPRESSION             = 0,
    COMPRESSED_FIXED_HUFFMAN   = 1,
    COMPRESSED_DYNAMIC_HUFFMAN = 2
};



inline const char8* enumToString(InflateBlockType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case InflateBlockType::NO_COMPRESSION:             return "NO_COMPRESSION";
        case InflateBlockType::COMPRESSED_FIXED_HUFFMAN:   return "COMPRESSED_FIXED_HUFFMAN";
        case InflateBlockType::COMPRESSED_DYNAMIC_HUFFMAN: return "COMPRESSED_DYNAMIC_HUFFMAN";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(InflateBlockType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_INFLATE_INFLATEBLOCKTYPE_H
