#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_REGISTERS_X86CR0FLAGS_H                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_REGISTERS_X86CR0FLAGS_H                                                                                                                                           // Colorize: green
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
typedef good_U32 x86_cr0_flags;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class X86Cr0Flag: x86_cr0_flags // TODO: Validate with spec_verifier                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                  = 0,                                                                                                                                                                           // Colorize: green
    PROTECTED_MODE_ENABLE = (1ULL << 0),  // If 1, system is in protected mode, else system is in real mode                                                                                              // Colorize: green
    MONITOR_CO_PROCESSOR  = (1ULL << 1),  // Controls interaction of WAIT/FWAIT instructions with TS flag in CR0                                                                                         // Colorize: green
    EMULATION             = (1ULL << 2),  // If set, no x87 floating-point unit present, if clear, x87 FPU present                                                                                       // Colorize: green
    TASK_SWITCHED         = (1ULL << 3),  // Allows saving x87 task context upon a task switch only after x87 instruction used                                                                           // Colorize: green
    EXTENSION_TYPE        = (1ULL << 4),  // On the 386, it allowed to specify whether the external math coprocessor was an 80287 or 80387                                                               // Colorize: green
    NUMERIC_ERROR         = (1ULL << 5),  // Enable internal x87 floating point error reporting when set, else enables PC style x87 error detection                                                      // Colorize: green
    WRITE_PROTECT         = (1ULL << 16), // When set, the CPU can't write to read-only pages when privilege level is 0                                                                                  // Colorize: green
    ALIGNMENT_MASK        = (1ULL << 18), // Alignment check enabled if AM set, AC flag (in EFLAGS register) set, and privilege level is 3                                                               // Colorize: green
    NOT_WRITE_THROUGH     = (1ULL << 29), // Globally enables/disable write-through caching                                                                                                              // Colorize: green
    CACHE_DISABLE         = (1ULL << 30), // Globally enables/disable the memory cache                                                                                                                   // Colorize: green
    PAGING                = (1ULL << 31)  // If 1, enable paging and use the § CR3 register, else disable paging.                                                                                        // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(X86Cr0Flags, x86_cr0_flags); // TEST: NO                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(X86Cr0Flag flag) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case X86Cr0Flag::NONE: return "NONE";                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(X86Cr0Flag flag) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[43];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", static_cast<x86_cr0_flags>(flag), flagToString(flag));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const X86Cr0Flags &flags) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[184];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, X86Cr0Flag);                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const X86Cr0Flags &flags) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[191];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, X86Cr0Flag, "0x%08X");                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_REGISTERS_X86CR0FLAGS_H                                                                                                                                         // Colorize: green
