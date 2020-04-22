#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiMemoryDeviceType: u8
{
    NONE                        = 0,
    OTHER                       = 1,
    UNKNOWN                     = 2,
    DRAM                        = 3,
    EDRAM                       = 4,
    VRAM                        = 5,
    SRAM                        = 6,
    RAM                         = 7,
    ROM                         = 8,
    FLASH                       = 9,
    EERPOM                      = 10,
    FEPROM                      = 11,
    EPROM                       = 12,
    CDRAM                       = 13,
    _3DRAM                      = 14,
    SDRAM                       = 15,
    SGRAM                       = 16,
    RDRAM                       = 17,
    DDR                         = 18,
    DDR2                        = 19,
    DDR2_FB_DIMM                = 20,
    DDR3                        = 24,
    FBD2                        = 25,
    DDR4                        = 26,
    LPDDR                       = 27,
    LPDDR2                      = 28,
    LPDDR3                      = 29,
    LPDDR4                      = 30,
    LOGICAL_NON_VOLATILE_DEVICE = 31,
    HBM                         = 32,
    HBM_2                       = 33
};



inline const char8* enumToString(DmiMemoryDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiMemoryDeviceType::NONE:                        return "NONE";
        case DmiMemoryDeviceType::OTHER:                       return "OTHER";
        case DmiMemoryDeviceType::UNKNOWN:                     return "UNKNOWN";
        case DmiMemoryDeviceType::DRAM:                        return "DRAM";
        case DmiMemoryDeviceType::EDRAM:                       return "EDRAM";
        case DmiMemoryDeviceType::VRAM:                        return "VRAM";
        case DmiMemoryDeviceType::SRAM:                        return "SRAM";
        case DmiMemoryDeviceType::RAM:                         return "RAM";
        case DmiMemoryDeviceType::ROM:                         return "ROM";
        case DmiMemoryDeviceType::FLASH:                       return "FLASH";
        case DmiMemoryDeviceType::EERPOM:                      return "EERPOM";
        case DmiMemoryDeviceType::FEPROM:                      return "FEPROM";
        case DmiMemoryDeviceType::EPROM:                       return "EPROM";
        case DmiMemoryDeviceType::CDRAM:                       return "CDRAM";
        case DmiMemoryDeviceType::_3DRAM:                      return "_3DRAM";
        case DmiMemoryDeviceType::SDRAM:                       return "SDRAM";
        case DmiMemoryDeviceType::SGRAM:                       return "SGRAM";
        case DmiMemoryDeviceType::RDRAM:                       return "RDRAM";
        case DmiMemoryDeviceType::DDR:                         return "DDR";
        case DmiMemoryDeviceType::DDR2:                        return "DDR2";
        case DmiMemoryDeviceType::DDR2_FB_DIMM:                return "DDR2_FB_DIMM";
        case DmiMemoryDeviceType::DDR3:                        return "DDR3";
        case DmiMemoryDeviceType::FBD2:                        return "FBD2";
        case DmiMemoryDeviceType::DDR4:                        return "DDR4";
        case DmiMemoryDeviceType::LPDDR:                       return "LPDDR";
        case DmiMemoryDeviceType::LPDDR2:                      return "LPDDR2";
        case DmiMemoryDeviceType::LPDDR3:                      return "LPDDR3";
        case DmiMemoryDeviceType::LPDDR4:                      return "LPDDR4";
        case DmiMemoryDeviceType::LOGICAL_NON_VOLATILE_DEVICE: return "LOGICAL_NON_VOLATILE_DEVICE";
        case DmiMemoryDeviceType::HBM:                         return "HBM";
        case DmiMemoryDeviceType::HBM_2:                       return "HBM_2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiMemoryDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPE_H
