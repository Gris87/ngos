#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID0000000BEBX0_H                                                                                                                                         // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID0000000BEBX0_H                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Verified with IntelCpuidSpecVerifier [BEGIN] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                      // Colorize: green
struct Cpuid0000000BEbx0                                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U32 numberOfThreadsPerCore: 16;                                                                                                                                                         // Colorize: green
            good_U32 _reserved:              16;                                                                                                                                                         // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        good_U32 value32;                                                                                                                                                                                // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                                                       // Colorize: green
// Verified with IntelCpuidSpecVerifier [END] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID0000000BEBX0_H                                                                                                                                       // Colorize: green
