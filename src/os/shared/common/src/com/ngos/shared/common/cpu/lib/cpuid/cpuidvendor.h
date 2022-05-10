#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUIDVENDOR_H                                                                                                                                               // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUIDVENDOR_H                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VENDOR_INTEL_1 0x756E6547   // Genu                                                                                                                                                              // Colorize: green
#define VENDOR_INTEL_2 0x49656E69   // ineI                                                                                                                                                              // Colorize: green
#define VENDOR_INTEL_3 0x6C65746E   // ntel                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define VENDOR_AMD_1   0x68747541   // Auth                                                                                                                                                              // Colorize: green
#define VENDOR_AMD_2   0x69746E65   // enti                                                                                                                                                              // Colorize: green
#define VENDOR_AMD_3   0x444D4163   // cAMD                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct CpuidVendor // TODO: Validate with spec_verifier                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    bool isIntel() const                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LT((""));                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return uints[0] == VENDOR_INTEL_1                                                                                                                                                                // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                uints[1] == VENDOR_INTEL_2                                                                                                                                                               // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                uints[2] == VENDOR_INTEL_3;                                                                                                                                                              // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    bool isAMD() const                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        COMMON_LT((""));                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return uints[0] == VENDOR_AMD_1                                                                                                                                                                  // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                uints[1] == VENDOR_AMD_2                                                                                                                                                                 // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                uints[2] == VENDOR_AMD_3;                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_U32 uints[3];                                                                                                                                                                           // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        good_Char8 chars[12];                                                                                                                                                                            // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_CPUID_CPUIDVENDOR_H                                                                                                                                             // Colorize: green
