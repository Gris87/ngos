#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORTYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiProcessorType: u8
{
    NONE              = 0,
    OTHER             = 1,
    UNKNOWN           = 2,
    CENTRAL_PROCESSOR = 3,
    MATH_PROCESSOR    = 4,
    DSP_PROCESSOR     = 5,
    VIDEO_PROCESSOR   = 6
};



inline const char8* enumToString(DmiProcessorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiProcessorType::NONE:              return "NONE";
        case DmiProcessorType::OTHER:             return "OTHER";
        case DmiProcessorType::UNKNOWN:           return "UNKNOWN";
        case DmiProcessorType::CENTRAL_PROCESSOR: return "CENTRAL_PROCESSOR";
        case DmiProcessorType::MATH_PROCESSOR:    return "MATH_PROCESSOR";
        case DmiProcessorType::DSP_PROCESSOR:     return "DSP_PROCESSOR";
        case DmiProcessorType::VIDEO_PROCESSOR:   return "VIDEO_PROCESSOR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiProcessorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORTYPE_H
