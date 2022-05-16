#ifndef COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32MISCENABLEFLAGS_H                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32MISCENABLEFLAGS_H                                                                                                                                           // Colorize: green
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
typedef good_U64 msr_ia32_misc_enable_flags;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class MsrIa32MiscEnableFlag: msr_ia32_misc_enable_flags // TODO: Validate with spec_verifier // https://cdrdv2.intel.com/v1/dl/getContent/671098                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                                       = 0,                                                                                                                                                      // Colorize: green
    FAST_STRINGS                               = (1ULL << 0),  // Fast-Strings Enable                                                                                                                    // Colorize: green
    AUTOMATIC_THERMAL_CONTROL_CIRCUIT          = (1ULL << 3),  // Automatic Thermal Control Circuit Enable (R/W)                                                                                         // Colorize: green
    PERFORMANCE_MONITORING                     = (1ULL << 7),  // Performance Monitoring Available (R)                                                                                                   // Colorize: green
    BRANCH_TRACE_STORAGE_UNAVAILABLE           = (1ULL << 11), // Branch Trace Storage Unavailable (R/O)                                                                                                 // Colorize: green
    PROCESSOR_EVENT_BASED_SAMPLING_UNAVAILABLE = (1ULL << 12), // Processor Event Based Sampling Unavailable (R/O)                                                                                       // Colorize: green
    ENHANCED_INTEL_SPEEDSTEP_TECHNOLOGY        = (1ULL << 16), // Enhanced Intel SpeedStep Technology Enable (R/W)                                                                                       // Colorize: green
    MWAIT                                      = (1ULL << 18), // ENABLE MONITOR FSM (R/W)                                                                                                               // Colorize: green
    LIMIT_CPUID                                = (1ULL << 22), // Limit CPUID Maxval (R/W)                                                                                                               // Colorize: green
    XTPR_DISABLE                               = (1ULL << 23), // xTPR Message Disable (R/W)                                                                                                             // Colorize: green
    XD_DISABLE                                 = (1ULL << 34)  // XD Bit Disable (R/W)                                                                                                                   // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(MsrIa32MiscEnableFlags, msr_ia32_misc_enable_flags); // TEST: NO                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(MsrIa32MiscEnableFlag flag) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case MsrIa32MiscEnableFlag::NONE: return "NONE";                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(MsrIa32MiscEnableFlag flag) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[43];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%016llX (%s)", static_cast<msr_ia32_misc_enable_flags>(flag), flagToString(flag));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const MsrIa32MiscEnableFlags &flags) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[184];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, MsrIa32MiscEnableFlag);                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const MsrIa32MiscEnableFlags &flags) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[191];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, MsrIa32MiscEnableFlag, "0x%016llX");                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSRIA32MISCENABLEFLAGS_H                                                                                                                                         // Colorize: green
