#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATECODETYPE_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATECODETYPE_H



#include <ngos/types.h>



enum class InflateCodeType: u8
{
    CODES,
    LENGTHS,
    DISTANCES
};



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATECODETYPE_H