#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H                                                                                                                      // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiprocessorstatus.h>                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiProcessorStatusAndSocketPopulated                                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            DmiProcessorStatus status:          3;                                                                                                                                                       // Colorize: green
            u8                 __reserved:      3;                                                                                                                                                       // Colorize: green
            u8                 socketPopulated: 1;                                                                                                                                                       // Colorize: green
            u8                 __reserved2:     1;                                                                                                                                                       // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        u8 value8;                                                                                                                                                                                       // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORSTATUSANDSOCKETPOPULATED_H                                                                                                                    // Colorize: green
