#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID80000008ECX_H                                                                                                                                          // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID80000008ECX_H                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpuid/lib/cpuidperformancetscsize.h>                                                                                                                            // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Verified with AmdCpuidSpecVerifier [BEGIN] // https://www.amd.com/system/files/TechDocs/24594.pdf                                                                                                      // Colorize: green
struct Cpuid80000008Ecx                                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    inline good_U16 physicalCoresReal() const                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LT((""));                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return physicalCores + 1;                                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    inline good_U8 apicIdBitsReal() const                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LT((""));                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (apicIdBits == 0)                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return 1;                                                                                                                                                                                    // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return apicIdBits;                                                                                                                                                                               // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U32                physicalCores:      8;                                                                                                                                                // Colorize: green
            good_U32                _reserved:          4;                                                                                                                                                // Colorize: green
            good_U32                apicIdBits:         4;                                                                                                                                                // Colorize: green
            CpuidPerformanceTscSize performanceTscSize: 2;                                                                                                                                                // Colorize: green
            good_U32                _reserved2:         14;                                                                                                                                               // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        good_U32 value32;                                                                                                                                                                                // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
// Verified with AmdCpuidSpecVerifier [END] // https://www.amd.com/system/files/TechDocs/24594.pdf                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUID80000008ECX_H                                                                                                                                        // Colorize: green
