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
// Verified with IntelCpuidSpecVerifier [BEGIN] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                      // Colorize: green
enum class CpuidLeaf: good_U32                                                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION                  = 0x00000000, // Returns CPUID's Highest Value for Basic Processor Information and the Vendor Identification String                         // Colorize: green
    MODEL_AND_FEATURE_INFORMATION                            = 0x00000001, // Returns Model, Family, Stepping Information in EAX, Returns Additional Information in EBX, Returns Feature Information in ECX and EDX // Colorize: green
    CACHE_INFORMATION                                        = 0x00000002, // TLB/Cache/Prefetch Information Returned in EAX, EBX, ECX, EDX                                                              // Colorize: green
    PROCESSOR_SERIAL_NUMBER                                  = 0x00000003, // 96 bit processor serial number. (Available in Pentium III processor only; otherwise, the value in this register is reserved.) // Colorize: green
    DETERMINISTIC_CACHE_PARAMETERS                           = 0x00000004, // Returns Deterministic Cache Parameters for Each Level                                                                      // Colorize: green
    MONITOR_AND_MWAIT_FEATURES                               = 0x00000005, // Returns MONITOR and MWAIT Features                                                                                         // Colorize: green
    THERMAL_AND_POWER_MANAGEMENT_FEATURES                    = 0x00000006, // Returns Thermal and Power Management Features                                                                              // Colorize: green
    STRUCTURED_EXTENDED_FEATURE                              = 0x00000007, // Returns Structured Extended Feature Enumeration Information                                                                // Colorize: green
    DIRECT_CACHE_ACCESS_INFORMATION                          = 0x00000009, // Returns Direct Cache Access Information                                                                                    // Colorize: green
    ARCHITECTUAL_PERFORMANCE_MONITORING_FEATURES             = 0x0000000A, // Returns Architectural Performance Monitoring Features                                                                      // Colorize: green
    EXTENDED_TOPOLOGY_INFORMATION                            = 0x0000000B, // Returns Extended Topology Information                                                                                      // Colorize: green
    XSAVE_FEATURES                                           = 0x0000000D, // Returns Processor Extended States Enumeration Information                                                                  // Colorize: green
    RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING                  = 0x0000000F, // Returns Intel Resource Director Technology (Intel RDT) Monitoring Enumeration Information                                  // Colorize: green
    RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION                  = 0x00000010, // Returns Intel Resource Director Technology (Intel RDT) Allocation Enumeration Information                                  // Colorize: green
    SGX                                                      = 0x00000012, // Returns Intel SGX Enumeration Information                                                                                  // Colorize: green
    PROCESSOR_TRACE                                          = 0x00000014, // Returns Intel Processor Trace Enumeration Information                                                                      // Colorize: green
    TSC_AND_NOMINAL_CORE_CRYSTAL_CLOCK_INFORMATION           = 0x00000015, // Returns Time Stamp Counter and Nominal Core Crystal Clock Information                                                      // Colorize: green
    PROCESSOR_FREQUENCY_INFORMATION                          = 0x00000016, // Returns Processor Frequency Information                                                                                    // Colorize: green
    SYSTEM_ON_CHIP_INFORMATION                               = 0x00000017, // Returns System-On-Chip Information                                                                                         // Colorize: green
    DETERMINISTIC_ADDRESS_TRANSLATION_PARAMETERS_INFORMATION = 0x00000018, // Returns Deterministic Address Translation Parameters Information                                                           // Colorize: green
    KEY_LOCKER_INFORMATION                                   = 0x00000019, // Returns Key Locker Information                                                                                             // Colorize: green
    HYBRID_INFORMATION                                       = 0x0000001A, // Returns Hybrid Information                                                                                                 // Colorize: green
    PCONFIG_INFORMATION                                      = 0x0000001B, // Returns PCONFIG Information                                                                                                // Colorize: green
    LAST_BRANCH_RECORD_INFORMATION                           = 0x0000001C, // Returns Last Branch Record Information                                                                                     // Colorize: green
    V2_EXTENDED_TOPOLOGY_INFORMATION                         = 0x0000001F, // Returns V2 Extended Topology Information                                                                                   // Colorize: green
    HISTORY_RESET_INFORMATION                                = 0x00000020, // Returns History Reset Information                                                                                          // Colorize: green
    LARGEST_EXTENDED_FUNCTION                                = 0x80000000,                                                                                                                               // Colorize: green
    EXTENDED_FEATURE_BITS                                    = 0x80000001,                                                                                                                               // Colorize: green
    PROCESSOR_BRAND_STRING_1                                 = 0x80000002,                                                                                                                               // Colorize: green
    PROCESSOR_BRAND_STRING_2                                 = 0x80000003,                                                                                                                               // Colorize: green
    PROCESSOR_BRAND_STRING_3                                 = 0x80000004,                                                                                                                               // Colorize: green
    L1_CACHE_IDENTIFIERS                                     = 0x80000005,                                                                                                                               // Colorize: green
    EXTENDED_L2_CACHE_FEATURES                               = 0x80000006,                                                                                                                               // Colorize: green
    ADVANCED_POWER_MANAGEMENT                                = 0x80000007,                                                                                                                               // Colorize: green
    VIRTUAL_AND_PHYSICAL_ADDRESS_SIZES                       = 0x80000008,                                                                                                                               // Colorize: green
    SVM_FEATURES                                             = 0x8000000A,                                                                                                                               // Colorize: green
    ENCRYPTED_MEMORY_CAPABILITIES                            = 0x8000001F                                                                                                                                // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
// Verified with IntelCpuidSpecVerifier [END] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                        // Colorize: green
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
