#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID80000008EAX_H                                                                                                                                          // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID80000008EAX_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct Cpuid80000008Eax // TODO: Validate with spec_verifier                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U32 physicalAddressBits:      8;                                                                                                                                                             // Colorize: green
            good_U32 virtualAddressBits:       8;                                                                                                                                                             // Colorize: green
            good_U32 guestPhysicalAddressBits: 8;                                                                                                                                                             // Colorize: green
            good_U32 _reserved:                8;                                                                                                                                                            // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        good_U32 value32;                                                                                                                                                                                // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID80000008EAX_H                                                                                                                                        // Colorize: green
