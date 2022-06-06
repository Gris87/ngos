#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPE_H                                                                                                                                       // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPE_H                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class DmiMemoryDeviceType: u8                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                        = 0,                                                                                                                                                                     // Colorize: green
    OTHER                       = 1,                                                                                                                                                                     // Colorize: green
    UNKNOWN                     = 2,                                                                                                                                                                     // Colorize: green
    DRAM                        = 3,                                                                                                                                                                     // Colorize: green
    EDRAM                       = 4,                                                                                                                                                                     // Colorize: green
    VRAM                        = 5,                                                                                                                                                                     // Colorize: green
    SRAM                        = 6,                                                                                                                                                                     // Colorize: green
    RAM                         = 7,                                                                                                                                                                     // Colorize: green
    ROM                         = 8,                                                                                                                                                                     // Colorize: green
    FLASH                       = 9,                                                                                                                                                                     // Colorize: green
    EERPOM                      = 10,                                                                                                                                                                    // Colorize: green
    FEPROM                      = 11,                                                                                                                                                                    // Colorize: green
    EPROM                       = 12,                                                                                                                                                                    // Colorize: green
    CDRAM                       = 13,                                                                                                                                                                    // Colorize: green
    _3DRAM                      = 14,                                                                                                                                                                    // Colorize: green
    SDRAM                       = 15,                                                                                                                                                                    // Colorize: green
    SGRAM                       = 16,                                                                                                                                                                    // Colorize: green
    RDRAM                       = 17,                                                                                                                                                                    // Colorize: green
    DDR                         = 18,                                                                                                                                                                    // Colorize: green
    DDR2                        = 19,                                                                                                                                                                    // Colorize: green
    DDR2_FB_DIMM                = 20,                                                                                                                                                                    // Colorize: green
    DDR3                        = 24,                                                                                                                                                                    // Colorize: green
    FBD2                        = 25,                                                                                                                                                                    // Colorize: green
    DDR4                        = 26,                                                                                                                                                                    // Colorize: green
    LPDDR                       = 27,                                                                                                                                                                    // Colorize: green
    LPDDR2                      = 28,                                                                                                                                                                    // Colorize: green
    LPDDR3                      = 29,                                                                                                                                                                    // Colorize: green
    LPDDR4                      = 30,                                                                                                                                                                    // Colorize: green
    LOGICAL_NON_VOLATILE_DEVICE = 31,                                                                                                                                                                    // Colorize: green
    HBM                         = 32,                                                                                                                                                                    // Colorize: green
    HBM2                        = 33                                                                                                                                                                     // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiMemoryDeviceType type) // TEST: NO                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiMemoryDeviceType::NONE:                        return "NONE";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::OTHER:                       return "OTHER";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::UNKNOWN:                     return "UNKNOWN";                                                                                                                         // Colorize: green
        case DmiMemoryDeviceType::DRAM:                        return "DRAM";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::EDRAM:                       return "EDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::VRAM:                        return "VRAM";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::SRAM:                        return "SRAM";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::RAM:                         return "RAM";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::ROM:                         return "ROM";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::FLASH:                       return "FLASH";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::EERPOM:                      return "EERPOM";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::FEPROM:                      return "FEPROM";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::EPROM:                       return "EPROM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::CDRAM:                       return "CDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::_3DRAM:                      return "3DRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::SDRAM:                       return "SDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::SGRAM:                       return "SGRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::RDRAM:                       return "RDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::DDR:                         return "DDR";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::DDR2:                        return "DDR2";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::DDR2_FB_DIMM:                return "DDR2_FB_DIMM";                                                                                                                    // Colorize: green
        case DmiMemoryDeviceType::DDR3:                        return "DDR3";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::FBD2:                        return "FBD2";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::DDR4:                        return "DDR4";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::LPDDR:                       return "LPDDR";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::LPDDR2:                      return "LPDDR2";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::LPDDR3:                      return "LPDDR3";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::LPDDR4:                      return "LPDDR4";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::LOGICAL_NON_VOLATILE_DEVICE: return "LOGICAL_NON_VOLATILE_DEVICE";                                                                                                     // Colorize: green
        case DmiMemoryDeviceType::HBM:                         return "HBM";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::HBM2:                        return "HBM2";                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiMemoryDeviceType type) // TEST: NO                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[35];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToHumanString(DmiMemoryDeviceType type) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiMemoryDeviceType::NONE:                        return "None";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::OTHER:                       return "Other";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::UNKNOWN:                     return "Unknown";                                                                                                                         // Colorize: green
        case DmiMemoryDeviceType::DRAM:                        return "DRAM";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::EDRAM:                       return "EDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::VRAM:                        return "VRAM";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::SRAM:                        return "SRAM";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::RAM:                         return "RAM";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::ROM:                         return "ROM";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::FLASH:                       return "Flash";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::EERPOM:                      return "EERPOM";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::FEPROM:                      return "FEPROM";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::EPROM:                       return "EPROM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::CDRAM:                       return "CDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::_3DRAM:                      return "3DRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::SDRAM:                       return "SDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::SGRAM:                       return "SGRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::RDRAM:                       return "RDRAM";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::DDR:                         return "DDR";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::DDR2:                        return "DDR2";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::DDR2_FB_DIMM:                return "DDR2 FB-DIMM";                                                                                                                    // Colorize: green
        case DmiMemoryDeviceType::DDR3:                        return "DDR3";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::FBD2:                        return "FBD2";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::DDR4:                        return "DDR4";                                                                                                                            // Colorize: green
        case DmiMemoryDeviceType::LPDDR:                       return "LPDDR";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceType::LPDDR2:                      return "LPDDR2";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::LPDDR3:                      return "LPDDR3";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::LPDDR4:                      return "LPDDR4";                                                                                                                          // Colorize: green
        case DmiMemoryDeviceType::LOGICAL_NON_VOLATILE_DEVICE: return "Logical non-volatile device";                                                                                                     // Colorize: green
        case DmiMemoryDeviceType::HBM:                         return "HBM";                                                                                                                             // Colorize: green
        case DmiMemoryDeviceType::HBM2:                        return "HBM2";                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICETYPE_H                                                                                                                                     // Colorize: green