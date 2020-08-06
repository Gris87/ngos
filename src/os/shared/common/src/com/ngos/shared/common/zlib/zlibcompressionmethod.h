#ifndef COM_NGOS_SHARED_COMMON_ZLIB_ZLIBCOMPRESSIONMETHOD_H
#define COM_NGOS_SHARED_COMMON_ZLIB_ZLIBCOMPRESSIONMETHOD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class ZLibCompressionMethod: u8
{
    NONE    = 0,
    DEFLATE = 8
};



inline const char8* enumToString(ZLibCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case ZLibCompressionMethod::NONE:    return "NONE";
        case ZLibCompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ZLibCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)method, enumToString(method));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ZLIB_ZLIBCOMPRESSIONMETHOD_H
