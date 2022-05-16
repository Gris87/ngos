#ifndef COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32ARCHCAPABILITIESFLAGS_H                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32ARCHCAPABILITIESFLAGS_H                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/flags.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/ngos/linkage.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/string/string.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
typedef good_U64 msr_ia32_arch_capabilities_flags;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class MsrIa32ArchCapabilitiesFlag: msr_ia32_arch_capabilities_flags // TODO: Validate with spec_verifier // https://cdrdv2.intel.com/v1/dl/getContent/671098                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                 = 0,                                                                                                                                                                                           // Colorize: green
    RDCL_NO              = (1ULL << 0),  // The processor is not susceptible to Rogue Data Cache Load (Meltdown)                                                                                                                                  // Colorize: green
    IBRS_ALL             = (1ULL << 1),  // The processor supports enhanced IBRS                                                                                                                                        // Colorize: green
    RSBA                 = (1ULL << 2),  // The processor supports RSB Alternate                                                                                                                                        // Colorize: green
    SKIP_L1DFL_VMENTRY   = (1ULL << 3),  // A value of 1 indicates the hypervisor need not flush the L1D on VM entry                                                                                                                                 // Colorize: green
    SSB_NO               = (1ULL << 4),  // Processor is not susceptible to Speculative Store Bypass                                                                                                        // Colorize: green
    MDS_NO               = (1ULL << 5),  // Processor is not susceptible to Microarchitectural Data Sampling                                                                                                // Colorize: green
    IF_PSCHANGE_MC_NO    = (1ULL << 6),  // The processor is not susceptible to a machine check error due to modifying the size of a code page without TLB invalidation                                  // Colorize: green
    TSX_CTRL             = (1ULL << 7),  // If 1, indicates presence of IA32_TSX_CTRL MSR                                                                                                                // Colorize: green
    TAA_NO               = (1ULL << 8),  // If 1, processor is not affected by TAA                                                                                                                       // Colorize: green
    MISC_PACKAGE_CTLS    = (1ULL << 10), // The processor supports IA32_MISC_PACKAGE_CTLS MSR                                                                                                            // Colorize: green
    ENERGY_FILTERING_CTL = (1ULL << 11), // The processor supports setting and reading the IA32_MISC_PACKAGE_CTLS[0] (ENERGY_FILTERING_ENABLE) bit                                                       // Colorize: green
    OVERCLOCKING_STATUS  = (1ULL << 23)  // If set, the IA32_OVERLOCKING STATUS MSR exists.                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(MsrIa32ArchCapabilitiesFlags, msr_ia32_arch_capabilities_flags); // TEST: NO                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(MsrIa32ArchCapabilitiesFlag flag) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case MsrIa32ArchCapabilitiesFlag::NONE: return "NONE";                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(MsrIa32ArchCapabilitiesFlag flag) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[43];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%016llX (%s)", static_cast<msr_ia32_arch_capabilities_flags>(flag), flagToString(flag));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const MsrIa32ArchCapabilitiesFlags &flags) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[184];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, MsrIa32ArchCapabilitiesFlag);                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const MsrIa32ArchCapabilitiesFlags &flags) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[191];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, MsrIa32ArchCapabilitiesFlag, "0x%016llX");                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32ARCHCAPABILITIESFLAGS_H                                                                                                                                         // Colorize: green
