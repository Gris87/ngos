// This file generated with the code_generator
// Please do not modify it manually
#include "x86featuresnames.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/utils.h>



const char8* x86FeaturesNames[(u64)x86FeatureWord::MAXIMUM * 32];



NgosStatus initX86FeaturesNames()
{
    COMMON_LT((""));



    // word 0

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 0)]  = "sse3";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 1)]  = "pclmulqdq";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 2)]  = "dtes64";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 3)]  = "monitor";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 4)]  = "ds_cpl";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 5)]  = "vmx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 6)]  = "smx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 7)]  = "est";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 8)]  = "tm2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 9)]  = "ssse3";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 10)] = "cid";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 11)] = "sdbg";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 12)] = "fma";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 13)] = "cx16";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 14)] = "xtpr";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 15)] = "pdcm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 17)] = "pcid";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 18)] = "dca";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 19)] = "sse4_1";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 20)] = "sse4_2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 21)] = "x2apic";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 22)] = "movbe";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 23)] = "popcnt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 24)] = "tsc_deadline_timer";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 25)] = "aes";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 26)] = "xsave";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 28)] = "avx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 29)] = "f16c";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 30)] = "rdrand";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 31)] = "hypervisor";

    // word 1

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 0)]  = "fpu";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 1)]  = "vme";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 2)]  = "de";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 3)]  = "pse";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 4)]  = "tsc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 5)]  = "msr";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 6)]  = "pae";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 7)]  = "mce";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 8)]  = "cx8";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 9)]  = "apic";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 11)] = "sep";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 12)] = "mtrr";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 13)] = "pge";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 14)] = "mca";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 15)] = "cmov";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 16)] = "pat";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 17)] = "pse36";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 18)] = "pn";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 19)] = "clflush";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 21)] = "dts";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 22)] = "acpi";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 23)] = "mmx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 24)] = "fxsr";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 25)] = "sse";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 26)] = "sse2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 27)] = "ss";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 28)] = "ht";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 29)] = "tm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 30)] = "ia64";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 31)] = "pbe";

    // word 2

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 0)]  = "dtherm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 1)]  = "ida";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 2)]  = "arat";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 3)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 4)]  = "pln";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 6)]  = "pts";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 7)]  = "hwp";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 8)]  = "hwp_notify";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 9)]  = "hwp_act_window";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 10)] = "hwp_epp";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 11)] = "hwp_pkg_req";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 31)] = "";

    // word 3

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 0)]  = "fsgsbase";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 1)]  = "tsc_adjust";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 2)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 3)]  = "bmi1";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 4)]  = "hle";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 5)]  = "avx2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 7)]  = "smep";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 8)]  = "bmi2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 9)]  = "erms";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 10)] = "invpcid";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 11)] = "rtm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 12)] = "cqm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 14)] = "mpx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 15)] = "rdt_a";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 16)] = "avx512f";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 17)] = "avx512dq";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 18)] = "rdseed";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 19)] = "adx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 20)] = "smap";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 21)] = "avx512ifma";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 23)] = "clflushopt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 24)] = "clwb";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 25)] = "intel_pt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 26)] = "avx512pf";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 27)] = "avx512er";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 28)] = "avx512cd";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 29)] = "sha_ni";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 30)] = "avx512bw";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 31)] = "avx512vl";

    // word 4

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 0)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 1)]  = "avx512vbmi";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 2)]  = "umip";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 3)]  = "pku";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 4)]  = "ospke";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 6)]  = "avx512_vbmi2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 8)]  = "gfni";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 9)]  = "vaes";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 10)] = "vpclmulqdq";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 11)] = "avx512_vnni";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 12)] = "avx512_bitalg";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 13)] = "tme";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 14)] = "avx512_vpopcntdq";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 16)] = "la57";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 22)] = "rdpid";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 25)] = "cldemote";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 27)] = "movdiri";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 28)] = "movdir64b";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 31)] = "";

    // word 5

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 0)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 1)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 2)]  = "avx512_4vnniw";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 3)]  = "avx512_4fmaps";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 18)] = "pconfig";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 28)] = "flush_l1d";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 29)] = "arch_capabilities";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 31)] = "";

    // word 6

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 0)]  = "xsaveopt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 1)]  = "xsavec";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 2)]  = "xgetbv1";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 3)]  = "xsaves";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 31)] = "";

    // word 7

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 0)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 1)]  = "cqm_llc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 2)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 3)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 31)] = "";

    // word 8

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 0)]  = "cqm_occup_llc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 1)]  = "cqm_mbm_total";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 2)]  = "cqm_mbm_local";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 3)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 31)] = "";

    // word 9

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 0)]  = "lahf_lm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 1)]  = "cmp_legacy";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 2)]  = "svm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 3)]  = "extapic";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 4)]  = "cr8_legacy";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 5)]  = "abm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 6)]  = "sse4a";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 7)]  = "misalignsse";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 8)]  = "3dnowprefetch";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 9)]  = "osvw";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 10)] = "ibs";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 11)] = "xop";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 12)] = "skinit";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 13)] = "wdt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 15)] = "lwp";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 16)] = "fma4";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 17)] = "tce";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 19)] = "nodeid_msr";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 21)] = "tbm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 22)] = "topoext";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 23)] = "perfctr_core";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 24)] = "perfctr_nb";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 26)] = "bpext";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 27)] = "ptsc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 28)] = "perfctr_llc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 29)] = "mwaitx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 31)] = "";

    // word 10

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 0)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 1)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 2)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 3)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 11)] = "syscall";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 19)] = "mp";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 20)] = "nx";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 22)] = "mmxext";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 25)] = "fxsr_opt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 26)] = "pdpe1gb";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 27)] = "rdtscp";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 29)] = "lm";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 30)] = "3dnowext";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 31)] = "3dnow";

    // word 11

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 0)]  = "overflow_recov";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 1)]  = "succor";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 2)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 3)]  = "smca";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 31)] = "";

    // word 12

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 0)]  = "clzero";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 1)]  = "irperf";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 2)]  = "xsaveerptr";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 3)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 4)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 5)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 25)] = "virt_ssbd";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 31)] = "";

    // word 13

    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 0)]  = "npt";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 1)]  = "lbrv";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 2)]  = "svm_lock";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 3)]  = "nrip_save";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 4)]  = "tsc_scale";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 5)]  = "vmcb_clean";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 6)]  = "flushbyasid";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 7)]  = "decodeassists";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 10)] = "pausefilter";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 12)] = "pfthreshold";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 13)] = "avic";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 15)] = "v_vmsave_vmload";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 16)] = "vgif";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 31)] = "";

    // word 14

    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 0)]  = "aperfmperf";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 1)]  = "epb";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 2)]  = "cat_l3";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 3)]  = "cat_l2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 4)]  = "cdp_l3";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 5)]  = "cdp_l2";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 6)]  = "mba";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 7)]  = "hw_pstate";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 8)]  = "cpb";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 9)]  = "proc_feedback";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 10)] = "sme";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 11)] = "sev";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 13)] = "ibrs";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 14)] = "ibpb";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 15)] = "stibp";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 16)] = "ssbd";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 17)] = "ibrs_enhanced";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 31)] = "";

    // word 15

    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 0)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 1)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 2)]  = "cpuid";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 3)]  = "constant_tsc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 4)]  = "nonstop_tsc";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 5)]  = "nonstop_tsc_s3";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 6)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 7)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 8)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 9)]  = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 10)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 11)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 12)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 13)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 14)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 15)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 16)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 17)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 18)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 19)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 20)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 21)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 22)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 23)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 24)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 25)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 26)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 27)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 28)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 29)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 30)] = "";
    x86FeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 31)] = "";



    return NgosStatus::OK;
}
