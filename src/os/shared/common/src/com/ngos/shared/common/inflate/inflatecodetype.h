#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATECODETYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATECODETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class InflateCodeType: u8
{
    CODES     = 0,
    LENGTHS   = 1,
    DISTANCES = 2
};



inline const char8* enumToString(InflateCodeType type) // TEST: NO
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



inline const char8* enumToFullString(InflateCodeType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATECODETYPE_H
