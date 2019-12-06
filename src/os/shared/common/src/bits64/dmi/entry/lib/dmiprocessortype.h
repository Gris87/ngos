#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORTYPE_H



#include <ngos/types.h>



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



inline const char8* dmiProcessorTypeToString(DmiProcessorType type) // TEST: NO
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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORTYPE_H