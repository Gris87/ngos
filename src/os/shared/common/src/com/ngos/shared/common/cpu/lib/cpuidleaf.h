#ifndef COM_NGOS_SHARED_COMMON_CPU_CPUIDLEAF_H                                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_CPUIDLEAF_H                                                                                                                                                           // Colorize: green
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
enum class CpuidLeaf: good_U32                                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION                = 0x00000000,                                                                                                                                 // Colorize: green
    FEATURE_INFORMATION                                    = 0x00000001,                                                                                                                                 // Colorize: green
    CACHE_DESCRIPTORS                                      = 0x00000002,                                                                                                                                 // Colorize: green
    PROCESSOR_SERIAL_NUMBER                                = 0x00000003,                                                                                                                                 // Colorize: green
    DETERMINISTIC_CACHE_PARAMETERS                         = 0x00000004,                                                                                                                                 // Colorize: green
    MONITOR_AND_MWAIT_PARAMETERS                           = 0x00000005,                                                                                                                                 // Colorize: green
    DIGITAL_THERMAL_SENSOR_AND_POWER_MANAGEMENT_PARAMETERS = 0x00000006,                                                                                                                                 // Colorize: green
    STRUCTURED_EXTENDED_FEATURE_FLAGS_ENUMERATION          = 0x00000007,                                                                                                                                 // Colorize: green
    DIRECT_CACHE_ACCESS_PARAMETERS                         = 0x00000009,                                                                                                                                 // Colorize: green
    ARCHITECTUAL_PERFORMANCE_MONITOR_FEATURES              = 0x0000000A,                                                                                                                                 // Colorize: green
    X2APIC_FEATURES_AND_PROCESSOR_TOPOLOGY                 = 0x0000000B,                                                                                                                                 // Colorize: green
    XSAVE_FEATURES                                         = 0x0000000D,                                                                                                                                 // Colorize: green
    RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING                = 0x0000000F,                                                                                                                                 // Colorize: green
    RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION                = 0x00000010,                                                                                                                                 // Colorize: green
    LARGEST_EXTENDED_FUNCTION                              = 0x80000000,                                                                                                                                 // Colorize: green
    EXTENDED_FEATURE_BITS                                  = 0x80000001,                                                                                                                                 // Colorize: green
    PROCESSOR_BRAND_STRING_1                               = 0x80000002,                                                                                                                                 // Colorize: green
    PROCESSOR_BRAND_STRING_2                               = 0x80000003,                                                                                                                                 // Colorize: green
    PROCESSOR_BRAND_STRING_3                               = 0x80000004,                                                                                                                                 // Colorize: green
    L1_CACHE_IDENTIFIERS                                   = 0x80000005,                                                                                                                                 // Colorize: green
    EXTENDED_L2_CACHE_FEATURES                             = 0x80000006,                                                                                                                                 // Colorize: green
    ADVANCED_POWER_MANAGEMENT                              = 0x80000007,                                                                                                                                 // Colorize: green
    VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES                     = 0x80000008,                                                                                                                                  // Colorize: green
    SVM_FEATURES                                           = 0x8000000A,                                                                                                                                  // Colorize: green
    ENCRYPTED_MEMORY_CAPABILITIES                          = 0x8000001F                                                                                                                                  // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(CpuidLeaf leaf) // TEST: NO                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | leaf = %u", leaf)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (leaf)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuidLeaf::VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION: return "VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION";                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(CpuidLeaf leaf) // TEST: NO                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | leaf = %u", leaf)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[50];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", static_cast<good_U32>(leaf), enumToString(leaf));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_CPUIDLEAF_H                                                                                                                                                         // Colorize: green
