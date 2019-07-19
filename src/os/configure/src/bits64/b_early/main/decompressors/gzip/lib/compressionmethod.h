#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_COMPRESSIONMETHOD_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_COMPRESSIONMETHOD_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



enum class CompressionMethod: u8
{
    NONE    = 0,
    DEFLATE = 8
};



inline const char* compressionMethodToString(CompressionMethod method) // TEST: NO
{
    // EARLY_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case CompressionMethod::NONE:    return "NONE";
        case CompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_COMPRESSIONMETHOD_H
