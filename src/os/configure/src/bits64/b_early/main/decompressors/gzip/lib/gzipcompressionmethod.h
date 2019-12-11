#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPCOMPRESSIONMETHOD_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPCOMPRESSIONMETHOD_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
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



    switch (method)
    {
        case GzipCompressionMethod::NONE:    return "NONE";
        case GzipCompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPCOMPRESSIONMETHOD_H
