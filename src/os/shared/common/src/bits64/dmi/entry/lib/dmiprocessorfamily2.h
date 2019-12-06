#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY2_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY2_H



#include <ngos/types.h>



enum class DmiProcessorFamily2: u16
{
    NONE            = 0,
    OTHER           = 1,
    ARM_V7          = 0x0100,
    ARM_V8          = 0x0101,
    SH3             = 0x0104,
    SH4             = 0x0105,
    ARM             = 0x0118,
    STRONG_ARM      = 0x0119,
    _6_X86          = 0x012C,
    MEDIA_GX        = 0x012D,
    MII             = 0x012E,
    WIN_CHIP        = 0x0140,
    DSP             = 0x015E,
    VIDEO_PROCESSOR = 0x01F4
};



inline const char8* dmiProcessorFamily2ToString(DmiProcessorFamily2 family2) // TEST: NO
{
    // COMMON_LT((" | family2 = %u", family2)); // Commented to avoid bad looking logs



    switch (family2)
    {
        case DmiProcessorFamily2::NONE:            return "NONE";
        case DmiProcessorFamily2::OTHER:           return "OTHER";
        case DmiProcessorFamily2::ARM_V7:          return "ARM_V7";
        case DmiProcessorFamily2::ARM_V8:          return "ARM_V8";
        case DmiProcessorFamily2::SH3:             return "SH3";
        case DmiProcessorFamily2::SH4:             return "SH4";
        case DmiProcessorFamily2::ARM:             return "ARM";
        case DmiProcessorFamily2::STRONG_ARM:      return "STRONG_ARM";
        case DmiProcessorFamily2::_6_X86:          return "_6_X86";
        case DmiProcessorFamily2::MEDIA_GX:        return "MEDIA_GX";
        case DmiProcessorFamily2::MII:             return "MII";
        case DmiProcessorFamily2::WIN_CHIP:        return "WIN_CHIP";
        case DmiProcessorFamily2::DSP:             return "DSP";
        case DmiProcessorFamily2::VIDEO_PROCESSOR: return "VIDEO_PROCESSOR";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORFAMILY2_H
