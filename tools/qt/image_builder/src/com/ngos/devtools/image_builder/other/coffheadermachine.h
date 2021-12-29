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
{
    UNKNOWN                             = 0,
    MATSUSHITA_AM33                     = 0x01D3,
    X64                                 = 0x8664,
    ARM                                 = 0x01C0,
    ARM64                               = 0xAA64,
    ARMV7                               = 0x01C4,
    UEFI_BYTE_CODE                      = 0x0EBC,
    INTEL_386                           = 0x014C,
    INTEL_IA64                          = 0x0200,
    LOONG_ARCH32                        = 0x6232,
    LOONG_ARCH64                        = 0x6264,
    MITSUBISHI_M32R                     = 0x9041,
    MIPS16                              = 0x0266,
    MIPS_WITH_FPU                       = 0x0366,
    MIPS16_WITH_FPU                     = 0x0466,
    POWERPC                             = 0x01F0,
    POWERPC_WITH_FLOATING_POINT_SUPPORT = 0x01F1,
    MIPS_R4000                          = 0x0166,
    RISC_V32                            = 0x5032,
    RISC_V64                            = 0x5064,
    RISC_V128                           = 0x5128,
    HITACHI_SH3                         = 0x01A2,
    HITACHI_SH3_DSP                     = 0x01A3,
    HITACHI_SH4                         = 0x01A6,
    HITACHI_SH5                         = 0x01A8,
    THUMB                               = 0x01C2,
    MIPS_WCE_V2                         = 0x0169,
    MIPS_R3000                          = 0x0162,
    MIPS_R10000                         = 0x0168,
    OLD_ALPHA_AXP                       = 0x0183,
    ALPHA_AXP                           = 0x0184,
    ALPHA_AXP_64_BIT                    = 0x0284,
    MOTOROLA_68000_SERIES               = 0x0268,
    CLR_PURE_MSIL                       = 0xC0EE
};
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
