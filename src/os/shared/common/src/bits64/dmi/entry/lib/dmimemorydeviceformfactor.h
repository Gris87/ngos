#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEFORMFACTOR_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEFORMFACTOR_H



#include <ngos/types.h>



enum class DmiMemoryDeviceFormFactor: u8
{
    NONE             = 0,
    OTHER            = 1,
    UNKNOWN          = 2,
    SIMM             = 3,
    SIP              = 4,
    CHIP             = 5,
    DIP              = 6,
    ZIP              = 7,
    PROPRIETARY_CARD = 8,
    DIMM             = 9,
    TSOP             = 10,
    ROW_OF_CHIPS     = 11,
    RIMM             = 12,
    SODIUM           = 13,
    SRIMM            = 14,
    FB_DIMM          = 15
};



inline const char8* enumToString(DmiMemoryDeviceFormFactor factor) // TEST: NO
{
    // COMMON_LT((" | factor = %u", factor)); // Commented to avoid bad looking logs



    switch (factor)
    {
        case DmiMemoryDeviceFormFactor::NONE:             return "NONE";
        case DmiMemoryDeviceFormFactor::OTHER:            return "OTHER";
        case DmiMemoryDeviceFormFactor::UNKNOWN:          return "UNKNOWN";
        case DmiMemoryDeviceFormFactor::SIMM:             return "SIMM";
        case DmiMemoryDeviceFormFactor::SIP:              return "SIP";
        case DmiMemoryDeviceFormFactor::CHIP:             return "CHIP";
        case DmiMemoryDeviceFormFactor::DIP:              return "DIP";
        case DmiMemoryDeviceFormFactor::ZIP:              return "ZIP";
        case DmiMemoryDeviceFormFactor::PROPRIETARY_CARD: return "PROPRIETARY_CARD";
        case DmiMemoryDeviceFormFactor::DIMM:             return "DIMM";
        case DmiMemoryDeviceFormFactor::TSOP:             return "TSOP";
        case DmiMemoryDeviceFormFactor::ROW_OF_CHIPS:     return "ROW_OF_CHIPS";
        case DmiMemoryDeviceFormFactor::RIMM:             return "RIMM";
        case DmiMemoryDeviceFormFactor::SODIUM:           return "SODIUM";
        case DmiMemoryDeviceFormFactor::SRIMM:            return "SRIMM";
        case DmiMemoryDeviceFormFactor::FB_DIMM:          return "FB_DIMM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiMemoryDeviceFormFactor factor) // TEST: NO
{
    // COMMON_LT((" | factor = %u", factor)); // Commented to avoid bad looking logs



    switch (factor)
    {
        case DmiMemoryDeviceFormFactor::NONE:             return "NONE";
        case DmiMemoryDeviceFormFactor::OTHER:            return "OTHER";
        case DmiMemoryDeviceFormFactor::UNKNOWN:          return "UNKNOWN";
        case DmiMemoryDeviceFormFactor::SIMM:             return "SIMM";
        case DmiMemoryDeviceFormFactor::SIP:              return "SIP";
        case DmiMemoryDeviceFormFactor::CHIP:             return "CHIP";
        case DmiMemoryDeviceFormFactor::DIP:              return "DIP";
        case DmiMemoryDeviceFormFactor::ZIP:              return "ZIP";
        case DmiMemoryDeviceFormFactor::PROPRIETARY_CARD: return "PROPRIETARY_CARD";
        case DmiMemoryDeviceFormFactor::DIMM:             return "DIMM";
        case DmiMemoryDeviceFormFactor::TSOP:             return "TSOP";
        case DmiMemoryDeviceFormFactor::ROW_OF_CHIPS:     return "ROW_OF_CHIPS";
        case DmiMemoryDeviceFormFactor::RIMM:             return "RIMM";
        case DmiMemoryDeviceFormFactor::SODIUM:           return "SODIUM";
        case DmiMemoryDeviceFormFactor::SRIMM:            return "SRIMM";
        case DmiMemoryDeviceFormFactor::FB_DIMM:          return "FB_DIMM";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEFORMFACTOR_H