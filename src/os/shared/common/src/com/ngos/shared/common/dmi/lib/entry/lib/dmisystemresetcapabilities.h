#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H                                                                                                                                // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemresetbootoption.h>                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiSystemResetCapabilities                                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            u8                       enabled:           1;                                                                                                                                               // Colorize: green
            DmiSystemResetBootOption bootOption:        2;                                                                                                                                               // Colorize: green
            DmiSystemResetBootOption bootOptionOnLimit: 2;                                                                                                                                               // Colorize: green
            u8                       watchdogEnabled:   1;                                                                                                                                               // Colorize: green
            u8                       __reserved:        2;                                                                                                                                               // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        u8 value8;                                                                                                                                                                                       // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H                                                                                                                              // Colorize: green