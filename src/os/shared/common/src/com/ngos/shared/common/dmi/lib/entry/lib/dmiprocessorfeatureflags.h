#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORFEATUREFLAGS_H                                                                                                                                  // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORFEATUREFLAGS_H                                                                                                                                  // Colorize: green
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
// Verified with DmiSpecVerifier [BEGIN] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                               // Colorize: green
typedef good_U32 dmi_processor_feature_flags;                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class DmiProcessorFeatureFlag: dmi_processor_feature_flags                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE   = 0,                                                                                                                                                                                       // Colorize: green
    FPU    = BIT_0,  // Floating Point Unit On-Chip. The processor contains an x87 FPU.                                                   // Colorize: green
    VME    = BIT_1,  // Virtual 8086 Mode Enhancements. Virtual 8086 mode enhancements, including CR4.VME for controlling the feature, CR4.PVI for protected mode virtual interrupts, software interrupt indirection, expansion of the TSS with the software indirection bitmap, and EFLAGS.VIF and EFLAGS.VIP flags. // Colorize: green
    DE     = BIT_2,  // Debugging Extensions. Support for I/O breakpoints, including CR4.DE for controlling the feature, and optional trapping of accesses to DR4 and DR5. // Colorize: green
    PSE    = BIT_3,  // Page Size Extension. Large pages of size 4 MByte are supported, including CR4.PSE for controlling the feature, the defined dirty bit in PDE (Page Directory Entries), optional reserved bit trapping in CR3, PDEs, and PTEs. // Colorize: green
    TSC    = BIT_4,  // Time Stamp Counter. The RDTSC instruction is supported, including CR4.TSD for controlling privilege.              // Colorize: green
    MSR    = BIT_5,  // Model Specific Registers RDMSR and WRMSR Instructions. The RDMSR and WRMSR instructions are supported. Some of the MSRs are implementation dependent. // Colorize: green
    PAE    = BIT_6,  // Physical Address Extension. Physical addresses greater than 32 bits are supported: extended page table entry formats, an extra level in the page translation tables is defined, 2-MByte pages are supported instead of 4 Mbyte pages if PAE bit is 1. // Colorize: green
    MCE    = BIT_7,  // Machine Check Exception. Exception 18 is defined for Machine Checks, including CR4.MCE for controlling the feature. This feature does not define the model-specific implementations of machine-check error logging, reporting, and processor shutdowns. Machine Check exception handlers may have to depend on processor version to do model specific processing of the exception, or test for the presence of the Machine Check feature. // Colorize: green
    CX8    = BIT_8,  // CMPXCHG8B Instruction. The compare-and-exchange 8 bytes (64 bits) instruction is supported (implicitly locked and atomic). // Colorize: green
    APIC   = BIT_9,  // APIC On-Chip. The processor contains an Advanced Programmable Interrupt Controller (APIC), responding to memory mapped commands in the physical address range FFFE0000H to FFFE0FFFH (by default - some processors permit the APIC to be relocated). // Colorize: green
    SEP    = BIT_11, // SYSENTER and SYSEXIT Instructions. The SYSENTER and SYSEXIT and associated MSRs are supported.                    // Colorize: green
    MTRR   = BIT_12, // Memory Type Range Registers. MTRRs are supported. The MTRRcap MSR contains feature bits that describe what memory types are supported, how many variable MTRRs are supported, and whether fixed MTRRs are supported. // Colorize: green
    PGE    = BIT_13, // Page Global Bit. The global bit is supported in paging-structure entries that map a page, indicating TLB entries that are common to different processes and need not be flushed. The CR4.PGE bit controls this feature. // Colorize: green
    MCA    = BIT_14, // Machine Check Architecture. A value of 1 indicates the Machine Check Architecture of reporting machine errors is supported. The MCG_CAP MSR contains feature bits describing how many banks of error reporting MSRs are supported. // Colorize: green
    CMOV   = BIT_15, // Conditional Move Instructions. The conditional move instruction CMOV is supported. In addition, if x87 FPU is present as indicated by the CPUID.FPU feature bit, then the FCOMI and FCMOV instructions are supported // Colorize: green
    PAT    = BIT_16, // Page Attribute Table. Page Attribute Table is supported. This feature augments the Memory Type Range Registers (MTRRs), allowing an operating system to specify attributes of memory accessed through a linear address on a 4KB granularity. // Colorize: green
    PSE_36 = BIT_17, // 36-Bit Page Size Extension. 4-MByte pages addressing physical memory beyond 4 GBytes are supported with 32-bit paging. This feature indicates that upper bits of the physical address of a 4-MByte page are encoded in bits 20:13 of the page-directory entry. Such physical addresses are limited by MAXPHYADDR and may be up to 40 bits in size. // Colorize: green
    PSN    = BIT_18, // Processor Serial Number. The processor supports the 96-bit processor identification number feature and the feature is enabled. // Colorize: green
    CLFSH  = BIT_19, // CLFLUSH Instruction. CLFLUSH Instruction is supported.                                                  // Colorize: green
    DS     = BIT_21, // Debug Store. The processor supports the ability to write debug information into a memory resident buffer. This feature is used by the branch trace store (BTS) and processor event-based sampling (PEBS) facilities (see Chapter 23, "Introduction to Virtual-Machine Extensions," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3C). // Colorize: green
    ACPI   = BIT_22, // Thermal Monitor and Software Controlled Clock Facilities. The processor implements internal MSRs that allow processor temperature to be monitored and processor performance to be modulated in predefined duty cycles under software control. // Colorize: green
    MMX    = BIT_23, // Intel MMX Technology. The processor supports the Intel MMX technology.                                            // Colorize: green
    FXSR   = BIT_24, // FXSAVE and FXRSTOR Instructions. The FXSAVE and FXRSTOR instructions are supported for fast save and restore of the floating point context. Presence of this bit also indicates that CR4.OSFXSR is available for an operating system to indicate that it supports the FXSAVE and FXRSTOR instructions. // Colorize: green
    SSE    = BIT_25, // SSE. The processor supports the SSE extensions.                                                                   // Colorize: green
    SSE2   = BIT_26, // SSE2. The processor supports the SSE2 extensions.                                                                 // Colorize: green
    SS     = BIT_27, // Self Snoop. The processor supports the management of conflicting memory types by performing a snoop of its own cache structure for transactions issued to the bus. // Colorize: green
    HTT    = BIT_28, // Max APIC IDs reserved field is Valid. A value of 0 for HTT indicates there is only a single logical processor in the package and software should assume only a single APIC ID is reserved. A value of 1 for HTT indicates the value in CPUID.1.EBX[23:16] (the Maximum number of addressable IDs for logical processors in this package) is valid for the package. // Colorize: green
    TM     = BIT_29, // Thermal Monitor. The processor implements the thermal monitor automatic thermal control circuitry (TCC).          // Colorize: green
    PBE    = BIT_31  // Pending Break Enable. The processor supports the use of the FERR#/PBE# pin when the processor is in the stop-clock state (STPCLK# is asserted) to signal the processor that an interrupt is pending and that the processor should return to normal operation to handle the interrupt. // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(DmiProcessorFeatureFlags, dmi_processor_feature_flags); // TEST: NO                                                                                                                         // Colorize: green
