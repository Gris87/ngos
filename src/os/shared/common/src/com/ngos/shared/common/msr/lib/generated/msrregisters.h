// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_MSR_LIB_GENERATED_MSRREGISTERS_H
#define COM_NGOS_SHARED_COMMON_MSR_LIB_GENERATED_MSRREGISTERS_H



#define MSR_IA32_P5_MC_ADDR               0x00000000 // See Section 2.23, "MSRs in Pentium Processors."
#define MSR_IA32_P5_MC_TYPE               0x00000001 // See Section 2.23, "MSRs in Pentium Processors."
#define MSR_IA32_MONITOR_FILTER_SIZE      0x00000006 // See Section 8.10.5, "Monitor/Mwait Address Range Determination."
#define MSR_IA32_TIME_STAMP_COUNTER       0x00000010 // See Section 17.17, "Time-Stamp Counter."
#define MSR_IA32_PLATFORM_ID              0x00000017 // Platform ID (R/O) The operating system can use this MSR to determine "slot" information for the processor and the proper microcode update to load.
#define MSR_IA32_APIC_BASE                0x0000001B // This register holds the APIC base address, permitting the relocation of the APIC memory map. See Section 10.4.4, "Local APIC Status and Location" and Section 10.4.5, "Relocating the Local APIC Registers".
#define MSR_IA32_FEATURE_CONTROL          0x0000003A // Control Features in Intel 64 Processor (R/W) If any one enumeration
#define MSR_IA32_TSC_ADJUST               0x0000003B // Per Logical Processor TSC Adjust (R/Write to clear)
#define MSR_IA32_SPEC_CTRL                0x00000048 // Speculation Control (R/W) The MSR bits are defined as logical processor scope. On some core implementations, the bits may impact sibling logical processors on the same core. This MSR has a value of 0 after reset and is unaffected by INIT# or SIPI#.
#define MSR_IA32_PRED_CMD                 0x00000049 // Prediction Command (WO) Gives software a way to issue commands that affect the state of predictors.
#define MSR_IA32_PPIN_CTL                 0x0000004E // Protected Processor Inventory Number Enable Control (R/W)
#define MSR_IA32_PPIN                     0x0000004F // Protected Processor Inventory Number (R/O)
#define MSR_IA32_BIOS_UPDT_TRIG           0x00000079 // BIOS Update Trigger (W) Executing a WRMSR instruction to this MSR causes a microcode update to be loaded into the processor. See Section 9.11.6, "Microcode Update Loader." A processor may prevent writing to this MSR when loading guest states on VM entries or saving guest states on VM exits.
#define MSR_IA32_BIOS_SIGN_ID             0x0000008B // BIOS Update Signature (R/W) Returns the microcode update signature following the execution of CPUID.01H. A processor may prevent writing to this MSR when loading guest states on VM entries or saving guest states on VM exits.
#define MSR_IA32_SGXLEPUBKEYHASH0         0x0000008C // IA32_SGXLEPUBKEYHASH[63:0] (R/W) Bits 63:0 of the SHA256 digest of the SIGSTRUCT.MODULUS for SGX Launch Enclave. On reset, the default value is the digest of Intel's signing key.
#define MSR_IA32_SGXLEPUBKEYHASH1         0x0000008D // IA32_SGXLEPUBKEYHASH[127:64] (R/W) Bits 127:64 of the SHA256 digest of the SIGSTRUCT.MODULUS for SGX Launch Enclave. On reset, the default value is the digest of Intel's signing key.
#define MSR_IA32_SGXLEPUBKEYHASH2         0x0000008E // IA32_SGXLEPUBKEYHASH[191:128] (R/W) Bits 191:128 of the SHA256 digest of the SIGSTRUCT.MODULUS for SGX Launch Enclave. On reset, the default value is the digest of Intel's signing key.
#define MSR_IA32_SGXLEPUBKEYHASH3         0x0000008F // IA32_SGXLEPUBKEYHASH[255:192] (R/W) Bits 255:192 of the SHA256 digest of the SIGSTRUCT.MODULUS for SGX Launch Enclave. On reset, the default value is the digest of Intel's signing key.
#define MSR_IA32_SMM_MONITOR_CTL          0x0000009B // SMM Monitor Configuration (R/W)
#define MSR_IA32_SMBASE                   0x0000009E // Base address of the logical processor's SMRAM image (R/O, SMM only).
#define MSR_IA32_MISC_PACKAGE_CTLS        0x000000BC // Power Filtering Control (R/W) This MSR has a value of 0 after reset and is unaffected by INIT# or SIPI#.
#define MSR_IA32_PMC0                     0x000000C1 // General Performance Counter 0 (R/W)
#define MSR_IA32_PMC1                     0x000000C2 // General Performance Counter 1 (R/W)
#define MSR_IA32_PMC2                     0x000000C3 // General Performance Counter 2 (R/W)
#define MSR_IA32_PMC3                     0x000000C4 // General Performance Counter 3 (R/W)
#define MSR_IA32_PMC4                     0x000000C5 // General Performance Counter 4 (R/W)
#define MSR_IA32_PMC5                     0x000000C6 // General Performance Counter 5 (R/W)
#define MSR_IA32_PMC6                     0x000000C7 // General Performance Counter 6 (R/W)
#define MSR_IA32_PMC7                     0x000000C8 // General Performance Counter 7 (R/W)
#define MSR_IA32_CORE_CAPABILITIES        0x000000CF // IA32 Core Capabilities Register
#define MSR_IA32_UMWAIT_CONTROL           0x000000E1 // UMWAIT Control (R/W)
#define MSR_IA32_MPERF                    0x000000E7 // TSC Frequency Clock Counter (R/Write to clear)
#define MSR_IA32_APERF                    0x000000E8 // Actual Performance Clock Counter (R/Write to clear)
#define MSR_IA32_MTRRCAP                  0x000000FE // MTRR Capability (R/O) See Section 11.11.2.1, "IA32_MTRR_DEF_TYPE MSR."
#define MSR_IA32_ARCH_CAPABILITIES        0x0000010A // Enumeration of Architectural Features (R/O)
#define MSR_IA32_FLUSH_CMD                0x0000010B // Flush Command (WO) Gives software a way to invalidate structures with finer granularity than other architectural methods.
#define MSR_IA32_TSX_CTRL                 0x00000122 // IA32_TSX_CTRL
#define MSR_IA32_SYSENTER_CS              0x00000174 // SYSENTER_CS_MSR (R/W)
#define MSR_IA32_SYSENTER_ESP             0x00000175 // SYSENTER_ESP_MSR (R/W)
#define MSR_IA32_SYSENTER_EIP             0x00000176 // SYSENTER_EIP_MSR (R/W)
#define MSR_IA32_MCG_CAP                  0x00000179 // Global Machine Check Capability (R/O)
#define MSR_IA32_MCG_STATUS               0x0000017A // Global Machine Check Status (R/W0)
#define MSR_IA32_MCG_CTL                  0x0000017B // Global Machine Check Control (R/W)
#define MSR_IA32_PERFEVTSEL0              0x00000186 // Performance Event Select Register 0 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL1              0x00000187 // Performance Event Select Register 1 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL2              0x00000188 // Performance Event Select Register 2 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL3              0x00000189 // Performance Event Select Register 3 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL4              0x0000018A // Performance Event Select Register 4 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL5              0x0000018B // Performance Event Select Register 5 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL6              0x0000018C // Performance Event Select Register 6 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_PERFEVTSEL7              0x0000018D // Performance Event Select Register 7 (R/W) If CPUID.0AH: EAX[15:8] >
#define MSR_IA32_OVERCLOCKING_STATUS      0x00000195 // Overclocking Status (R/O) IA32_ARCH_CAPABILITIES[bit 23] enumerates support for this MSR.
#define MSR_IA32_PERF_STATUS              0x00000198 // Current Performance Status (R/O) See Section 14.1.1, "Software Interface For Initiating Performance State Transitions".
#define MSR_IA32_PERF_CTL                 0x00000199 // Performance Control MSR (R/W) Software makes a request for a new Performance state (P-State) by writing this MSR. See Section 14.1.1, "Software Interface For Initiating Performance State Transitions".
#define MSR_IA32_CLOCK_MODULATION         0x0000019A // Clock Modulation Control (R/W) See Section 14.8.3, "Software Controlled Clock Modulation."
#define MSR_IA32_THERM_INTERRUPT          0x0000019B // Thermal Interrupt Control (R/W) Enables and disables the generation of an interrupt on temperature transitions detected with the processor's thermal sensors and thermal monitor. See Section 14.8.2, "Thermal Monitor."
#define MSR_IA32_THERM_STATUS             0x0000019C // Thermal Status Information (R/O) Contains status information about the processor's thermal sensor and automatic thermal monitoring facilities. See Section 14.8.2, "Thermal Monitor".
#define MSR_IA32_MISC_ENABLE              0x000001A0 // Enable Misc. Processor Features (R/W) Allows a variety of processor functions to be enabled and disabled.
#define MSR_IA32_ENERGY_PERF_BIAS         0x000001B0 // Performance Energy Bias Hint (R/W)
#define MSR_IA32_PACKAGE_THERM_STATUS     0x000001B1 // Package Thermal Status Information (R/O) Contains status information about the package's thermal sensor. See Section 14.9, "Package Level Thermal Management."
#define MSR_IA32_PACKAGE_THERM_INTERRUPT  0x000001B2 // Pkg Thermal Interrupt Control (R/W) Enables and disables the generation of an interrupt on temperature transitions detected with the package's thermal sensor. See Section 14.9, "Package Level Thermal Management."
#define MSR_IA32_DEBUGCTL                 0x000001D9 // Trace/Profile Resource Control (R/W)
#define MSR_IA32_LER_FROM_IP              0x000001DD // Last Event Record Source IP Register (R/W)
#define MSR_IA32_LER_TO_IP                0x000001DE // Last Event Record Destination IP Register (R/W)
#define MSR_IA32_LER_INFO                 0x000001E0 // Last Event Record Info Register (R/W)
#define MSR_IA32_SMRR_PHYSBASE            0x000001F2 // SMRR Base Address (Writeable only in SMM) Base address of SMM memory range.
#define MSR_IA32_SMRR_PHYSMASK            0x000001F3 // SMRR Range Mask (Writeable only in SMM) Range Mask of SMM memory range.
#define MSR_IA32_PLATFORM_DCA_CAP         0x000001F8 // DCA Capability (R)
#define MSR_IA32_CPU_DCA_CAP              0x000001F9 // If set, CPU supports Prefetch-Hint type.
#define MSR_IA32_DCA_0_CAP                0x000001FA // DCA type 0 Status and Control register.
#define MSR_IA32_MTRR_PHYSBASE0           0x00000200 // See Section 11.11.2.3, "Variable Range MTRRs."
#define MSR_IA32_MTRR_PHYSMASK0           0x00000201 // MTRRphysMask0
#define MSR_IA32_MTRR_PHYSBASE1           0x00000202 // MTRRphysBase1
#define MSR_IA32_MTRR_PHYSMASK1           0x00000203 // MTRRphysMask1
#define MSR_IA32_MTRR_PHYSBASE2           0x00000204 // MTRRphysBase2
#define MSR_IA32_MTRR_PHYSMASK2           0x00000205 // MTRRphysMask2
#define MSR_IA32_MTRR_PHYSBASE3           0x00000206 // MTRRphysBase3
#define MSR_IA32_MTRR_PHYSMASK3           0x00000207 // MTRRphysMask3
#define MSR_IA32_MTRR_PHYSBASE4           0x00000208 // MTRRphysBase4
#define MSR_IA32_MTRR_PHYSMASK4           0x00000209 // MTRRphysMask4
#define MSR_IA32_MTRR_PHYSBASE5           0x0000020A // MTRRphysBase5
#define MSR_IA32_MTRR_PHYSMASK5           0x0000020B // MTRRphysMask5
#define MSR_IA32_MTRR_PHYSBASE6           0x0000020C // MTRRphysBase6
#define MSR_IA32_MTRR_PHYSMASK6           0x0000020D // MTRRphysMask6
#define MSR_IA32_MTRR_PHYSBASE7           0x0000020E // MTRRphysBase7
#define MSR_IA32_MTRR_PHYSMASK7           0x0000020F // MTRRphysMask7
#define MSR_IA32_MTRR_PHYSBASE8           0x00000210 // MTRRphysBase8
#define MSR_IA32_MTRR_PHYSMASK8           0x00000211 // MTRRphysMask8
#define MSR_IA32_MTRR_PHYSBASE9           0x00000212 // MTRRphysBase9
#define MSR_IA32_MTRR_PHYSMASK9           0x00000213 // MTRRphysMask9
#define MSR_IA32_MTRR_FIX64K_00000        0x00000250 // MTRRfix64K_00000
#define MSR_IA32_MTRR_FIX16K_80000        0x00000258 // MTRRfix16K_80000
#define MSR_IA32_MTRR_FIX16K_A0000        0x00000259 // MTRRfix16K_A0000
#define MSR_IA32_MTRR_FIX4K_C0000         0x00000268 // See Section 11.11.2.2, "Fixed Range MTRRs."
#define MSR_IA32_MTRR_FIX4K_C8000         0x00000269 // MTRRfix4K_C8000
#define MSR_IA32_MTRR_FIX4K_D0000         0x0000026A // MTRRfix4K_D0000
#define MSR_IA32_MTRR_FIX4K_D8000         0x0000026B // MTRRfix4K_D8000
#define MSR_IA32_MTRR_FIX4K_E0000         0x0000026C // MTRRfix4K_E0000
#define MSR_IA32_MTRR_FIX4K_E8000         0x0000026D // MTRRfix4K_E8000
#define MSR_IA32_MTRR_FIX4K_F0000         0x0000026E // MTRRfix4K_F0000
#define MSR_IA32_MTRR_FIX4K_F8000         0x0000026F // MTRRfix4K_F8000
#define MSR_IA32_PAT                      0x00000277 // IA32_PAT (R/W)
#define MSR_IA32_MC0_CTL2                 0x00000280 // MSR to enable/disable CMCI capability for bank 0. (R/W) See Section 15.3.2.5, "IA32_MCi_CTL2 MSRs".
#define MSR_IA32_MC1_CTL2                 0x00000281 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC2_CTL2                 0x00000282 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC3_CTL2                 0x00000283 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC4_CTL2                 0x00000284 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC5_CTL2                 0x00000285 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC6_CTL2                 0x00000286 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC7_CTL2                 0x00000287 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC8_CTL2                 0x00000288 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC9_CTL2                 0x00000289 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC10_CTL2                0x0000028A // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC11_CTL2                0x0000028B // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC12_CTL2                0x0000028C // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC13_CTL2                0x0000028D // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC14_CTL2                0x0000028E // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC15_CTL2                0x0000028F // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC16_CTL2                0x00000290 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC17_CTL2                0x00000291 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC18_CTL2                0x00000292 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC19_CTL2                0x00000293 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC20_CTL2                0x00000294 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC21_CTL2                0x00000295 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC22_CTL2                0x00000296 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC23_CTL2                0x00000297 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC24_CTL2                0x00000298 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC25_CTL2                0x00000299 // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC26_CTL2                0x0000029A // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC27_CTL2                0x0000029B // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC28_CTL2                0x0000029C // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC29_CTL2                0x0000029D // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC30_CTL2                0x0000029E // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MC31_CTL2                0x0000029F // (R/W) Same fields as IA32_MC0_CTL2.
#define MSR_IA32_MTRR_DEF_TYPE            0x000002FF // MTRRdefType (R/W)
#define MSR_IA32_FIXED_CTR0               0x00000309 // Fixed-Function Performance Counter 0 (R/W): Counts Instr_Retired.Any.
#define MSR_IA32_FIXED_CTR1               0x0000030A // Fixed-Function Performance Counter 1 (R/W): Counts CPU_CLK_Unhalted.Core.
#define MSR_IA32_FIXED_CTR2               0x0000030B // Fixed-Function Performance Counter 2 (R/W): Counts CPU_CLK_Unhalted.Ref.
#define MSR_IA32_PERF_CAPABILITIES        0x00000345 // Read Only MSR that enumerates the existence of performance monitoring features. (R/O)
#define MSR_IA32_FIXED_CTR_CTRL           0x0000038D // Fixed-Function Performance Counter Control (R/W) Counter increments while the results of ANDing respective enable bit in IA32_PERF_GLOBAL_CTRL with the corresponding OS or USR bits in this MSR is true.
#define MSR_IA32_PERF_GLOBAL_STATUS       0x0000038E // Performance Counter Status (R/O)
#define MSR_IA32_PERF_GLOBAL_CTRL         0x0000038F // Global Performance Counter Control (R/W) Counter increments while the result of ANDing the respective enable bit in this MSR with the corresponding OS or USR bits in the general-purpose or fixed counter control MSR is true.
#define MSR_IA32_PERF_GLOBAL_OVF_CTRL     0x00000390 // Global Performance Counter Overflow Control (R/W)
#define MSR_IA32_PERF_GLOBAL_STATUS_RESET 0x00000390 // Global Performance Counter Overflow Reset Control (R/W)
#define MSR_IA32_PERF_GLOBAL_STATUS_SET   0x00000391 // Global Performance Counter Overflow Set Control (R/W)
#define MSR_IA32_PERF_GLOBAL_INUSE        0x00000392 // Indicator that core perfmon interface is in use. (R/O)
#define MSR_IA32_PEBS_ENABLE              0x000003F1 // PEBS Control (R/W)
#define MSR_IA32_MC0_CTL                  0x00000400 // MC0_CTL
#define MSR_IA32_MC0_STATUS               0x00000401 // MC0_STATUS
#define MSR_IA32_MC0_ADDR                 0x00000402 // MC0_ADDR
#define MSR_IA32_MC0_MISC                 0x00000403 // MC0_MISC
#define MSR_IA32_MC1_CTL                  0x00000404 // MC1_CTL
#define MSR_IA32_MC1_STATUS               0x00000405 // MC1_STATUS
#define MSR_IA32_MC1_ADDR                 0x00000406 // MC1_ADDR
#define MSR_IA32_MC1_MISC                 0x00000407 // MC1_MISC
#define MSR_IA32_MC2_CTL                  0x00000408 // MC2_CTL
#define MSR_IA32_MC2_STATUS               0x00000409 // MC2_STATUS
#define MSR_IA32_MC2_ADDR                 0x0000040A // MC2_ADDR
#define MSR_IA32_MC2_MISC                 0x0000040B // MC2_MISC
#define MSR_IA32_MC3_CTL                  0x0000040C // MC3_CTL
#define MSR_IA32_MC3_STATUS               0x0000040D // MC3_STATUS
#define MSR_IA32_MC3_ADDR                 0x0000040E // MC3_ADDR
#define MSR_IA32_MC3_MISC                 0x0000040F // MC3_MISC
#define MSR_IA32_MC4_CTL                  0x00000410 // MC4_CTL
#define MSR_IA32_MC4_STATUS               0x00000411 // MC4_STATUS
#define MSR_IA32_MC4_ADDR                 0x00000412 // MC4_ADDR
#define MSR_IA32_MC4_MISC                 0x00000413 // MC4_MISC
#define MSR_IA32_MC5_CTL                  0x00000414 // MC5_CTL
#define MSR_IA32_MC5_STATUS               0x00000415 // MC5_STATUS
#define MSR_IA32_MC5_ADDR                 0x00000416 // MC5_ADDR
#define MSR_IA32_MC5_MISC                 0x00000417 // MC5_MISC
#define MSR_IA32_MC6_CTL                  0x00000418 // MC6_CTL
#define MSR_IA32_MC6_STATUS               0x00000419 // MC6_STATUS
#define MSR_IA32_MC6_ADDR                 0x0000041A // MC6_ADDR
#define MSR_IA32_MC6_MISC                 0x0000041B // MC6_MISC
#define MSR_IA32_MC7_CTL                  0x0000041C // MC7_CTL
#define MSR_IA32_MC7_STATUS               0x0000041D // MC7_STATUS
#define MSR_IA32_MC7_ADDR                 0x0000041E // MC7_ADDR
#define MSR_IA32_MC7_MISC                 0x0000041F // MC7_MISC
#define MSR_IA32_MC8_CTL                  0x00000420 // MC8_CTL
#define MSR_IA32_MC8_STATUS               0x00000421 // MC8_STATUS
#define MSR_IA32_MC8_ADDR                 0x00000422 // MC8_ADDR
#define MSR_IA32_MC8_MISC                 0x00000423 // MC8_MISC
#define MSR_IA32_MC9_CTL                  0x00000424 // MC9_CTL
#define MSR_IA32_MC9_STATUS               0x00000425 // MC9_STATUS
#define MSR_IA32_MC9_ADDR                 0x00000426 // MC9_ADDR
#define MSR_IA32_MC9_MISC                 0x00000427 // MC9_MISC
#define MSR_IA32_MC10_CTL                 0x00000428 // MC10_CTL
#define MSR_IA32_MC10_STATUS              0x00000429 // MC10_STATUS
#define MSR_IA32_MC10_ADDR                0x0000042A // MC10_ADDR
#define MSR_IA32_MC10_MISC                0x0000042B // MC10_MISC
#define MSR_IA32_MC11_CTL                 0x0000042C // MC11_CTL
#define MSR_IA32_MC11_STATUS              0x0000042D // MC11_STATUS
#define MSR_IA32_MC11_ADDR                0x0000042E // MC11_ADDR
#define MSR_IA32_MC11_MISC                0x0000042F // MC11_MISC
#define MSR_IA32_MC12_CTL                 0x00000430 // MC12_CTL
#define MSR_IA32_MC12_STATUS              0x00000431 // MC12_STATUS
#define MSR_IA32_MC12_ADDR                0x00000432 // MC12_ADDR
#define MSR_IA32_MC12_MISC                0x00000433 // MC12_MISC
#define MSR_IA32_MC13_CTL                 0x00000434 // MC13_CTL
#define MSR_IA32_MC13_STATUS              0x00000435 // MC13_STATUS
#define MSR_IA32_MC13_ADDR                0x00000436 // MC13_ADDR
#define MSR_IA32_MC13_MISC                0x00000437 // MC13_MISC
#define MSR_IA32_MC14_CTL                 0x00000438 // MC14_CTL
#define MSR_IA32_MC14_STATUS              0x00000439 // MC14_STATUS
#define MSR_IA32_MC14_ADDR                0x0000043A // MC14_ADDR
#define MSR_IA32_MC14_MISC                0x0000043B // MC14_MISC
#define MSR_IA32_MC15_CTL                 0x0000043C // MC15_CTL
#define MSR_IA32_MC15_STATUS              0x0000043D // MC15_STATUS
#define MSR_IA32_MC15_ADDR                0x0000043E // MC15_ADDR
#define MSR_IA32_MC15_MISC                0x0000043F // MC15_MISC
#define MSR_IA32_MC16_CTL                 0x00000440 // MC16_CTL
#define MSR_IA32_MC16_STATUS              0x00000441 // MC16_STATUS
#define MSR_IA32_MC16_ADDR                0x00000442 // MC16_ADDR
#define MSR_IA32_MC16_MISC                0x00000443 // MC16_MISC
#define MSR_IA32_MC17_CTL                 0x00000444 // MC17_CTL
#define MSR_IA32_MC17_STATUS              0x00000445 // MC17_STATUS
#define MSR_IA32_MC17_ADDR                0x00000446 // MC17_ADDR
#define MSR_IA32_MC17_MISC                0x00000447 // MC17_MISC
#define MSR_IA32_MC18_CTL                 0x00000448 // MC18_CTL
#define MSR_IA32_MC18_STATUS              0x00000449 // MC18_STATUS
#define MSR_IA32_MC18_ADDR                0x0000044A // MC18_ADDR
#define MSR_IA32_MC18_MISC                0x0000044B // MC18_MISC
#define MSR_IA32_MC19_CTL                 0x0000044C // MC19_CTL
#define MSR_IA32_MC19_STATUS              0x0000044D // MC19_STATUS
#define MSR_IA32_MC19_ADDR                0x0000044E // MC19_ADDR
#define MSR_IA32_MC19_MISC                0x0000044F // MC19_MISC
#define MSR_IA32_MC20_CTL                 0x00000450 // MC20_CTL
#define MSR_IA32_MC20_STATUS              0x00000451 // MC20_STATUS
#define MSR_IA32_MC20_ADDR                0x00000452 // MC20_ADDR
#define MSR_IA32_MC20_MISC                0x00000453 // MC20_MISC
#define MSR_IA32_MC21_CTL                 0x00000454 // MC21_CTL
#define MSR_IA32_MC21_STATUS              0x00000455 // MC21_STATUS
#define MSR_IA32_MC21_ADDR                0x00000456 // MC21_ADDR
#define MSR_IA32_MC21_MISC                0x00000457 // MC21_MISC
#define MSR_IA32_MC22_CTL                 0x00000458 // MC22_CTL
#define MSR_IA32_MC22_STATUS              0x00000459 // MC22_STATUS
#define MSR_IA32_MC22_ADDR                0x0000045A // MC22_ADDR
#define MSR_IA32_MC22_MISC                0x0000045B // MC22_MISC
#define MSR_IA32_MC23_CTL                 0x0000045C // MC23_CTL
#define MSR_IA32_MC23_STATUS              0x0000045D // MC23_STATUS
#define MSR_IA32_MC23_ADDR                0x0000045E // MC23_ADDR
#define MSR_IA32_MC23_MISC                0x0000045F // MC23_MISC
#define MSR_IA32_MC24_CTL                 0x00000460 // MC24_CTL
#define MSR_IA32_MC24_STATUS              0x00000461 // MC24_STATUS
#define MSR_IA32_MC24_ADDR                0x00000462 // MC24_ADDR
#define MSR_IA32_MC24_MISC                0x00000463 // MC24_MISC
#define MSR_IA32_MC25_CTL                 0x00000464 // MC25_CTL
#define MSR_IA32_MC25_STATUS              0x00000465 // MC25_STATUS
#define MSR_IA32_MC25_ADDR                0x00000466 // MC25_ADDR
#define MSR_IA32_MC25_MISC                0x00000467 // MC25_MISC
#define MSR_IA32_MC26_CTL                 0x00000468 // MC26_CTL
#define MSR_IA32_MC26_STATUS              0x00000469 // MC26_STATUS
#define MSR_IA32_MC26_ADDR                0x0000046A // MC26_ADDR
#define MSR_IA32_MC26_MISC                0x0000046B // MC26_MISC
#define MSR_IA32_MC27_CTL                 0x0000046C // MC27_CTL
#define MSR_IA32_MC27_STATUS              0x0000046D // MC27_STATUS
#define MSR_IA32_MC27_ADDR                0x0000046E // MC27_ADDR
#define MSR_IA32_MC27_MISC                0x0000046F // MC27_MISC
#define MSR_IA32_MC28_CTL                 0x00000470 // MC28_CTL
#define MSR_IA32_MC28_STATUS              0x00000471 // MC28_STATUS
#define MSR_IA32_MC28_ADDR                0x00000472 // MC28_ADDR
#define MSR_IA32_MC28_MISC                0x00000473 // MC28_MISC
#define MSR_IA32_VMX_BASIC                0x00000480 // Reporting Register of Basic VMX Capabilities (R/O) See Appendix A.1, "Basic VMX Information."
#define MSR_IA32_VMX_PINBASED_CTLS        0x00000481 // Capability Reporting Register of Pin-Based VM-Execution Controls (R/O) See Appendix A.3.1, "Pin-Based VM- Execution Controls."
#define MSR_IA32_VMX_PROCBASED_CTLS       0x00000482 // Capability Reporting Register of Primary Processor-Based VM-Execution Controls (R/O) See Appendix A.3.2, "Primary Processor- Based VM-Execution Controls."
#define MSR_IA32_VMX_EXIT_CTLS            0x00000483 // Capability Reporting Register of Primary VM-Exit Controls (R/O) See Appendix A.4.1, "Primary VM-Exit Controls."
#define MSR_IA32_VMX_ENTRY_CTLS           0x00000484 // Capability Reporting Register of VM-Entry Controls (R/O) See Appendix A.5, "VM-Entry Controls."
#define MSR_IA32_VMX_MISC                 0x00000485 // Reporting Register of Miscellaneous VMX Capabilities (R/O) See Appendix A.6, "Miscellaneous Data."
#define MSR_IA32_VMX_CR0_FIXED0           0x00000486 // Capability Reporting Register of CR0 Bits Fixed to 0 (R/O) See Appendix A.7, "VMX-Fixed Bits in CR0."
#define MSR_IA32_VMX_CR0_FIXED1           0x00000487 // Capability Reporting Register of CR0 Bits Fixed to 1 (R/O) See Appendix A.7, "VMX-Fixed Bits in CR0."
#define MSR_IA32_VMX_CR4_FIXED0           0x00000488 // Capability Reporting Register of CR4 Bits Fixed to 0 (R/O) See Appendix A.8, "VMX-Fixed Bits in CR4."
#define MSR_IA32_VMX_CR4_FIXED1           0x00000489 // Capability Reporting Register of CR4 Bits Fixed to 1 (R/O) See Appendix A.8, "VMX-Fixed Bits in CR4."
#define MSR_IA32_VMX_VMCS_ENUM            0x0000048A // Capability Reporting Register of VMCS Field Enumeration (R/O) See Appendix A.9, "VMCS Enumeration."
#define MSR_IA32_VMX_PROCBASED_CTLS2      0x0000048B // Capability Reporting Register of Secondary Processor-Based VM-Execution Controls (R/O) See Appendix A.3.3, "Secondary Processor- Based VM-Execution Controls."
#define MSR_IA32_VMX_EPT_VPID_CAP         0x0000048C // Capability Reporting Register of EPT and VPID (R/O) See Appendix A.10, "VPID and EPT Capabilities."
#define MSR_IA32_VMX_TRUE_PINBASED_CTLS   0x0000048D // Capability Reporting Register of Pin-Based VM-Execution Flex Controls (R/O) See Appendix A.3.1, "Pin-Based VM- Execution Controls."
#define MSR_IA32_VMX_TRUE_PROCBASED_CTLS  0x0000048E // Capability Reporting Register of Primary Processor-Based VM-Execution Flex Controls (R/O) See Appendix A.3.2, "Primary Processor- Based VM-Execution Controls."
#define MSR_IA32_VMX_TRUE_EXIT_CTLS       0x0000048F // Capability Reporting Register of VM-Exit Flex Controls (R/O) See Appendix A.4, "VM-Exit Controls."
#define MSR_IA32_VMX_TRUE_ENTRY_CTLS      0x00000490 // Capability Reporting Register of VM-Entry Flex Controls (R/O) See Appendix A.5, "VM-Entry Controls."
#define MSR_IA32_VMX_VMFUNC               0x00000491 // Capability Reporting Register of VM- Function Controls (R/O)
#define MSR_IA32_VMX_PROCBASED_CTLS3      0x00000492 // Capability Reporting Register of Tertiary Processor-Based VM-Execution Controls (R/O) See Appendix A.3.4, "Tertiary Processor- Based VM-Execution Controls."
#define MSR_IA32_VMX_EXIT_CTLS2           0x00000493 // Capability Reporting Register of Secondary VM-Exit Controls (R/O) See Appendix A.4.2, "Secondary VM-Exit Controls."
#define MSR_IA32_A_PMC0                   0x000004C1 // Full Width Writable IA32_PMC0 Alias (R/W)
#define MSR_IA32_A_PMC1                   0x000004C2 // Full Width Writable IA32_PMC1 Alias (R/W)
#define MSR_IA32_A_PMC2                   0x000004C3 // Full Width Writable IA32_PMC2 Alias (R/W)
#define MSR_IA32_A_PMC3                   0x000004C4 // Full Width Writable IA32_PMC3 Alias (R/W)
#define MSR_IA32_A_PMC4                   0x000004C5 // Full Width Writable IA32_PMC4 Alias (R/W)
#define MSR_IA32_A_PMC5                   0x000004C6 // Full Width Writable IA32_PMC5 Alias (R/W)
#define MSR_IA32_A_PMC6                   0x000004C7 // Full Width Writable IA32_PMC6 Alias (R/W)
#define MSR_IA32_A_PMC7                   0x000004C8 // Full Width Writable IA32_PMC7 Alias (R/W)
#define MSR_IA32_MCG_EXT_CTL              0x000004D0 // Allows software to signal some MCEs to only a single logical processor in the system. (R/W) See Section 15.3.1.4, "IA32_MCG_EXT_CTL MSR".
#define MSR_IA32_SGX_SVN_STATUS           0x00000500 // Status and SVN Threshold of SGX Support for ACM (R/O).
#define MSR_IA32_RTIT_OUTPUT_BASE         0x00000560 // Trace Output Base Register (R/W)
#define MSR_IA32_RTIT_OUTPUT_MASK_PTRS    0x00000561 // Trace Output Mask Pointers Register (R/W) If ((CPUID.(EAX=07H,
#define MSR_IA32_RTIT_CTL                 0x00000570 // Trace Control Register (R/W)
#define MSR_IA32_RTIT_STATUS              0x00000571 // Tracing Status Register (R/W)
#define MSR_IA32_RTIT_CR3_MATCH           0x00000572 // Trace Filter CR3 Match Register (R/W)
#define MSR_IA32_RTIT_ADDR0_A             0x00000580 // Region 0 Start Address (R/W)
#define MSR_IA32_RTIT_ADDR0_B             0x00000581 // Region 0 End Address (R/W)
#define MSR_IA32_RTIT_ADDR1_A             0x00000582 // Region 1 Start Address (R/W)
#define MSR_IA32_RTIT_ADDR1_B             0x00000583 // Region 1 End Address (R/W)
#define MSR_IA32_RTIT_ADDR2_A             0x00000584 // Region 2 Start Address (R/W)
#define MSR_IA32_RTIT_ADDR2_B             0x00000585 // Region 2 End Address (R/W)
#define MSR_IA32_RTIT_ADDR3_A             0x00000586 // Region 3 Start Address (R/W)
#define MSR_IA32_RTIT_ADDR3_B             0x00000587 // Region 3 End Address (R/W)
#define MSR_IA32_DS_AREA                  0x00000600 // DS Save Area (R/W) Points to the linear address of the first byte of the DS buffer management area, which is used to manage the BTS and PEBS buffers. See Section 19.6.3.4, "Debug Store (DS) Mechanism."
#define MSR_IA32_U_CET                    0x000006A0 // Configure User Mode CET (R/W)
#define MSR_IA32_S_CET                    0x000006A2 // Configure Supervisor Mode CET (R/W)
#define MSR_IA32_PL0_SSP                  0x000006A4 // Linear address to be loaded into SSP on transition to privilege level 0. (R/W) If the processor does not support Intel 64 architecture, these fields have only 32 bits; bits 63:32 of the MSRs are reserved. On processors that support Intel 64 architecture this value cannot represent a non-canonical address. In protected mode, only 31:0 are loaded. The linear address written must be aligned to 8 bytes and bits 2:0 must be 0 (hardware requires bits 1:0 to be 0).
#define MSR_IA32_PL1_SSP                  0x000006A5 // Linear address to be loaded into SSP on transition to privilege level 1. (R/W) If the processor does not support Intel 64 architecture, these fields have only 32 bits; bits 63:32 of the MSRs are reserved. On processors that support Intel 64 architecture this value cannot represent a non-canonical address. In protected mode, only 31:0 are loaded. The linear address written must be aligned to 8 bytes and bits 2:0 must be 0 (hardware requires bits 1:0 to be 0).
#define MSR_IA32_PL2_SSP                  0x000006A6 // Linear address to be loaded into SSP on transition to privilege level 2. (R/W) If the processor does not support Intel 64 architecture, these fields have only 32 bits; bits 63:32 of the MSRs are reserved. On processors that support Intel 64 architecture this value cannot represent a non-canonical address. In protected mode, only 31:0 are loaded. The linear address written must be aligned to 8 bytes and bits 2:0 must be 0 (hardware requires bits 1:0 to be 0).
#define MSR_IA32_PL3_SSP                  0x000006A7 // Linear address to be loaded into SSP on transition to privilege level 3. (R/W) If the processor does not support Intel 64 architecture, these fields have only 32 bits; bits 63:32 of the MSRs are reserved. On processors that support Intel 64 architecture this value cannot represent a non-canonical address. In protected mode, only 31:0 are loaded. The linear address written must be aligned to 8 bytes and bits 2:0 must be 0 (hardware requires bits 1:0 to be 0).
#define MSR_IA32_INTERRUPT_SSP_TABLE_ADDR 0x000006A8 // Linear address of a table of seven shadow stack pointers that are selected in IA-32e mode using the IST index (when not 0) from the interrupt gate descriptor. (R/W) This MSR is not present on processors that do not support Intel 64 architecture. This field cannot represent a non-canonical address.
#define MSR_IA32_TSC_DEADLINE             0x000006E0 // TSC Target of Local APIC's TSC Deadline Mode (R/W)
#define MSR_IA32_PKRS                     0x000006E1 // Specifies the PK permissions associated with each protection domain for supervisor pages (R/W)
#define MSR_IA32_PM_ENABLE                0x00000770 // Enable/disable HWP (R/W)
#define MSR_IA32_HWP_CAPABILITIES         0x00000771 // HWP Performance Range Enumeration (R/O)
#define MSR_IA32_HWP_REQUEST_PKG          0x00000772 // Power Management Control Hints for All Logical Processors in a Package (R/W)
#define MSR_IA32_HWP_INTERRUPT            0x00000773 // Control HWP Native Interrupts (R/W)
#define MSR_IA32_HWP_REQUEST              0x00000774 // Power Management Control Hints to a Logical Processor (R/W)
#define MSR_IA32_PECI_HWP_REQUEST_INFO    0x00000775 // IA32_PECI_HWP_REQUEST_INFO
#define MSR_IA32_HWP_CTL                  0x00000776 // IA32_HWP_CTL
#define MSR_IA32_HWP_STATUS               0x00000777 // Log bits indicating changes to Guaranteed & excursions to Minimum (R/W)
#define MSR_IA32_X2APIC_APICID            0x00000802 // x2APIC ID Register (R/O) See x2APIC Specification.
#define MSR_IA32_X2APIC_VERSION           0x00000803 // x2APIC Version Register (R/O)
#define MSR_IA32_X2APIC_TPR               0x00000808 // x2APIC Task Priority Register (R/W)
#define MSR_IA32_X2APIC_PPR               0x0000080A // x2APIC Processor Priority Register (R/O)
#define MSR_IA32_X2APIC_EOI               0x0000080B // x2APIC EOI Register (W/O)
#define MSR_IA32_X2APIC_LDR               0x0000080D // x2APIC Logical Destination Register (R/O)
#define MSR_IA32_X2APIC_SIVR              0x0000080F // x2APIC Spurious Interrupt Vector Register (R/W)
#define MSR_IA32_X2APIC_ISR0              0x00000810 // x2APIC In-Service Register Bits 31:0 (R/O)
#define MSR_IA32_X2APIC_ISR1              0x00000811 // x2APIC In-Service Register Bits 63:32 (R/O) If CPUID.01H:ECX.[21] = 1
#define MSR_IA32_X2APIC_ISR2              0x00000812 // x2APIC In-Service Register Bits 95:64 (R/O) If CPUID.01H:ECX.[21] = 1
#define MSR_IA32_X2APIC_ISR3              0x00000813 // x2APIC In-Service Register Bits 127:96 (R/O)
#define MSR_IA32_X2APIC_ISR4              0x00000814 // x2APIC In-Service Register Bits 159:128 (R/O)
#define MSR_IA32_X2APIC_ISR5              0x00000815 // x2APIC In-Service Register Bits 191:160 (R/O)
#define MSR_IA32_X2APIC_ISR6              0x00000816 // x2APIC In-Service Register Bits 223:192 (R/O)
#define MSR_IA32_X2APIC_ISR7              0x00000817 // x2APIC In-Service Register Bits 255:224 (R/O)
#define MSR_IA32_X2APIC_TMR0              0x00000818 // x2APIC Trigger Mode Register Bits 31:0 (R/O)
#define MSR_IA32_X2APIC_TMR1              0x00000819 // x2APIC Trigger Mode Register Bits 63:32 (R/O)
#define MSR_IA32_X2APIC_TMR2              0x0000081A // x2APIC Trigger Mode Register Bits 95:64 (R/O)
#define MSR_IA32_X2APIC_TMR3              0x0000081B // x2APIC Trigger Mode Register Bits 127:96 (R/O)
#define MSR_IA32_X2APIC_TMR4              0x0000081C // x2APIC Trigger Mode Register Bits 159:128 (R/O)
#define MSR_IA32_X2APIC_TMR5              0x0000081D // x2APIC Trigger Mode Register Bits 191:160 (R/O)
#define MSR_IA32_X2APIC_TMR6              0x0000081E // x2APIC Trigger Mode Register Bits 223:192 (R/O)
#define MSR_IA32_X2APIC_TMR7              0x0000081F // x2APIC Trigger Mode Register Bits 255:224 (R/O)
#define MSR_IA32_X2APIC_IRR0              0x00000820 // x2APIC Interrupt Request Register Bits 31:0 (R/O)
#define MSR_IA32_X2APIC_IRR1              0x00000821 // x2APIC Interrupt Request Register Bits 63:32 (R/O)
#define MSR_IA32_X2APIC_IRR2              0x00000822 // x2APIC Interrupt Request Register Bits 95:64 (R/O)
#define MSR_IA32_X2APIC_IRR3              0x00000823 // x2APIC Interrupt Request Register Bits 127:96 (R/O)
#define MSR_IA32_X2APIC_IRR4              0x00000824 // x2APIC Interrupt Request Register Bits 159:128 (R/O)
#define MSR_IA32_X2APIC_IRR5              0x00000825 // x2APIC Interrupt Request Register Bits 191:160 (R/O)
#define MSR_IA32_X2APIC_IRR6              0x00000826 // x2APIC Interrupt Request Register Bits 223:192 (R/O)
#define MSR_IA32_X2APIC_IRR7              0x00000827 // x2APIC Interrupt Request Register Bits 255:224 (R/O)
#define MSR_IA32_X2APIC_ESR               0x00000828 // x2APIC Error Status Register (R/W)
#define MSR_IA32_X2APIC_LVT_CMCI          0x0000082F // x2APIC LVT Corrected Machine Check Interrupt Register (R/W)
#define MSR_IA32_X2APIC_ICR               0x00000830 // x2APIC Interrupt Command Register (R/W)
#define MSR_IA32_X2APIC_LVT_TIMER         0x00000832 // x2APIC LVT Timer Interrupt Register (R/W) If CPUID.01H:ECX.[21] = 1
#define MSR_IA32_X2APIC_LVT_THERMAL       0x00000833 // x2APIC LVT Thermal Sensor Interrupt Register (R/W)
#define MSR_IA32_X2APIC_LVT_PMI           0x00000834 // x2APIC LVT Performance Monitor Interrupt Register (R/W)
#define MSR_IA32_X2APIC_LVT_LINT0         0x00000835 // x2APIC LVT LINT0 Register (R/W)
#define MSR_IA32_X2APIC_LVT_LINT1         0x00000836 // x2APIC LVT LINT1 Register (R/W)
#define MSR_IA32_X2APIC_LVT_ERROR         0x00000837 // x2APIC LVT Error Register (R/W)
#define MSR_IA32_X2APIC_INIT_COUNT        0x00000838 // x2APIC Initial Count Register (R/W)
#define MSR_IA32_X2APIC_CUR_COUNT         0x00000839 // x2APIC Current Count Register (R/O)
#define MSR_IA32_X2APIC_DIV_CONF          0x0000083E // x2APIC Divide Configuration Register (R/W) If CPUID.01H:ECX.[21] = 1
#define MSR_IA32_X2APIC_SELF_IPI          0x0000083F // x2APIC Self IPI Register (W/O)
#define MSR_IA32_TME_CAPABILITY           0x00000981 // Memory Encryption Capability MSR
#define MSR_IA32_TME_ACTIVATE             0x00000982 // Memory Encryption Activation MSR This MSR is used to lock the MSRs listed below. Any write to the following MSRs will be ignored after they are locked. The lock is reset when CPU is reset. • IA32_TME_ACTIVATE • IA32_TME_EXCLUDE_MASK • IA32_TME_EXCLUDE_BASE Note that IA32_TME_EXCLUDE_MASK and IA32_TME_EXCLUDE_BASE must be configured before IA32_TME_ACTIVATE.
#define MSR_IA32_TME_EXCLUDE_MASK         0x00000983 // Memory Encryption Exclude Mask
#define MSR_IA32_TME_EXCLUDE_BASE         0x00000984 // Memory Encryption Exclude Base
#define MSR_IA32_COPY_STATUS              0x00000990 // Status of Most Recent Platform to Local or Local to Platform Copies (R/O)
#define MSR_IA32_IWKEYBACKUP_STATUS       0x00000991 // Information about IWKeyBackup Register (R/O)
#define MSR_IA32_DEBUG_INTERFACE          0x00000C80 // Silicon Debug Feature Control (R/W)
#define MSR_IA32_L3_QOS_CFG               0x00000C81 // L3 QOS Configuration (R/W)
#define MSR_IA32_L2_QOS_CFG               0x00000C82 // L2 QOS Configuration (R/W)
#define MSR_IA32_QM_EVTSEL                0x00000C8D // Monitoring Event Select Register (R/W)
#define MSR_IA32_QM_CTR                   0x00000C8E // Monitoring Counter Register (R/O)
#define MSR_IA32_PQR_ASSOC                0x00000C8F // Resource Association Register (R/W)
#define MSR_IA32_L3_MASK_0                0x00000C90 // L3 CAT Mask for COS0 (R/W)
#define MSR_IA32_L2_MASK_0                0x00000D10 // L2 CAT Mask for COS0 (R/W)
#define MSR_IA32_BNDCFGS                  0x00000D90 // Supervisor State of MPX Configuration (R/W)
#define MSR_IA32_COPY_LOCAL_TO_PLATFORM   0x00000D91 // Copy Local State to Platform State (W)
#define MSR_IA32_COPY_PLATFORM_TO_LOCAL   0x00000D92 // Copy Platform State to Local State (W)
#define MSR_IA32_XSS                      0x00000DA0 // Extended Supervisor State Mask (R/W)
#define MSR_IA32_PKG_HDC_CTL              0x00000DB0 // Package Level Enable/disable HDC (R/W)
#define MSR_IA32_PM_CTL1                  0x00000DB1 // Enable/disable HWP (R/W)
#define MSR_IA32_THREAD_STALL             0x00000DB2 // Per-Logical_Processor HDC Idle Residency (R/0)
#define MSR_IA32_LBR_1200_INFO            0x00001200 // Last Branch Record Entry 1200 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1201_INFO            0x00001201 // Last Branch Record Entry 1201 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1202_INFO            0x00001202 // Last Branch Record Entry 1202 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1203_INFO            0x00001203 // Last Branch Record Entry 1203 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1204_INFO            0x00001204 // Last Branch Record Entry 1204 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1205_INFO            0x00001205 // Last Branch Record Entry 1205 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1206_INFO            0x00001206 // Last Branch Record Entry 1206 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1207_INFO            0x00001207 // Last Branch Record Entry 1207 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1208_INFO            0x00001208 // Last Branch Record Entry 1208 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1209_INFO            0x00001209 // Last Branch Record Entry 1209 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_120A_INFO            0x0000120A // Last Branch Record Entry 120A Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_120B_INFO            0x0000120B // Last Branch Record Entry 120B Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_120C_INFO            0x0000120C // Last Branch Record Entry 120C Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_120D_INFO            0x0000120D // Last Branch Record Entry 120D Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_120E_INFO            0x0000120E // Last Branch Record Entry 120E Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_120F_INFO            0x0000120F // Last Branch Record Entry 120F Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1210_INFO            0x00001210 // Last Branch Record Entry 1210 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1211_INFO            0x00001211 // Last Branch Record Entry 1211 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1212_INFO            0x00001212 // Last Branch Record Entry 1212 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1213_INFO            0x00001213 // Last Branch Record Entry 1213 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1214_INFO            0x00001214 // Last Branch Record Entry 1214 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1215_INFO            0x00001215 // Last Branch Record Entry 1215 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1216_INFO            0x00001216 // Last Branch Record Entry 1216 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1217_INFO            0x00001217 // Last Branch Record Entry 1217 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1218_INFO            0x00001218 // Last Branch Record Entry 1218 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1219_INFO            0x00001219 // Last Branch Record Entry 1219 Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_121A_INFO            0x0000121A // Last Branch Record Entry 121A Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_121B_INFO            0x0000121B // Last Branch Record Entry 121B Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_121C_INFO            0x0000121C // Last Branch Record Entry 121C Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_121D_INFO            0x0000121D // Last Branch Record Entry 121D Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_121E_INFO            0x0000121E // Last Branch Record Entry 121E Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_121F_INFO            0x0000121F // Last Branch Record Entry 121F Info Register (R/W) An attempt to read or write IA32_LBR_x_INFO such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_CTL                  0x000014CE // Last Branch Record Enabling and Configuration Register (R/W)
#define MSR_IA32_LBR_DEPTH                0x000014CF // Last Branch Record Maximum Stack Depth Register (R/W)
#define MSR_IA32_LBR_1500_FROM_IP         0x00001500 // Last Branch Record entry 1500 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1501_FROM_IP         0x00001501 // Last Branch Record entry 1501 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1502_FROM_IP         0x00001502 // Last Branch Record entry 1502 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1503_FROM_IP         0x00001503 // Last Branch Record entry 1503 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1504_FROM_IP         0x00001504 // Last Branch Record entry 1504 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1505_FROM_IP         0x00001505 // Last Branch Record entry 1505 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1506_FROM_IP         0x00001506 // Last Branch Record entry 1506 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1507_FROM_IP         0x00001507 // Last Branch Record entry 1507 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1508_FROM_IP         0x00001508 // Last Branch Record entry 1508 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1509_FROM_IP         0x00001509 // Last Branch Record entry 1509 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_150A_FROM_IP         0x0000150A // Last Branch Record entry 150A source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_150B_FROM_IP         0x0000150B // Last Branch Record entry 150B source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_150C_FROM_IP         0x0000150C // Last Branch Record entry 150C source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_150D_FROM_IP         0x0000150D // Last Branch Record entry 150D source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_150E_FROM_IP         0x0000150E // Last Branch Record entry 150E source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_150F_FROM_IP         0x0000150F // Last Branch Record entry 150F source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1510_FROM_IP         0x00001510 // Last Branch Record entry 1510 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1511_FROM_IP         0x00001511 // Last Branch Record entry 1511 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1512_FROM_IP         0x00001512 // Last Branch Record entry 1512 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1513_FROM_IP         0x00001513 // Last Branch Record entry 1513 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1514_FROM_IP         0x00001514 // Last Branch Record entry 1514 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1515_FROM_IP         0x00001515 // Last Branch Record entry 1515 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1516_FROM_IP         0x00001516 // Last Branch Record entry 1516 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1517_FROM_IP         0x00001517 // Last Branch Record entry 1517 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1518_FROM_IP         0x00001518 // Last Branch Record entry 1518 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1519_FROM_IP         0x00001519 // Last Branch Record entry 1519 source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_151A_FROM_IP         0x0000151A // Last Branch Record entry 151A source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_151B_FROM_IP         0x0000151B // Last Branch Record entry 151B source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_151C_FROM_IP         0x0000151C // Last Branch Record entry 151C source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_151D_FROM_IP         0x0000151D // Last Branch Record entry 151D source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_151E_FROM_IP         0x0000151E // Last Branch Record entry 151E source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_151F_FROM_IP         0x0000151F // Last Branch Record entry 151F source IP register (R/W). An attempt to read or write IA32_LBR_x_FROM_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1600_TO_IP           0x00001600 // Last Branch Record Entry 1600 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1601_TO_IP           0x00001601 // Last Branch Record Entry 1601 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1602_TO_IP           0x00001602 // Last Branch Record Entry 1602 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1603_TO_IP           0x00001603 // Last Branch Record Entry 1603 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1604_TO_IP           0x00001604 // Last Branch Record Entry 1604 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1605_TO_IP           0x00001605 // Last Branch Record Entry 1605 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1606_TO_IP           0x00001606 // Last Branch Record Entry 1606 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1607_TO_IP           0x00001607 // Last Branch Record Entry 1607 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1608_TO_IP           0x00001608 // Last Branch Record Entry 1608 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1609_TO_IP           0x00001609 // Last Branch Record Entry 1609 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_160A_TO_IP           0x0000160A // Last Branch Record Entry 160A Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_160B_TO_IP           0x0000160B // Last Branch Record Entry 160B Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_160C_TO_IP           0x0000160C // Last Branch Record Entry 160C Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_160D_TO_IP           0x0000160D // Last Branch Record Entry 160D Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_160E_TO_IP           0x0000160E // Last Branch Record Entry 160E Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_160F_TO_IP           0x0000160F // Last Branch Record Entry 160F Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1610_TO_IP           0x00001610 // Last Branch Record Entry 1610 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1611_TO_IP           0x00001611 // Last Branch Record Entry 1611 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1612_TO_IP           0x00001612 // Last Branch Record Entry 1612 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1613_TO_IP           0x00001613 // Last Branch Record Entry 1613 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1614_TO_IP           0x00001614 // Last Branch Record Entry 1614 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1615_TO_IP           0x00001615 // Last Branch Record Entry 1615 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1616_TO_IP           0x00001616 // Last Branch Record Entry 1616 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1617_TO_IP           0x00001617 // Last Branch Record Entry 1617 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1618_TO_IP           0x00001618 // Last Branch Record Entry 1618 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_1619_TO_IP           0x00001619 // Last Branch Record Entry 1619 Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_161A_TO_IP           0x0000161A // Last Branch Record Entry 161A Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_161B_TO_IP           0x0000161B // Last Branch Record Entry 161B Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_161C_TO_IP           0x0000161C // Last Branch Record Entry 161C Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_161D_TO_IP           0x0000161D // Last Branch Record Entry 161D Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_161E_TO_IP           0x0000161E // Last Branch Record Entry 161E Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_LBR_161F_TO_IP           0x0000161F // Last Branch Record Entry 161F Destination IP Register (R/W) An attempt to read or write IA32_LBR_x_TO_IP such that x >= IA32_LBR_DEPTH.DEPTH will #GP.
#define MSR_IA32_HW_FEEDBACK_PTR          0x000017D0 // Hardware Feedback Interface Pointer
#define MSR_IA32_HW_FEEDBACK_CONFIG       0x000017D1 // Hardware Feedback Interface Configuration If CPUID.06H:EAX.[19] = 1
#define MSR_IA32_THREAD_FEEDBACK_CHAR     0x000017D2 // Thread Feedback Characteristics (R/O)
#define MSR_IA32_HW_FEEDBACK_THREAD_CONFI 0x000017D4 // Hardware Feedback Thread Configuration (R/W)
#define MSR_IA32_HRESET_ENABLE            0x000017DA // History Reset Enable (R/W)
#define MSR_IA32_EFER                     0xC0000080 // Extended Feature Enables
#define MSR_IA32_LSTAR                    0xC0000082 // IA-32e Mode System Call Target Address (R/W) Target RIP for the called procedure when SYSCALL is executed in 64-bit mode.
#define MSR_IA32_CSTAR                    0xC0000083 // IA-32e Mode System Call Target Address (R/W) Not used, as the SYSCALL instruction is not recognized in compatibility mode.
#define MSR_IA32_FMASK                    0xC0000084 // System Call Flag Mask (R/W)
#define MSR_IA32_FS_BASE                  0xC0000100 // Map of BASE Address of FS (R/W)
#define MSR_IA32_GS_BASE                  0xC0000101 // Map of BASE Address of GS (R/W)
#define MSR_IA32_KERNEL_GS_BASE           0xC0000102 // Swap Target of BASE Address of GS (R/W)
#define MSR_IA32_TSC_AUX                  0xC0000103 // Auxiliary TSC (R/W)
#define MSR_KVM_CLOCKSOURCE_WALL_CLOCK    0x00000011 // KVM clock 1 wall clock
#define MSR_KVM_CLOCKSOURCE_SYSTEM_TIME   0x00000012 // KVM clock 1 system time
#define MSR_KVM_CLOCKSOURCE2_WALL_CLOCK   0x4B564D00 // KVM clock 2 wall clock
#define MSR_KVM_CLOCKSOURCE2_SYSTEM_TIME  0x4B564D01 // KVM clock 2 system time



#endif // COM_NGOS_SHARED_COMMON_MSR_LIB_GENERATED_MSRREGISTERS_H
