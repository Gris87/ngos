#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID00000000EAX_H                                                                                                                                          // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID00000000EAX_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuidleaf.h>                                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Verified with IntelCpuidSpecVerifier [BEGIN] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                      // Colorize: green
struct Cpuid00000000Eax                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            CpuidLeaf largestFunction;                                                                                                                                                                  // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        good_U32 value32;                                                                                                                                                                                // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
// Verified with IntelCpuidSpecVerifier [END] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID00000000EAX_H                                                                                                                                        // Colorize: green