// Verified with DmiSpecVerifier [END] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(DmiProcessorFeatureFlag flag) // TEST: NO                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiProcessorFeatureFlag::NONE:      return "NONE";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::FPU:       return "FPU";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::VME:       return "VME";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::DE:        return "DE";                                                                                                                                            // Colorize: green
        case DmiProcessorFeatureFlag::PSE:       return "PSE";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::TSC:       return "TSC";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::MSR:       return "MSR";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::PAE:       return "PAE";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::MCE:       return "MCE";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::CX8:       return "CX8";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::APIC:      return "APIC";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::SEP:       return "SEP";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::MTRR:      return "MTRR";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::PGE:       return "PGE";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::MCA:       return "MCA";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::CMOV:      return "CMOV";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::PAT:       return "PAT";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::PSE_36:    return "PSE_36";                                                                                                                                         // Colorize: green
        case DmiProcessorFeatureFlag::PSN:       return "PSN";                                                                                                                                            // Colorize: green
        case DmiProcessorFeatureFlag::CLFSH:     return "CLFSH";                                                                                                                                       // Colorize: green
        case DmiProcessorFeatureFlag::DS:        return "DS";                                                                                                                                            // Colorize: green
        case DmiProcessorFeatureFlag::ACPI:      return "ACPI";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::MMX:       return "MMX";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::FXSR:      return "FXSR";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::SSE:       return "SSE";                                                                                                                                           // Colorize: green
        case DmiProcessorFeatureFlag::SSE2:      return "SSE2";                                                                                                                                          // Colorize: green
        case DmiProcessorFeatureFlag::SS:        return "SS";                                                                                                                                     // Colorize: green
        case DmiProcessorFeatureFlag::HTT:       return "HTT";                                                                                                                                            // Colorize: green
        case DmiProcessorFeatureFlag::TM:        return "TM";                                                                                                                                            // Colorize: green
        case DmiProcessorFeatureFlag::PBE:       return "PBE";                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(DmiProcessorFeatureFlag flag) // TEST: NO                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[23];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%08X (%s)", (dmi_processor_feature_flags)flag, flagToString(flag));                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const DmiProcessorFeatureFlags &flags) // TEST: NO                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[207];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, DmiProcessorFeatureFlag);                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const DmiProcessorFeatureFlags &flags) // TEST: NO                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[220];                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, DmiProcessorFeatureFlag, "0x%08X");                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPROCESSORFEATUREFLAGS_H                                                                                                                                // Colorize: green
