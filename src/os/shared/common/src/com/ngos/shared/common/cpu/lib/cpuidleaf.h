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
// TODO: Check why we didn't rebuild after change this file                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Verified with IntelCpuidSpecVerifier [BEGIN] // https://cdrdv2.intel.com/v1/dl/getContent/671199                                                                                                       // Colorize: green
// Verified with AmdCpuidSpecVerifier [BEGIN] // https://www.amd.com/system/files/TechDocs/24594.pdf                                                                                                     // Colorize: green
enum class CpuidLeaf: good_U32                                                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    VENDOR_ID_AND_LARGEST_STANDARD_FUNCTION                           = 0x00000000, // Returns CPUID's Highest Value for Basic Processor Information and the Vendor Identification String                // Colorize: green
    MODEL_AND_FEATURE_INFORMATION                                     = 0x00000001, // Returns Model, Family, Stepping Information in EAX, Returns Additional Information in EBX, Returns Feature Information in ECX and EDX // Colorize: green
    CACHE_INFORMATION                                                 = 0x00000002, // TLB/Cache/Prefetch Information Returned in EAX, EBX, ECX, EDX                                                     // Colorize: green
    PROCESSOR_SERIAL_NUMBER                                           = 0x00000003, // 96 bit processor serial number. (Available in Pentium III processor only; otherwise, the value in this register is reserved.) // Colorize: green
    DETERMINISTIC_CACHE_PARAMETERS                                    = 0x00000004, // Returns Deterministic Cache Parameters for Each Level                                                             // Colorize: green
    MONITOR_AND_MWAIT_FEATURES                                        = 0x00000005, // Returns MONITOR and MWAIT Features                                                                                // Colorize: green
    THERMAL_AND_POWER_MANAGEMENT_FEATURES                             = 0x00000006, // Returns Thermal and Power Management Features                                                                     // Colorize: green
    STRUCTURED_EXTENDED_FEATURE                                       = 0x00000007, // Returns Structured Extended Feature Enumeration Information                                                       // Colorize: green
    DIRECT_CACHE_ACCESS_INFORMATION                                   = 0x00000009, // Returns Direct Cache Access Information                                                                           // Colorize: green
    ARCHITECTUAL_PERFORMANCE_MONITORING_FEATURES                      = 0x0000000A, // Returns Architectural Performance Monitoring Features                                                             // Colorize: green
    EXTENDED_TOPOLOGY_INFORMATION                                     = 0x0000000B, // Returns Extended Topology Information                                                                             // Colorize: green
    XSAVE_FEATURES                                                    = 0x0000000D, // Returns Processor Extended States Enumeration Information                                                         // Colorize: green
    RESOURCE_DIRECTOR_TECHNOLOGY_MONITORING                           = 0x0000000F, // Returns Intel Resource Director Technology (Intel RDT) Monitoring Enumeration Information                         // Colorize: green
    RESOURCE_DIRECTOR_TECHNOLOGY_ALLOCATION                           = 0x00000010, // Returns Intel Resource Director Technology (Intel RDT) Allocation Enumeration Information                         // Colorize: green
    SGX                                                               = 0x00000012, // Returns Intel SGX Enumeration Information                                                                         // Colorize: green
    PROCESSOR_TRACE                                                   = 0x00000014, // Returns Intel Processor Trace Enumeration Information                                                             // Colorize: green
    TSC_AND_NOMINAL_CORE_CRYSTAL_CLOCK_INFORMATION                    = 0x00000015, // Returns Time Stamp Counter and Nominal Core Crystal Clock Information                                             // Colorize: green
    PROCESSOR_FREQUENCY_INFORMATION                                   = 0x00000016, // Returns Processor Frequency Information                                                                           // Colorize: green
    SYSTEM_ON_CHIP_INFORMATION                                        = 0x00000017, // Returns System-On-Chip Information                                                                                // Colorize: green
    DETERMINISTIC_ADDRESS_TRANSLATION_PARAMETERS_INFORMATION          = 0x00000018, // Returns Deterministic Address Translation Parameters Information                                                  // Colorize: green
    KEY_LOCKER_INFORMATION                                            = 0x00000019, // Returns Key Locker Information                                                                                    // Colorize: green
    HYBRID_INFORMATION                                                = 0x0000001A, // Returns Hybrid Information                                                                                        // Colorize: green
    PCONFIG_INFORMATION                                               = 0x0000001B, // Returns PCONFIG Information                                                                                       // Colorize: green
    LAST_BRANCH_RECORD_INFORMATION                                    = 0x0000001C, // Returns Last Branch Record Information                                                                            // Colorize: green
    V2_EXTENDED_TOPOLOGY_INFORMATION                                  = 0x0000001F, // Returns V2 Extended Topology Information                                                                          // Colorize: green
    HISTORY_RESET_INFORMATION                                         = 0x00000020, // Returns History Reset Information                                                                                 // Colorize: green
    MAXIMUM_EXTENDED_FUNCTION_NUMBER_AND_VENDOR_STRING                = 0x80000000, // This function provides information about the maximum extended function number supported on this processor and a string that identifies the vendor of the product. // Colorize: green
    EXTENDED_PROCESSOR_AND_PROCESSOR_FEATURE_IDENTIFIERS              = 0x80000001, // Returns Model, Family, Stepping Information in EAX, Returns Additional Information in EBX, Returns Feature Information in ECX and EDX // Colorize: green
    PROCESSOR_BRAND_STRING_1                                          = 0x80000002, // The three extended functions from Fn8000_0002 to Fn8000_0004 are programmed to return a null terminated ASCII string up to 48 characters in length corresponding to the processor name. // Colorize: green
    PROCESSOR_BRAND_STRING_2                                          = 0x80000003, // The three extended functions from Fn8000_0002 to Fn8000_0004 are programmed to return a null terminated ASCII string up to 48 characters in length corresponding to the processor name. // Colorize: green
    PROCESSOR_BRAND_STRING_3                                          = 0x80000004, // The three extended functions from Fn8000_0002 to Fn8000_0004 are programmed to return a null terminated ASCII string up to 48 characters in length corresponding to the processor name. // Colorize: green
    L1_CACHE_AND_TLB_INFORMATION                                      = 0x80000005, // This function provides first level cache TLB characteristics for the processor that executes the instruction.     // Colorize: green
    L2_CACHE_AND_TLB_AND_L3_CACHE_INFORMATION                         = 0x80000006, // This function provides the second level cache and TLB characteristics for the logical processor that executes the instruction. The EDX register returns the processor’s third level cache characteristics that are shared by all logical processors in the package. // Colorize: green
    PROCESSOR_POWER_MANAGEMENT_AND_RAS_CAPABILITIES                   = 0x80000007, // This function provides information about the power management, power reporting, and RAS capabilities of the processor that executes the instruction.There may be other processor-specific features and reporting capabilities not covered here. Refer to the BIOS and Kernel Developer’s Guide for your specific product to otain more information. // Colorize: green
    PROCESSOR_CAPACITY_PARAMETERS_AND_EXTENDED_FEATURE_IDENTIFICATION = 0x80000008, // This function provides the size or capacity of various architectural parameters that vary by implementation, as well as an extension to the Fn8000_0001 feature identifiers. // Colorize: green
    SVM_FEATURES                                                      = 0x8000000A, // This function provides information about the SVM features that the processory supports. If SVM is not supported (CPUID Fn8000_0001_ECX[SVM] = 0), this function is reserved. // Colorize: green
    TLB_CHARACTERISTICS_FOR_1GB_PAGES                                 = 0x80000019, // This function provides information about the TLB for 1 GB pages for the processor that executes the instruction.  // Colorize: green
    INSTRUCTION_OPTIMIZATIONS                                         = 0x8000001A, // Instruction Optimizations                                                                                         // Colorize: green
    INSTRUCTION_BASED_SAMPLING_CAPABILITIES                           = 0x8000001B, // If instruction-based sampling (IBS) is supported (CPUID Fn8000_0001_ECX[IBS] = 1), this CPUID function can be used to obtain IBS feature information. If IBS is not supported (CPUID Fn8000_0001_ECX[IBS] = 0), this function number is reserved. For more information on using IBS, see “Instruction-Based Sampling” in APM2. // Colorize: green
    LIGHTWEIGHT_PROFILING_CAPABILITIES                                = 0x8000001C, // If lightweight profilling (LWP) is supported (CPUID Fn8000_0001_ECX[LWP] = 1), this CPUID function can be used to obtain information about LWP features supported by the processor. If LWP is not supported (CPUID Fn8000_0001_ECX[LWP] = 0), this function number is reserved. For more information on using LWP, see “Lightweight Profiling” in APM2. // Colorize: green
    CACHE_TOPOLOGY_INFORMATION                                        = 0x8000001D, // CPUID Fn8000_001D_E[D,C,B,A]X reports cache topology information for the cache enumerated by the value passed to the instruction in ECX, referred to as Cache n in the following description. To gather information for all cache levels, software must repeatedly execute CPUID with 8000_001Dh in EAX and ECX set to increasing values beginning with 0 until a value of 00h is returned in the field CacheType (EAX[4:0]) indicating no more cache descriptions are available for this processor. // Colorize: green
    PROCESSOR_TOPOLOGY_INFORMATION                                    = 0x8000001E, // Processor Topology Information                                                                                    // Colorize: green
    ENCRYPTED_MEMORY_CAPABILITIES                                     = 0x8000001F, // Encrypted Memory Capabilities                                                                                     // Colorize: green
    EXTENDED_FEATURE_IDENTIFICATION_2                                 = 0x80000021  // Extended Feature Identification 2                                                                                 // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
// Verified with AmdCpuidSpecVerifier [END] // https://www.amd.com/system/files/TechDocs/24594.pdf                                                                                                       // Colorize: green
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
