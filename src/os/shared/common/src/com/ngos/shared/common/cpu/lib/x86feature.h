#ifndef COM_NGOS_SHARED_COMMON_CPU_X86FEATURE_H
#define COM_NGOS_SHARED_COMMON_CPU_X86FEATURE_H



#include <com/ngos/shared/common/cpu/x86featureword.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/ngos/utils.h>



enum class X86Feature: u16 // Ignore CppEnumVerifier
{
    //
    // Intel-defined CPU features, CPUID level 0x00000001 (ECX), word 0
    //
    XMM3                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 0),      // "sse3" SSE-3
    PCLMULQDQ           = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 1),      // PCLMULQDQ instruction
    DTES64              = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 2),      // 64-bit Debug Store
    MWAIT               = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 3),      // "monitor" MONITOR/MWAIT support
    DSCPL               = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 4),      // "ds_cpl" CPL-qualified (filtered) Debug Store
    VMX                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 5),      // Hardware virtualization
    SMX                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 6),      // Safer Mode eXtensions
    EST                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 7),      // Enhanced SpeedStep
    TM2                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 8),      // Thermal Monitor 2
    SSSE3               = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 9),      // Supplemental SSE-3
    CID                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 10),     // Context ID
    SDBG                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 11),     // Silicon Debug
    FMA                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 12),     // Fused multiply-add
    CX16                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 13),     // CMPXCHG16B instruction
    XTPR                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 14),     // Send Task Priority Messages
    PDCM                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 15),     // Perf/Debug Capabilities MSR
    PCID                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 17),     // Process Context Identifiers
    DCA                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 18),     // Direct Cache Access
    XMM4_1              = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 19),     // "sse4_1" SSE-4.1
    XMM4_2              = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 20),     // "sse4_2" SSE-4.2
    X2APIC              = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 21),     // X2APIC
    MOVBE               = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 22),     // MOVBE instruction
    POPCNT              = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 23),     // POPCNT instruction
    TSC_DEADLINE_TIMER  = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 24),     // TSC deadline timer
    AES                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 25),     // AES instructions
    XSAVE               = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 26),     // XSAVE/XRSTOR/XSETBV/XGETBV instructions
    OSXSAVE             = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 27),     // "" XSAVE instruction enabled in the OS
    AVX                 = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 28),     // Advanced Vector Extensions
    F16C                = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 29),     // 16-bit FP conversions
    RDRAND              = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 30),     // RDRAND instruction
    HYPERVISOR          = WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 31),     // Running on a hypervisor



    //
    // Intel-defined CPU features, CPUID level 0x00000001 (EDX), word 1
    //
    FPU                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 0),      // Onboard FPU
    VME                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 1),      // Virtual Mode Extensions
    DE                  = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 2),      // Debugging Extensions
    PSE                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 3),      // Page Size Extensions
    TSC                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 4),      // Time Stamp Counter
    MSR                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 5),      // Model-Specific Registers
    PAE                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 6),      // Physical Address Extensions
    MCE                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 7),      // Machine Check Exception
    CX8                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 8),      // CMPXCHG8 instruction
    APIC                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 9),      // Onboard APIC
    SEP                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 11),     // SYSENTER/SYSEXIT
    MTRR                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 12),     // Memory Type Range Registers
    PGE                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 13),     // Page Global Enable
    MCA                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 14),     // Machine Check Architecture
    CMOV                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 15),     // CMOV instructions (plus FCMOVcc, FCOMI with FPU)
    PAT                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 16),     // Page Attribute Table
    PSE36               = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 17),     // 36-bit PSEs
    PN                  = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 18),     // Processor serial number
    CLFLUSH             = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 19),     // CLFLUSH instruction
    DS                  = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 21),     // "dts" Debug Store
    ACPI                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 22),     // ACPI via MSR
    MMX                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 23),     // Multimedia Extensions
    FXSR                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 24),     // FXSAVE/FXRSTOR, CR4.OSFXSR
    XMM                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 25),     // "sse"
    XMM2                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 26),     // "sse2"
    SELFSNOOP           = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 27),     // "ss" CPU self snoop
    HT                  = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 28),     // Hyper-Threading
    ACC                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 29),     // "tm" Automatic clock control
    IA64                = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 30),     // IA-64 processor
    PBE                 = WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 31),     // Pending Break Enable



    //
    // Thermal and Power Management Leaf, CPUID level 0x00000006 (EAX), word 2
    //
    DTHERM              = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 0),      // Digital Thermal Sensor
    IDA                 = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 1),      // Intel Dynamic Acceleration
    ARAT                = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 2),      // Always Running APIC Timer
    PLN                 = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 4),      // Intel Power Limit Notification
    PTS                 = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 6),      // Intel Package Thermal Status
    HWP                 = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 7),      // Intel Hardware P-states
    HWP_NOTIFY          = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 8),      // HWP Notification
    HWP_ACT_WINDOW      = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 9),      // HWP Activity Window
    HWP_EPP             = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 10),     // HWP Energy Perf. Preference
    HWP_PKG_REQ         = WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 11),     // HWP Package Level Request



    //
    // Intel-defined CPU features, CPUID level 0x00000007 (EBX), word 3
    //
    FSGSBASE            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 0),      // RDFSBASE, WRFSBASE, RDGSBASE, WRGSBASE instructions
    TSC_ADJUST          = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 1),      // TSC adjustment MSR 0x3B
    BMI1                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 3),      // 1st group bit manipulation extensions
    HLE                 = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 4),      // Hardware Lock Elision
    AVX2                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 5),      // AVX2 instructions
    SMEP                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 7),      // Supervisor Mode Execution Protection
    BMI2                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 8),      // 2nd group bit manipulation extensions
    ERMS                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 9),      // Enhanced REP MOVSB/STOSB instructions
    INVPCID             = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 10),     // Invalidate Processor Context ID
    RTM                 = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 11),     // Restricted Transactional Memory
    CQM                 = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 12),     // Cache QoS Monitoring
    MPX                 = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 14),     // Memory Protection Extension
    RDT_A               = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 15),     // Resource Director Technology Allocation
    AVX512F             = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 16),     // AVX-512 Foundation
    AVX512DQ            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 17),     // AVX-512 DQ (Double/Quad granular) Instructions
    RDSEED              = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 18),     // RDSEED instruction
    ADX                 = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 19),     // ADCX and ADOX instructions
    SMAP                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 20),     // Supervisor Mode Access Prevention
    AVX512IFMA          = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 21),     // AVX-512 Integer Fused Multiply-Add instructions
    CLFLUSHOPT          = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 23),     // CLFLUSHOPT instruction
    CLWB                = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 24),     // CLWB instruction
    INTEL_PT            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 25),     // Intel Processor Trace
    AVX512PF            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 26),     // AVX-512 Prefetch
    AVX512ER            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 27),     // AVX-512 Exponential and Reciprocal
    AVX512CD            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 28),     // AVX-512 Conflict Detection
    SHA_NI              = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 29),     // SHA1/SHA256 Instruction Extensions
    AVX512BW            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 30),     // AVX-512 BW (Byte/Word granular) Instructions
    AVX512VL            = WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 31),     // AVX-512 VL (128/256 Vector Length) Extensions



    //
    // Intel-defined CPU features, CPUID level 0x00000007 (ECX), word 4
    //
    AVX512VBMI          = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 1),      // AVX512 Vector Bit Manipulation instructions
    UMIP                = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 2),      // User Mode Instruction Protection
    PKU                 = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 3),      // Protection Keys for Userspace
    OSPKE               = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 4),      // OS Protection Keys Enable
    AVX512_VBMI2        = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 6),      // Additional AVX512 Vector Bit Manipulation Instructions
    GFNI                = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 8),      // Galois Field New Instructions
    VAES                = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 9),      // Vector AES
    VPCLMULQDQ          = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 10),     // Carry-Less Multiplication Double Quadword
    AVX512_VNNI         = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 11),     // Vector Neural Network Instructions
    AVX512_BITALG       = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 12),     // Support for VPOPCNT[B,W] and VPSHUF-BITQMB instructions
    TME                 = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 13),     // Intel Total Memory Encryption
    AVX512_VPOPCNTDQ    = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 14),     // POPCNT for vectors of DW/QW
    LA57                = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 16),     // 5-level page tables
    RDPID               = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 22),     // RDPID instruction
    CLDEMOTE            = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 25),     // CLDEMOTE instruction
    MOVDIRI             = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 27),     // MOVDIRI instruction
    MOVDIR64B           = WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 28),     // MOVDIR64B instruction



    //
    // Intel-defined CPU features, CPUID level 0x00000007:0 (EDX), word 5
    //
    AVX512_4VNNIW           = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 2),  // AVX-512 Neural Network Instructions
    AVX512_4FMAPS           = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 3),  // AVX-512 Multiply Accumulation Single precision
    PCONFIG                 = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 18), // Intel PCONFIG
    SPEC_CTRL               = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 26), // "" Speculation Control (IBRS + IBPB)
    INTEL_STIBP             = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 27), // "" Single Thread Indirect Branch Predictors
    FLUSH_L1D               = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 28), // Flush L1D cache
    ARCH_CAPABILITIES       = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 29), // IA32_ARCH_CAPABILITIES MSR (Intel)
    SPEC_CTRL_SSBD          = WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 31), // "" Speculative Store Bypass Disable



    //
    // Extended state features, CPUID level 0x0000000D:1 (EAX), word 6
    //
    XSAVEOPT            = WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 0),    // XSAVEOPT instruction
    XSAVEC              = WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 1),    // XSAVEC instruction
    XGETBV1             = WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 2),    // XGETBV with ECX = 1 instruction
    XSAVES              = WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 3),    // XSAVES/XRSTORS instructions



    //
    // Intel-defined CPU QoS Sub-leaf, CPUID level 0x0000000F:0 (EDX), word 7
    //
    CQM_LLC             = WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 1),    // LLC QoS if 1



    //
    // Intel-defined CPU QoS Sub-leaf, CPUID level 0x0000000F:1 (EDX), word 8
    //
    CQM_OCCUP_LLC       = WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 0),    // LLC occupancy monitoring
    CQM_MBM_TOTAL       = WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 1),    // LLC Total MBM monitoring
    CQM_MBM_LOCAL       = WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 2),    // LLC Local MBM monitoring



    //
    // AMD-defined CPU features, CPUID level 0x80000001 (ECX), word 9
    //
    LAHF_LM             = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 0),      // LAHF/SAHF in long mode
    CMP_LEGACY          = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 1),      // If yes HyperThreading not valid
    SVM                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 2),      // Secure Virtual Machine
    EXTAPIC             = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 3),      // Extended APIC space
    CR8_LEGACY          = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 4),      // CR8 in 32-bit mode
    ABM                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 5),      // Advanced bit manipulation
    SSE4A               = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 6),      // SSE-4A
    MISALIGNSSE         = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 7),      // Misaligned SSE mode
    _3DNOWPREFETCH      = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 8),      // 3DNow prefetch instructions
    OSVW                = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 9),      // OS Visible Workaround
    IBS                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 10),     // Instruction Based Sampling
    XOP                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 11),     // extended AVX instructions
    SKINIT              = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 12),     // SKINIT/STGI instructions
    WDT                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 13),     // Watchdog timer
    LWP                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 15),     // Light Weight Profiling
    FMA4                = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 16),     // 4 operands MAC instructions
    TCE                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 17),     // Translation Cache Extension
    NODEID_MSR          = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 19),     // NodeId MSR
    TBM                 = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 21),     // Trailing Bit Manipulations
    TOPOEXT             = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 22),     // Topology extensions CPUID leafs
    PERFCTR_CORE        = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 23),     // Core performance counter extensions
    PERFCTR_NB          = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 24),     // NB performance counter extensions
    BPEXT               = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 26),     // Data breakpoint extension
    PTSC                = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 27),     // Performance time-stamp counter
    PERFCTR_LLC         = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 28),     // Last Level Cache performance counter extensions
    MWAITX              = WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 29),     // MWAIT extension (MONITORX/MWAITX instructions)



    //
    // AMD-defined CPU features, CPUID level 0x80000001 (EDX), word 10
    //
    SYSCALL             = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 11),     // SYSCALL/SYSRET
    MP                  = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 19),     // MP Capable
    NX                  = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 20),     // Execute Disable
    MMXEXT              = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 22),     // AMD MMX extensions
    FXSR_OPT            = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 25),     // FXSAVE/FXRSTOR optimizations
    GBPAGES             = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 26),     // "pdpe1gb" GB pages
    RDTSCP              = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 27),     // RDTSCP
    LM                  = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 29),     // Long Mode (x86-64, 64-bit support)
    _3DNOWEXT           = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 30),     // AMD 3DNow extensions
    _3DNOW              = WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 31),     // 3DNow



    //
    // AMD-defined CPU features, CPUID level 0x80000007 (EBX), word 11
    //
    OVERFLOW_RECOV      = WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 0),      // MCA overflow recovery support
    SUCCOR              = WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 1),      // Uncorrectable error containment and recovery
    SMCA                = WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 3),      // Scalable MCA



    //
    // AMD-defined CPU features, CPUID level 0x80000008 (EBX), word 12
    //
    CLZERO              = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 0),      // CLZERO instruction
    IRPERF              = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 1),      // Instructions Retired Count
    XSAVEERPTR          = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 2),      // Always save/restore FP error pointers
    AMD_IBPB            = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 12),     // "" Indirect Branch Prediction Barrier
    AMD_IBRS            = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 14),     // "" Indirect Branch Restricted Speculation
    AMD_STIBP           = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 15),     // "" Single Thread Indirect Branch Predictors
    AMD_SSBD            = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 24),     // "" Speculative Store Bypass Disable
    VIRT_SSBD           = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 25),     // Virtualized Speculative Store Bypass Disable
    AMD_SSB_NO          = WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 26),     // "" Speculative Store Bypass is fixed in hardware



    //
    // AMD SVM Feature Identification, CPUID level 0x8000000A (EDX), word 13
    //
    NPT                 = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 0),      // Nested Page Table support
    LBRV                = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 1),      // LBR Virtualization support
    SVML                = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 2),      // "svm_lock" SVM locking MSR
    NRIPS               = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 3),      // "nrip_save" SVM next_rip save
    TSCRATEMSR          = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 4),      // "tsc_scale" TSC scaling support
    VMCBCLEAN           = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 5),      // "vmcb_clean" VMCB clean bits support
    FLUSHBYASID         = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 6),      // flush-by-ASID support
    DECODEASSISTS       = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 7),      // Decode Assists support
    PAUSEFILTER         = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 10),     // filtered pause intercept
    PFTHRESHOLD         = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 12),     // pause filter threshold
    AVIC                = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 13),     // Virtual Interrupt Controller
    V_VMSAVE_VMLOAD     = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 15),     // Virtual VMSAVE VMLOAD
    VGIF                = WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 16),     // Virtual GIF



    //
    // Auxiliary flags: NGOS defined - For features scattered in various
    // CPUID levels like 0x06, 0x0A etc, word 14
    //
    APERFMPERF          = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 0),    // P-State hardware coordination feedback capability (APERF/MPERF MSRs)
    EPB                 = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 1),    // IA32_ENERGY_PERF_BIAS support
    CAT_L3              = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 2),    // Cache Allocation Technology L3
    CAT_L2              = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 3),    // Cache Allocation Technology L2
    CDP_L3              = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 4),    // Code and Data Prioritization L3
    CDP_L2              = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 5),    // Code and Data Prioritization L2
    MBA                 = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 6),    // Memory Bandwidth Allocation
    HW_PSTATE           = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 7),    // AMD HW-PState
    CPB                 = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 8),    // AMD Core Performance Boost
    PROC_FEEDBACK       = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 9),    // AMD ProcFeedbackInterface
    SME                 = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 10),   // AMD Secure Memory Encryption
    SEV                 = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 11),   // AMD Secure Encrypted Virtualization
    MSR_SPEC_CTRL       = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 12),   // "" MSR SPEC_CTRL is implemented
    IBRS                = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 13),   // Indirect Branch Restricted Speculation
    IBPB                = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 14),   // Indirect Branch Prediction Barrier
    STIBP               = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 15),   // Single Thread Indirect Branch Predictors
    SSBD                = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 16),   // Speculative Store Bypass Disable
    IBRS_ENHANCED       = WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 17),   // Enhanced IBRS



    //
    // Other features, NGOS-defined mapping, word 15
    //
    ALWAYS              = WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 0),        // "" Always-present feature
    ALWAYS_ZERO         = WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 1),        // "" Always-absent feature
    CPUID               = WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 2),        // CPU has CPUID instruction itself
    CONSTANT_TSC        = WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 3),        // TSC ticks at a constant rate
    NONSTOP_TSC         = WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 4),        // TSC doesn't stop in C states
    NONSTOP_TSC_S3      = WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 5),        // TSC doesn't stop in S3 state
};



#endif // COM_NGOS_SHARED_COMMON_CPU_X86FEATURE_H
