#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_REGISTERS_X86CR4FLAGS_H                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_LIB_REGISTERS_X86CR4FLAGS_H                                                                                                                                           // Colorize: green
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
// Verified with X86RegistersSpecVerifier [BEGIN] // https://cdrdv2.intel.com/v1/dl/getContent/671190                                                                                                    // Colorize: green
typedef good_U64 x86_cr4_flags;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class X86Cr4Flag: x86_cr4_flags                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                                             = 0,                                                                                                                                                // Colorize: green
    VIRTUAL_8086_MODE_EXTENSIONS                     = BIT_0,  // Enables interrupt- and exception-handling extensions in virtual-8086 mode when set; disables the extensions when clear           // Colorize: green
    PROTECTED_MODE_VIRTUAL_INTERRUPTS                = BIT_1,  // Enables hardware support for a virtual interrupt flag (VIF) in protected mode when set; disables the VIF flag in protected mode when clear // Colorize: green
    TIME_STAMP_DISABLE                               = BIT_2,  // Restricts the execution of the RDTSC instruction to procedures running at privilege level 0 when set; allows RDTSC instruction to be executed at any privilege level when clear // Colorize: green
    DEBUGGING_EXTENSIONS                             = BIT_3,  // References to debug registers DR4 and DR5 cause an undefined opcode (#UD) exception to be generated when set; when clear, processor aliases references to registers DR4 and DR5 for compatibility with software written to run on earlier IA-32 processors // Colorize: green
    PAGE_SIZE_EXTENSIONS                             = BIT_4,  // Enables 4-MByte pages with 32-bit paging when set; restricts 32-bit paging to pages of 4 KBytes when clear                       // Colorize: green
    PHYSICAL_ADDRESS_EXTENSION                       = BIT_5,  // When set, enables paging to produce physical addresses with more than 32 bits                                                    // Colorize: green
    MACHINE_CHECK_ENABLE                             = BIT_6,  // Enables the machine-check exception when set; disables the machine-check exception when clear                                    // Colorize: green
    PAGE_GLOBAL_ENABLE                               = BIT_7,  // (Introduced in the P6 family processors                                                                                          // Colorize: green
    PERFORMANCE_MONITORING_COUNTER_ENABLE            = BIT_8,  // Enables execution of the RDPMC instruction for programs or procedures running at any protection level when set; RDPMC instruction can be executed only at protection level 0 when clear // Colorize: green
    SUPPORT_FXSAVE                                   = BIT_9,  // When set, this flag: (1) indicates to software that the operating system supports the use of the FXSAVE and FXRSTOR instructions, (2) enables the FXSAVE and FXRSTOR instructions to save and restore the contents of the XMM and MXCSR registers along with the contents of the x87 FPU and MMX registers, and (3) enables the processor to execute SSE/SSE2/SSE3/SSSE3/SSE4 instructions, with the exception of the PAUSE, PREFETCHh, SFENCE, LFENCE, MFENCE, MOVNTI, CLFLUSH, CRC32, and POPCNT // Colorize: green
    SUPPORT_UNMASKED_SSE_EXCEPTIONS                  = BIT_10, // When set, indicates that the operating system supports the handling of unmasked SIMD floating-point exceptions through an exception handler that is invoked when a SIMD floating-point exception (#XM) is generated // Colorize: green
    USER_MODE_INSTRUCTION_PREVENTION                 = BIT_11, // When set, the following instructions cannot be executed if CPL > 0: SGDT, SIDT, SLDT, SMSW, and STR                              // Colorize: green
    _57_BIT_LINEAR_ADDRESSES                         = BIT_12, // When set in IA-32e mode, the processor uses 5-level paging to translate 57-bit linear addresses                                  // Colorize: green
    VIRTUAL_MACHINE_EXTENSIONS_ENABLE                = BIT_13, // Enables VMX operation when set                                                                                                   // Colorize: green
    SAFER_MODE_EXTENSIONS_ENABLE                     = BIT_14, // Enables SMX operation when set                                                                                                   // Colorize: green
    FSGSBASE                                         = BIT_16, // Enables the instructions RDFSBASE, RDGSBASE, WRFSBASE, and WRGSBASE                                                              // Colorize: green
    PROCESS_CONTEXT_ID_ENABLE                        = BIT_17, // Enables process-context identifiers (PCIDs) when set                                                                             // Colorize: green
    SUPPORT_XSAVE                                    = BIT_18, // When set, this flag: (1) indicates (via CPUID                                                                                    // Colorize: green
    KEY_LOCKER_ENABLE_BIT                            = BIT_19, // When set, the LOADIWKEY instruction is enabled; in addition, if support for the AES Key Locker instructions has been activated by system firmware, CPUID // Colorize: green
    SUPERVISOR_MODE_EXECUTION_PROTECTION_ENABLE      = BIT_20, // Enables supervisor-mode execution prevention (SMEP) when set                                                                     // Colorize: green
    SUPERVISOR_MODE_ACCESS_PROTECTION_ENABLE         = BIT_21, // Enables supervisor-mode access prevention (SMAP) when set                                                                        // Colorize: green
    ENABLE_PROTECTION_KEYS_FOR_USER_MODE_PAGES       = BIT_22, // 4-level paging and 5-level paging associate each user-mode linear address with a protection key                                  // Colorize: green
    CONTROL_FLOW_ENFORCEMENT_TECHNOLOGY              = BIT_23, // Enables control-flow enforcement technology when set                                                                             // Colorize: green
    ENABLE_PROTECTION_KEYS_FOR_SUPERVISOR_MODE_PAGES = BIT_24  // 4-level paging and 5-level paging associate each supervisor-mode linear address with a protection key                            // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(X86Cr4Flags, x86_cr4_flags); // TEST: NO                                                                                                                                                    // Colorize: green
// Verified with X86RegistersSpecVerifier [END] // https://cdrdv2.intel.com/v1/dl/getContent/671190                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(X86Cr4Flag flag) // TEST: NO                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case X86Cr4Flag::NONE: return "NONE";                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(X86Cr4Flag flag) // TEST: NO                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[43];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", static_cast<x86_cr4_flags>(flag), flagToString(flag));                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const X86Cr4Flags &flags) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[184];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, X86Cr4Flag);                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const X86Cr4Flags &flags) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[191];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, X86Cr4Flag, "0x%016llX");                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_REGISTERS_X86CR4FLAGS_H                                                                                                                                         // Colorize: green
