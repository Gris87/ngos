#ifndef COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSREFERFLAGS_H                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSREFERFLAGS_H                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/bits/flags.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/bits/macros.h>                                                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/ngos/linkage.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/string/string.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Verified with IntelMsrSpecVerifier [BEGIN] // https://cdrdv2.intel.com/v1/dl/getContent/671098                                                                                                        // Colorize: green
typedef good_U64 msr_ia32_efer_flags;                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class MsrIa32EferFlag: msr_ia32_efer_flags                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE              = 0,                                                                                                                                                                               // Colorize: green
    SYSCALL_ENABLE    = BIT_0,  // IA32_EFER.SCE (R/W) Enables SYSCALL/SYSRET instructions in 64-bit mode.                                                                                         // Colorize: green
    LONG_MODE_ENABLE  = BIT_8,  // IA32_EFER.LME (R/W) Enables IA-32e mode operation.                                                                                                              // Colorize: green
    LONG_MODE_ACTIVE  = BIT_10, // IA32_EFER.LMA (R) Indicates IA-32e mode is active when set.                                                                                                     // Colorize: green
    NO_EXECUTE_ENABLE = BIT_11  // IA32_EFER.NXE (R/W)                                                                                                                                             // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(MsrIa32EferFlags, msr_ia32_efer_flags); // TEST: NO                                                                                                                                         // Colorize: green
// Verified with IntelMsrSpecVerifier [END] // https://cdrdv2.intel.com/v1/dl/getContent/671098                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(MsrIa32EferFlag flag) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case MsrIa32EferFlag::NONE: return "NONE";                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(MsrIa32EferFlag flag) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[43];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%016llX (%s)", static_cast<msr_ia32_efer_flags>(flag), flagToString(flag));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const MsrIa32EferFlags &flags) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[184];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, MsrIa32EferFlag);                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const MsrIa32EferFlags &flags) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[191];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, MsrIa32EferFlag, "0x%016llX");                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_MSR_LIB_REGISTERS_MSREFERFLAGS_H                                                                                                                                         // Colorize: green
