// This file generated with the code_generator
// Please do not modify it manually
#include "x86featuresnames.h"



const good_Char8* x86FeaturesNames[static_cast<good_Enum_t>(x86FeatureWord::MAXIMUM) * 32] =
{
    // word 0

    "sse3",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 0)         // X86Feature::XMM3
    "pclmulqdq",             // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 1)         // X86Feature::PCLMULQDQ
    "dtes64",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 2)         // X86Feature::DTES64
    "monitor",               // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 3)         // X86Feature::MWAIT
    "ds_cpl",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 4)         // X86Feature::DSCPL
    "vmx",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 5)         // X86Feature::VMX
    "smx",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 6)         // X86Feature::SMX
    "est",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 7)         // X86Feature::EST
    "tm2",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 8)         // X86Feature::TM2
    "ssse3",                 // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 9)         // X86Feature::SSSE3
    "cid",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 10)        // X86Feature::CID
    "sdbg",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 11)        // X86Feature::SDBG
    "fma",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 12)        // X86Feature::FMA
    "cx16",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 13)        // X86Feature::CX16
    "xtpr",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 14)        // X86Feature::XTPR
    "pdcm",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 15)        // X86Feature::PDCM
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 16)
    "pcid",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 17)        // X86Feature::PCID
    "dca",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 18)        // X86Feature::DCA
    "sse4_1",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 19)        // X86Feature::XMM4_1
    "sse4_2",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 20)        // X86Feature::XMM4_2
    "x2apic",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 21)        // X86Feature::X2APIC
    "movbe",                 // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 22)        // X86Feature::MOVBE
    "popcnt",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 23)        // X86Feature::POPCNT
    "tsc_deadline_timer",    // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 24)        // X86Feature::TSC_DEADLINE_TIMER
    "aes",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 25)        // X86Feature::AES
    "xsave",                 // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 26)        // X86Feature::XSAVE
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 27)        // X86Feature::OSXSAVE
    "avx",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 28)        // X86Feature::AVX
    "f16c",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 29)        // X86Feature::F16C
    "rdrand",                // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 30)        // X86Feature::RDRAND
    "hypervisor",            // WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 31)        // X86Feature::HYPERVISOR

    // word 1

    "fpu",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 0)         // X86Feature::FPU
    "vme",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 1)         // X86Feature::VME
    "de",                    // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 2)         // X86Feature::DE
    "pse",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 3)         // X86Feature::PSE
    "tsc",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 4)         // X86Feature::TSC
    "msr",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 5)         // X86Feature::MSR
    "pae",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 6)         // X86Feature::PAE
    "mce",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 7)         // X86Feature::MCE
    "cx8",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 8)         // X86Feature::CX8
    "apic",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 9)         // X86Feature::APIC
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 10)
    "sep",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 11)        // X86Feature::SEP
    "mtrr",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 12)        // X86Feature::MTRR
    "pge",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 13)        // X86Feature::PGE
    "mca",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 14)        // X86Feature::MCA
    "cmov",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 15)        // X86Feature::CMOV
    "pat",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 16)        // X86Feature::PAT
    "pse36",                 // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 17)        // X86Feature::PSE36
    "pn",                    // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 18)        // X86Feature::PN
    "clflush",               // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 19)        // X86Feature::CLFLUSH
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 20)
    "dts",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 21)        // X86Feature::DS
    "acpi",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 22)        // X86Feature::ACPI
    "mmx",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 23)        // X86Feature::MMX
    "fxsr",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 24)        // X86Feature::FXSR
    "sse",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 25)        // X86Feature::XMM
    "sse2",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 26)        // X86Feature::XMM2
    "ss",                    // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 27)        // X86Feature::SELFSNOOP
    "ht",                    // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 28)        // X86Feature::HT
    "tm",                    // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 29)        // X86Feature::ACC
    "ia64",                  // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 30)        // X86Feature::IA64
    "pbe",                   // WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 31)        // X86Feature::PBE

    // word 2

    "dtherm",                // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 0)         // X86Feature::DTHERM
    "ida",                   // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 1)         // X86Feature::IDA
    "arat",                  // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 2)         // X86Feature::ARAT
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 3)
    "pln",                   // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 4)         // X86Feature::PLN
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 5)
    "pts",                   // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 6)         // X86Feature::PTS
    "hwp",                   // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 7)         // X86Feature::HWP
    "hwp_notify",            // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 8)         // X86Feature::HWP_NOTIFY
    "hwp_act_window",        // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 9)         // X86Feature::HWP_ACT_WINDOW
    "hwp_epp",               // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 10)        // X86Feature::HWP_EPP
    "hwp_pkg_req",           // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 11)        // X86Feature::HWP_PKG_REQ
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 26)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 31)

    // word 3

    "fsgsbase",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 0)         // X86Feature::FSGSBASE
    "tsc_adjust",            // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 1)         // X86Feature::TSC_ADJUST
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 2)
    "bmi1",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 3)         // X86Feature::BMI1
    "hle",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 4)         // X86Feature::HLE
    "avx2",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 5)         // X86Feature::AVX2
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 6)
    "smep",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 7)         // X86Feature::SMEP
    "bmi2",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 8)         // X86Feature::BMI2
    "erms",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 9)         // X86Feature::ERMS
    "invpcid",               // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 10)        // X86Feature::INVPCID
    "rtm",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 11)        // X86Feature::RTM
    "cqm",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 12)        // X86Feature::CQM
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 13)
    "mpx",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 14)        // X86Feature::MPX
    "rdt_a",                 // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 15)        // X86Feature::RDT_A
    "avx512f",               // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 16)        // X86Feature::AVX512F
    "avx512dq",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 17)        // X86Feature::AVX512DQ
    "rdseed",                // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 18)        // X86Feature::RDSEED
    "adx",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 19)        // X86Feature::ADX
    "smap",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 20)        // X86Feature::SMAP
    "avx512ifma",            // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 21)        // X86Feature::AVX512IFMA
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 22)
    "clflushopt",            // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 23)        // X86Feature::CLFLUSHOPT
    "clwb",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 24)        // X86Feature::CLWB
    "intel_pt",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 25)        // X86Feature::INTEL_PT
    "avx512pf",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 26)        // X86Feature::AVX512PF
    "avx512er",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 27)        // X86Feature::AVX512ER
    "avx512cd",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 28)        // X86Feature::AVX512CD
    "sha_ni",                // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 29)        // X86Feature::SHA_NI
    "avx512bw",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 30)        // X86Feature::AVX512BW
    "avx512vl",              // WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 31)        // X86Feature::AVX512VL

    // word 4

    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 0)
    "avx512vbmi",            // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 1)         // X86Feature::AVX512VBMI
    "umip",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 2)         // X86Feature::UMIP
    "pku",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 3)         // X86Feature::PKU
    "ospke",                 // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 4)         // X86Feature::OSPKE
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 5)
    "avx512_vbmi2",          // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 6)         // X86Feature::AVX512_VBMI2
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 7)
    "gfni",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 8)         // X86Feature::GFNI
    "vaes",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 9)         // X86Feature::VAES
    "vpclmulqdq",            // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 10)        // X86Feature::VPCLMULQDQ
    "avx512_vnni",           // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 11)        // X86Feature::AVX512_VNNI
    "avx512_bitalg",         // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 12)        // X86Feature::AVX512_BITALG
    "tme",                   // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 13)        // X86Feature::TME
    "avx512_vpopcntdq",      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 14)        // X86Feature::AVX512_VPOPCNTDQ
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 15)
    "la57",                  // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 16)        // X86Feature::LA57
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 21)
    "rdpid",                 // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 22)        // X86Feature::RDPID
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 24)
    "cldemote",              // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 25)        // X86Feature::CLDEMOTE
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 26)
    "movdiri",               // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 27)        // X86Feature::MOVDIRI
    "movdir64b",             // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 28)        // X86Feature::MOVDIR64B
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 31)

    // word 5

    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 0)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 1)
    "avx512_4vnniw",         // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 2)         // X86Feature::AVX512_4VNNIW
    "avx512_4fmaps",         // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 3)         // X86Feature::AVX512_4FMAPS
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 10)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 11)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 17)
    "pconfig",               // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 18)        // X86Feature::PCONFIG
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 26)        // X86Feature::SPEC_CTRL
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 27)        // X86Feature::INTEL_STIBP
    "flush_l1d",             // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 28)        // X86Feature::FLUSH_L1D
    "arch_capabilities",     // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 29)        // X86Feature::ARCH_CAPABILITIES
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 31)        // X86Feature::SPEC_CTRL_SSBD

    // word 6

    "xsaveopt",              // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 0)       // X86Feature::XSAVEOPT
    "xsavec",                // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 1)       // X86Feature::XSAVEC
    "xgetbv1",               // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 2)       // X86Feature::XGETBV1
    "xsaves",                // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 3)       // X86Feature::XSAVES
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 10)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 11)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 26)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 31)

    // word 7

    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 0)
    "cqm_llc",               // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 1)       // X86Feature::CQM_LLC
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 2)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 3)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 10)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 11)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 26)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 31)

    // word 8

    "cqm_occup_llc",         // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 0)       // X86Feature::CQM_OCCUP_LLC
    "cqm_mbm_total",         // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 1)       // X86Feature::CQM_MBM_TOTAL
    "cqm_mbm_local",         // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 2)       // X86Feature::CQM_MBM_LOCAL
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 3)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 10)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 11)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 26)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 31)

    // word 9

    "lahf_lm",               // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 0)         // X86Feature::LAHF_LM
    "cmp_legacy",            // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 1)         // X86Feature::CMP_LEGACY
    "svm",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 2)         // X86Feature::SVM
    "extapic",               // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 3)         // X86Feature::EXTAPIC
    "cr8_legacy",            // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 4)         // X86Feature::CR8_LEGACY
    "abm",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 5)         // X86Feature::ABM
    "sse4a",                 // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 6)         // X86Feature::SSE4A
    "misalignsse",           // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 7)         // X86Feature::MISALIGNSSE
    "3dnowprefetch",         // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 8)         // X86Feature::_3DNOWPREFETCH
    "osvw",                  // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 9)         // X86Feature::OSVW
    "ibs",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 10)        // X86Feature::IBS
    "xop",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 11)        // X86Feature::XOP
    "skinit",                // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 12)        // X86Feature::SKINIT
    "wdt",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 13)        // X86Feature::WDT
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 14)
    "lwp",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 15)        // X86Feature::LWP
    "fma4",                  // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 16)        // X86Feature::FMA4
    "tce",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 17)        // X86Feature::TCE
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 18)
    "nodeid_msr",            // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 19)        // X86Feature::NODEID_MSR
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 20)
    "tbm",                   // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 21)        // X86Feature::TBM
    "topoext",               // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 22)        // X86Feature::TOPOEXT
    "perfctr_core",          // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 23)        // X86Feature::PERFCTR_CORE
    "perfctr_nb",            // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 24)        // X86Feature::PERFCTR_NB
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 25)
    "bpext",                 // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 26)        // X86Feature::BPEXT
    "ptsc",                  // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 27)        // X86Feature::PTSC
    "perfctr_llc",           // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 28)        // X86Feature::PERFCTR_LLC
    "mwaitx",                // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 29)        // X86Feature::MWAITX
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 31)

    // word 10

    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 0)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 1)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 2)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 3)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 10)
    "syscall",               // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 11)        // X86Feature::SYSCALL
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 18)
    "mp",                    // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 19)        // X86Feature::MP
    "nx",                    // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 20)        // X86Feature::NX
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 21)
    "mmxext",                // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 22)        // X86Feature::MMXEXT
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 24)
    "fxsr_opt",              // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 25)        // X86Feature::FXSR_OPT
    "pdpe1gb",               // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 26)        // X86Feature::GBPAGES
    "rdtscp",                // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 27)        // X86Feature::RDTSCP
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 28)
    "lm",                    // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 29)        // X86Feature::LM
    "3dnowext",              // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 30)        // X86Feature::_3DNOWEXT
    "3dnow",                 // WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 31)        // X86Feature::_3DNOW

    // word 11

    "overflow_recov",        // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 0)         // X86Feature::OVERFLOW_RECOV
    "succor",                // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 1)         // X86Feature::SUCCOR
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 2)
    "smca",                  // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 3)         // X86Feature::SMCA
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 10)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 11)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 12)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 14)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 15)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 26)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 31)

    // word 12

    "clzero",                // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 0)         // X86Feature::CLZERO
    "irperf",                // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 1)         // X86Feature::IRPERF
    "xsaveerptr",            // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 2)         // X86Feature::XSAVEERPTR
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 3)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 4)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 5)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 6)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 7)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 9)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 10)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 11)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 12)        // X86Feature::AMD_IBPB
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 13)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 14)        // X86Feature::AMD_IBRS
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 15)        // X86Feature::AMD_STIBP
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 16)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 24)        // X86Feature::AMD_SSBD
    "virt_ssbd",             // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 25)        // X86Feature::VIRT_SSBD
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 26)        // X86Feature::AMD_SSB_NO
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 31)

    // word 13

    "npt",                   // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 0)         // X86Feature::NPT
    "lbrv",                  // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 1)         // X86Feature::LBRV
    "svm_lock",              // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 2)         // X86Feature::SVML
    "nrip_save",             // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 3)         // X86Feature::NRIPS
    "tsc_scale",             // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 4)         // X86Feature::TSCRATEMSR
    "vmcb_clean",            // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 5)         // X86Feature::VMCBCLEAN
    "flushbyasid",           // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 6)         // X86Feature::FLUSHBYASID
    "decodeassists",         // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 7)         // X86Feature::DECODEASSISTS
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 8)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 9)
    "pausefilter",           // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 10)        // X86Feature::PAUSEFILTER
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 11)
    "pfthreshold",           // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 12)        // X86Feature::PFTHRESHOLD
    "avic",                  // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 13)        // X86Feature::AVIC
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 14)
    "v_vmsave_vmload",       // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 15)        // X86Feature::V_VMSAVE_VMLOAD
    "vgif",                  // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 16)        // X86Feature::VGIF
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 17)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 18)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 19)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 20)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 21)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 22)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 23)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 24)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 25)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 26)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 27)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 28)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 29)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 30)
    "",                      // WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 31)

    // word 14

    "aperfmperf",            // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 0)    // X86Feature::APERFMPERF
    "epb",                   // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 1)    // X86Feature::EPB
    "cat_l3",                // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 2)    // X86Feature::CAT_L3
    "cat_l2",                // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 3)    // X86Feature::CAT_L2
    "mba",                   // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 4)    // X86Feature::MBA
    "cdp_l3",                // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 5)    // X86Feature::CDP_L3
    "cdp_l2",                // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 6)    // X86Feature::CDP_L2
    "hw_pstate",             // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 7)    // X86Feature::HW_PSTATE
    "cpb",                   // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 8)    // X86Feature::CPB
    "proc_feedback",         // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 9)    // X86Feature::PROC_FEEDBACK
    "sme",                   // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 10)   // X86Feature::SME
    "sev",                   // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 11)   // X86Feature::SEV
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 12)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 13)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 14)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 15)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 16)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 17)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 18)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 19)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 20)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 21)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 22)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 23)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 24)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 25)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 26)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 27)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 28)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 29)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 30)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_SCATTERED_FEATURES, 31)

    // word 15

    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 0)        // X86Feature::ALWAYS_ZERO
    "cpuid",                 // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 1)        // X86Feature::CPUID
    "constant_tsc",          // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 2)        // X86Feature::CONSTANT_TSC
    "nonstop_tsc",           // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 3)        // X86Feature::NONSTOP_TSC
    "nonstop_tsc_s3",        // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 4)        // X86Feature::NONSTOP_TSC_S3
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 5)        // X86Feature::MSR_SPEC_CTRL
    "ibrs",                  // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 6)        // X86Feature::IBRS
    "ibpb",                  // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 7)        // X86Feature::IBPB
    "stibp",                 // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 8)        // X86Feature::STIBP
    "ssbd",                  // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 9)        // X86Feature::SSBD
    "ibrs_enhanced",         // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 10)       // X86Feature::IBRS_ENHANCED
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 11)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 12)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 13)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 14)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 15)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 16)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 17)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 18)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 19)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 20)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 21)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 22)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 23)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 24)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 25)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 26)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 27)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 28)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 29)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 30)
    "",                      // WORD_BIT(x86FeatureWord::NGOS_OTHER_FEATURES, 31)
};
