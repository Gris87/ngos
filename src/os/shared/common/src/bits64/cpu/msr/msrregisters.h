#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MSR_MSRREGISTERS_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MSR_MSRREGISTERS_H



#define MSR_KVM_CLOCKSOURCE_WALL_CLOCK      0x00000011 // KVM clock 1 wall clock
#define MSR_KVM_CLOCKSOURCE_SYSTEM_TIME     0x00000012 // KVM clock 1 system time
#define MSR_IA32_MICROCODE_REV              0x0000008B // Microcode revision
#define MSR_IA32_ARCH_CAPABILITIES          0x0000010A // Architecture capabilities
#define MSR_IA32_MISC_ENABLE                0x000001A0 // Misc enable flags
#define MSR_KVM_CLOCKSOURCE2_WALL_CLOCK     0x4B564D00 // KVM clock 1 wall clock
#define MSR_KVM_CLOCKSOURCE2_SYSTEM_TIME    0x4B564D01 // KVM clock 1 system time
#define MSR_EFER                            0xC0000080 // Extended Feature Enable Register
#define MSR_FS_BASE                         0xC0000100 // 64 bit FS base
#define MSR_GS_BASE                         0xC0000101 // 64 bit GS base



// MSR_IA32_ARCH_CAPABILITIES bits:
#define MSR_IA32_ARCH_CAPABILITIES_RDCL_NO_BIT                  0 // Not susceptible to Meltdown
#define MSR_IA32_ARCH_CAPABILITIES_IBRS_ALL_BIT                 1 // Enhanced IBRS support
#define MSR_IA32_ARCH_CAPABILITIES_SKIP_VMENTRY_L1DFLUSH_BIT    3 // Skip L1D flush on vmentry
#define MSR_IA32_ARCH_CAPABILITIES_SSB_NO_BIT                   4 // Not susceptible to Speculative Store Bypass attack, so no Speculative Store Bypass control required.

#define MSR_IA32_ARCH_CAPABILITIES_RDCL_NO                      (1ULL << MSR_IA32_ARCH_CAPABILITIES_RDCL_NO_BIT)
#define MSR_IA32_ARCH_CAPABILITIES_IBRS_ALL                     (1ULL << MSR_IA32_ARCH_CAPABILITIES_IBRS_ALL_BIT)
#define MSR_IA32_ARCH_CAPABILITIES_SKIP_VMENTRY_L1DFLUSH        (1ULL << MSR_IA32_ARCH_CAPABILITIES_SKIP_VMENTRY_L1DFLUSH_BIT)
#define MSR_IA32_ARCH_CAPABILITIES_SSB_NO                       (1ULL << MSR_IA32_ARCH_CAPABILITIES_SSB_NO_BIT)



// MSR_IA32_MISC_ENABLE bits:
#define MSR_IA32_MISC_ENABLE_FAST_STRING_BIT        0
#define MSR_IA32_MISC_ENABLE_TCC_BIT                1
#define MSR_IA32_MISC_ENABLE_EMON_BIT               7
#define MSR_IA32_MISC_ENABLE_BTS_UNAVAILABLE_BIT    11
#define MSR_IA32_MISC_ENABLE_PEBS_UNAVAILABLE_BIT   12
#define MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP_BIT 16
#define MSR_IA32_MISC_ENABLE_MWAIT_BIT              18
#define MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT        22
#define MSR_IA32_MISC_ENABLE_XTPR_DISABLE_BIT       23
#define MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT         34

#define MSR_IA32_MISC_ENABLE_FAST_STRING            (1ULL << MSR_IA32_MISC_ENABLE_FAST_STRING_BIT)
#define MSR_IA32_MISC_ENABLE_TCC                    (1ULL << MSR_IA32_MISC_ENABLE_TCC_BIT)
#define MSR_IA32_MISC_ENABLE_EMON                   (1ULL << MSR_IA32_MISC_ENABLE_EMON_BIT)
#define MSR_IA32_MISC_ENABLE_BTS_UNAVAILABLE        (1ULL << MSR_IA32_MISC_ENABLE_BTS_UNAVAILABLE_BIT)
#define MSR_IA32_MISC_ENABLE_PEBS_UNAVAILABLE       (1ULL << MSR_IA32_MISC_ENABLE_PEBS_UNAVAILABLE_BIT)
#define MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP     (1ULL << MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP_BIT)
#define MSR_IA32_MISC_ENABLE_MWAIT                  (1ULL << MSR_IA32_MISC_ENABLE_MWAIT_BIT)
#define MSR_IA32_MISC_ENABLE_LIMIT_CPUID            (1ULL << MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT)
#define MSR_IA32_MISC_ENABLE_XTPR_DISABLE           (1ULL << MSR_IA32_MISC_ENABLE_XTPR_DISABLE_BIT)
#define MSR_IA32_MISC_ENABLE_XD_DISABLE             (1ULL << MSR_IA32_MISC_ENABLE_XD_DISABLE_BIT)



// MSR_EFER bits:
#define MSR_EFER_SCE_BIT    0  // SYSCALL/SYSRET
#define MSR_EFER_LME_BIT    8  // Long mode enable
#define MSR_EFER_LMA_BIT    10 // Long mode active (read-only)
#define MSR_EFER_NX_BIT     11 // No execute enable
#define MSR_EFER_SVME_BIT   12 // Enable virtualization
#define MSR_EFER_LMSLE_BIT  13 // Long Mode Segment Limit Enable
#define MSR_EFER_FFXSR_BIT  14 // Enable Fast FXSAVE/FXRSTOR

#define MSR_EFER_SCE        (1ULL << MSR_EFER_SCE_BIT)
#define MSR_EFER_LME        (1ULL << MSR_EFER_LME_BIT)
#define MSR_EFER_LMA        (1ULL << MSR_EFER_LMA_BIT)
#define MSR_EFER_NX         (1ULL << MSR_EFER_NX_BIT)
#define MSR_EFER_SVME       (1ULL << MSR_EFER_SVME_BIT)
#define MSR_EFER_LMSLE      (1ULL << MSR_EFER_LMSLE_BIT)
#define MSR_EFER_FFXSR      (1ULL << MSR_EFER_FFXSR_BIT)



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MSR_MSRREGISTERS_H
