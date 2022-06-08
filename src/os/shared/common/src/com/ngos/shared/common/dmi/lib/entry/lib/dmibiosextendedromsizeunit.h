#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZEUNIT_H                                                                                                                                // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZEUNIT_H                                                                                                                                // Colorize: green
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
// Verified with DmiSpecVerifier [BEGIN] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                               // Colorize: green
enum class DmiBiosExtendedRomSizeUnit: good_U16                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    MEGABYTES = 0,                                                                                                                                                                                       // Colorize: green
    GIGABYTES = 1                                                                                                                                                                                        // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
// Verified with DmiSpecVerifier [END] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const good_Char8* enumToString(DmiBiosExtendedRomSizeUnit unit) // TEST: NO                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | unit = %u", unit)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (unit)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiBiosExtendedRomSizeUnit::MEGABYTES: return "MEGABYTES";                                                                                                                                  // Colorize: green
        case DmiBiosExtendedRomSizeUnit::GIGABYTES: return "GIGABYTES";                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const good_Char8* enumToFullString(DmiBiosExtendedRomSizeUnit unit) // TEST: NO                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | unit = %u", unit)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static good_Char8 res[17];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%04X (%s)", static_cast<good_U16>(unit), enumToString(unit));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZEUNIT_H                                                                                                                              // Colorize: green
