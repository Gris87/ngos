#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIBCOMPRESSIONMETHOD_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIBCOMPRESSIONMETHOD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



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

    sprintf(res, "0x%02X (%s)", method, enumToString(method));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ZLIB_ZLIBCOMPRESSIONMETHOD_H
