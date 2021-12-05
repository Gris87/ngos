#ifndef COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_PEOPTHEADERSUBSYSTEM_H                                                                                                                                     // Colorize: green
#define COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_PEOPTHEADERSUBSYSTEM_H                                                                                                                                     // Colorize: green
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
enum class PEOptHeaderSubsystem: quint16                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    UNKNOWN                  = 0,      // Unknown subsystem                                                                                                                                              // Colorize: green
    NATIVE                   = 0x0001, // No subsystem required (device drivers and native system processes)                                                                                             // Colorize: green
    WINDOWS_GUI              = 0x0002, // Windows graphical user interface (GUI) subsystem                                                                                                               // Colorize: green
    WINDOWS_CUI              = 0x0003, // Windows character-mode user interface (CUI) subsystem                                                                                                          // Colorize: green
    OS2_CUI                  = 0x0005, // OS/2 CUI subsystem                                                                                                                                             // Colorize: green
    POSIX_CUI                = 0x0007, // POSIX CUI subsystem                                                                                                                                            // Colorize: green
    WINDOWS_CE_GUI           = 0x0009, // Windows CE system                                                                                                                                              // Colorize: green
    UEFI_APPLICATION         = 0x000A, // Unified Extensible Firmware Interface (UEFI) application                                                                                                       // Colorize: green
    UEFI_BOOT_SERVICE_DRIVER = 0x000B, // UEFI driver with boot services                                                                                                                                 // Colorize: green
    UEFI_RUNTIME_DRIVER      = 0x000C, // UEFI driver with run-time services                                                                                                                             // Colorize: green
    UEFI_ROM                 = 0x000D, // UEFI ROM image                                                                                                                                                 // Colorize: green
    XBOX                     = 0x000E, // XBOX system                                                                                                                                                    // Colorize: green
    WINDOWS_BOOT_APPLICATION = 0x0010  // Boot application                                                                                                                                               // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(PEOptHeaderSubsystem machine) // TEST: NO                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    switch (machine)                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case PEOptHeaderSubsystem::UNKNOWN:   return "UNKNOWN";                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(PEOptHeaderSubsystem machine) // TEST: NO                                                                                                                           // Colorize: green
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
#endif // COM_NGOS_DEVTOOLS_IMAGE_BUILDER_OTHER_PEOPTHEADERSUBSYSTEM_H                                                                                                                                   // Colorize: green