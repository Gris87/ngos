#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPESELECT_H                                                                                                                      // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPESELECT_H                                                                                                                      // Colorize: green
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
enum class DmiChassisContainedElementTypeSelect: good_U8                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    BASEBOARD_TYPE = 0, // SMBIOS Baseboard Type enumeration                                                                                                                                             // Colorize: green
    DMI_ENTRY_TYPE = 1  // SMBIOS structure type enumeration                                                                                                                                             // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
// Verified with DmiSpecVerifier [END] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiChassisContainedElementTypeSelect select) // TEST: NO                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (select)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: return "BASEBOARD_TYPE";                                                                                                              // Colorize: green
        case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: return "DMI_ENTRY_TYPE";                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiChassisContainedElementTypeSelect select) // TEST: NO                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[22];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)select, enumToString(select));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPESELECT_H                                                                                                                    // Colorize: green
