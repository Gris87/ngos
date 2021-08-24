#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_COFFHEADERMACHINE_H                                                                                                                                                  // Colorize: green
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_COFFHEADERMACHINE_H                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <Qt>                                                                                                                                                                                            // Colorize: green
#include <stdio.h>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class COFFHeaderMachine: quint16                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    INTEL_386                           = 0x014C,                                                                                                                                                        // Colorize: green
    X64                                 = 0x8664,                                                                                                                                                        // Colorize: green
    MIPS_R3000                          = 0x0162,                                                                                                                                                        // Colorize: green
    MIPS_R10000                         = 0x0168,                                                                                                                                                        // Colorize: green
    MIPS_LITTLE_ENDIAN_WCI_V2           = 0x0169,                                                                                                                                                        // Colorize: green
    OLD_ALPHA_AXP                       = 0x0183,                                                                                                                                                        // Colorize: green
    ALPHA_AXP                           = 0x0184,                                                                                                                                                        // Colorize: green
    HITACHI_SH3                         = 0x01A2,                                                                                                                                                        // Colorize: green
    HITACHI_SH3_DSP                     = 0x01A3,                                                                                                                                                        // Colorize: green
    HITACHI_SH4                         = 0x01A6,                                                                                                                                                        // Colorize: green
    HITACHI_SH5                         = 0x01A8,                                                                                                                                                        // Colorize: green
    ARM_LITTLE_ENDIAN                   = 0x01C0,                                                                                                                                                        // Colorize: green
    THUMB                               = 0x01C2,                                                                                                                                                        // Colorize: green
    ARMV7                               = 0x01C4,                                                                                                                                                        // Colorize: green
    MATSUSHITA_AM33                     = 0x01D3,                                                                                                                                                        // Colorize: green
    POWERPC_LITTLE_ENDIAN               = 0x01F0,                                                                                                                                                        // Colorize: green
    POWERPC_WITH_FLOATING_POINT_SUPPORT = 0x01F1,                                                                                                                                                        // Colorize: green
    INTEL_IA64                          = 0x0200,                                                                                                                                                        // Colorize: green
    MIPS16                              = 0x0266,                                                                                                                                                        // Colorize: green
    MOTOROLA_68000_SERIES               = 0x0268,                                                                                                                                                        // Colorize: green
    ALPHA_AXP_64_BIT                    = 0x0284,                                                                                                                                                        // Colorize: green
    MIPS_WITH_FPU                       = 0x0366,                                                                                                                                                        // Colorize: green
    MIPS16_WITH_FPU                     = 0x0466,                                                                                                                                                        // Colorize: green
    UEFI_BYTE_CODE                      = 0x0EBC,                                                                                                                                                        // Colorize: green
    AMD_AMD64                           = 0x8664,                                                                                                                                                        // Colorize: green
    MITSUBISHI_M32R_LITTLE_ENDIAN       = 0x9041,                                                                                                                                                        // Colorize: green
    ARM64_LITTLE_ENDIAN                 = 0xAA64,                                                                                                                                                        // Colorize: green
    CLR_PURE_MSIL                       = 0xC0EE                                                                                                                                                         // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(COFFHeaderMachine machine) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    switch (machine)                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case COFFHeaderMachine::INTEL_386:   return "INTEL_386";                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(COFFHeaderMachine machine) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    static char8 res[22];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%04X (%s)", (quint16)machine, enumToString(machine));                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_COFFHEADERMACHINE_H                                                                                                                                                // Colorize: green
