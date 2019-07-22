#ifndef OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATECODETYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATECODETYPE_H



#include <ngos/types.h>



enum class InflateCodeType: u8
{
    CODES,
    LENGTHS,
    DISTANCES
};



inline const char* inflateCodeTypeToString(InflateCodeType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case InflateCodeType::CODES:     return "CODES";
        case InflateCodeType::LENGTHS:   return "LENGTHS";
        case InflateCodeType::DISTANCES: return "DISTANCES";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATECODETYPE_H
