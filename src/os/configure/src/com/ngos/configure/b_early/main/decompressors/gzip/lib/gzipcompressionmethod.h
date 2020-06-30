#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPCOMPRESSIONMETHOD_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPCOMPRESSIONMETHOD_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



enum class GzipCompressionMethod: u8
{
    NONE    = 0,
    DEFLATE = 8
};



inline const char8* enumToString(GzipCompressionMethod method) // TEST: NO
{
    // EARLY_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case GzipCompressionMethod::NONE:    return "NONE";
        case GzipCompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(GzipCompressionMethod method) // TEST: NO
{
    // EARLY_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", method, enumToString(method));

    return res;
}



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPCOMPRESSIONMETHOD_H
