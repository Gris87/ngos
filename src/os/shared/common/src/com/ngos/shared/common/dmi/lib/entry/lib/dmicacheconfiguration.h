#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H                                                                                                                                     // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicachelocation.h>                                                                                                                                   // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicacheoperationalmode.h>                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiCacheConfiguration                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    u16 levelReal()                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return level + 1;                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            u16                     level:           3;                                                                                                                                                  // Colorize: green
            u16                     socketed:        1;                                                                                                                                                  // Colorize: green
            u16                     __reserved:      1;                                                                                                                                                  // Colorize: green
            DmiCacheLocation        location:        2;                                                                                                                                                  // Colorize: green
            u16                     enabled:         1;                                                                                                                                                  // Colorize: green
            DmiCacheOperationalMode operationalMode: 2;                                                                                                                                                  // Colorize: green
            u16                     __reserved2:     6;                                                                                                                                                  // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        u16 value16;                                                                                                                                                                                     // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H                                                                                                                                   // Colorize: green
