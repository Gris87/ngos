// This file generated with the code_generator
// Please do not modify it manually
#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_CPUFEATURESNAMES_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_CPUFEATURESNAMES_H



#include <common/src/bits64/cpu/x86feature.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/status.h>



extern const char8* cpuFeaturesNames[(u64)x86FeatureWord::MAXIMUM << 5]; // cpuFeaturesNames declared in cpu.cpp file // "<< 5" == "* 32"



inline NgosStatus initCpuFeaturesNames() // TEST: NO
{
    COMMON_LT((""));



    // word 0

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 0)]  = "pni";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 1)]  = "pclmulqdq";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 2)]  = "dtes64";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 3)]  = "monitor";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 4)]  = "ds_cpl";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 5)]  = "vmx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 6)]  = "smx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 7)]  = "est";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 8)]  = "tm2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 9)]  = "ssse3";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 10)] = "cid";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 11)] = "sdbg";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 12)] = "fma";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 13)] = "cx16";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 14)] = "xtpr";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 15)] = "pdcm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 17)] = "pcid";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 18)] = "dca";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 19)] = "sse4_1";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 20)] = "sse4_2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 21)] = "x2apic";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 22)] = "movbe";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 23)] = "popcnt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 24)] = "tsc_deadline_timer";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 25)] = "aes";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 26)] = "xsave";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 28)] = "avx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 29)] = "f16c";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 30)] = "rdrand";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_ECX, 31)] = "hypervisor";

    // word 1

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 0)]  = "fpu";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 1)]  = "vme";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 2)]  = "de";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 3)]  = "pse";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 4)]  = "tsc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 5)]  = "msr";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 6)]  = "pae";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 7)]  = "mce";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 8)]  = "cx8";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 9)]  = "apic";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 11)] = "sep";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 12)] = "mtrr";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 13)] = "pge";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 14)] = "mca";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 15)] = "cmov";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 16)] = "pat";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 17)] = "pse36";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 18)] = "pn";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 19)] = "clflush";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 21)] = "dts";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 22)] = "acpi";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 23)] = "mmx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 24)] = "fxsr";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 25)] = "sse";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 26)] = "sse2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 27)] = "ss";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 28)] = "ht";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 29)] = "tm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 30)] = "ia64";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000001_EDX, 31)] = "pbe";

    // word 2

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 0)]  = "dtherm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 1)]  = "ida";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 2)]  = "arat";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 3)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 4)]  = "pln";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 6)]  = "pts";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 7)]  = "hwp";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 8)]  = "hwp_notify";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 9)]  = "hwp_act_window";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 10)] = "hwp_epp";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 11)] = "hwp_pkg_req";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000006_EAX, 31)] = "";

    // word 3

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 0)]  = "fsgsbase";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 1)]  = "tsc_adjust";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 2)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 3)]  = "bmi1";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 4)]  = "hle";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 5)]  = "avx2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 7)]  = "smep";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 8)]  = "bmi2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 9)]  = "erms";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 10)] = "invpcid";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 11)] = "rtm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 12)] = "cqm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 14)] = "mpx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 15)] = "rdt_a";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 16)] = "avx512f";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 17)] = "avx512dq";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 18)] = "rdseed";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 19)] = "adx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 20)] = "smap";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 21)] = "avx512ifma";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 23)] = "clflushopt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 24)] = "clwb";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 25)] = "intel_pt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 26)] = "avx512pf";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 27)] = "avx512er";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 28)] = "avx512cd";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 29)] = "sha_ni";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 30)] = "avx512bw";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EBX, 31)] = "avx512vl";

    // word 4

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 0)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 1)]  = "avx512vbmi";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 2)]  = "umip";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 3)]  = "pku";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 4)]  = "ospke";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 6)]  = "avx512_vbmi2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 8)]  = "gfni";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 9)]  = "vaes";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 10)] = "vpclmulqdq";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 11)] = "avx512_vnni";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 12)] = "avx512_bitalg";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 13)] = "tme";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 14)] = "avx512_vpopcntdq";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 16)] = "la57";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 22)] = "rdpid";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 25)] = "cldemote";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 27)] = "movdiri";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 28)] = "movdir64b";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_ECX, 31)] = "";

    // word 5

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 0)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 1)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 2)]  = "avx512_4vnniw";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 3)]  = "avx512_4fmaps";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 18)] = "pconfig";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 28)] = "flush_l1d";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 29)] = "arch_capabilities";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_00000007_EDX, 31)] = "";

    // word 6

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 0)]  = "xsaveopt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 1)]  = "xsavec";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 2)]  = "xgetbv1";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 3)]  = "xsaves";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000D_1_EAX, 31)] = "";

    // word 7

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 0)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 1)]  = "cqm_llc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 2)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 3)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_0_EDX, 31)] = "";

    // word 8

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 0)]  = "cqm_occup_llc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 1)]  = "cqm_mbm_total";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 2)]  = "cqm_mbm_local";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 3)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_0000000F_1_EDX, 31)] = "";

    // word 9

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 0)]  = "lahf_lm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 1)]  = "cmp_legacy";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 2)]  = "svm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 3)]  = "extapic";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 4)]  = "cr8_legacy";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 5)]  = "abm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 6)]  = "sse4a";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 7)]  = "misalignsse";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 8)]  = "3dnowprefetch";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 9)]  = "osvw";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 10)] = "ibs";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 11)] = "xop";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 12)] = "skinit";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 13)] = "wdt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 15)] = "lwp";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 16)] = "fma4";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 17)] = "tce";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 19)] = "nodeid_msr";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 21)] = "tbm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 22)] = "topoext";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 23)] = "perfctr_core";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 24)] = "perfctr_nb";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 26)] = "bpext";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 27)] = "ptsc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 28)] = "perfctr_llc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 29)] = "mwaitx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_ECX, 31)] = "";

    // word 10

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 0)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 1)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 2)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 3)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 11)] = "syscall";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 19)] = "mp";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 20)] = "nx";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 22)] = "mmxext";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 25)] = "fxsr_opt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 26)] = "pdpe1gb";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 27)] = "rdtscp";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 29)] = "lm";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 30)] = "3dnowext";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000001_EDX, 31)] = "3dnow";

    // word 11

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 0)]  = "overflow_recov";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 1)]  = "succor";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 2)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 3)]  = "smca";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000007_EBX, 31)] = "";

    // word 12

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 0)]  = "clzero";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 1)]  = "irperf";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 2)]  = "xsaveerptr";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 3)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 4)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 5)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 25)] = "virt_ssbd";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_80000008_EBX, 31)] = "";

    // word 13

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 0)]  = "npt";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 1)]  = "lbrv";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 2)]  = "svm_lock";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 3)]  = "nrip_save";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 4)]  = "tsc_scale";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 5)]  = "vmcb_clean";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 6)]  = "flushbyasid";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 7)]  = "decodeassists";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 10)] = "pausefilter";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 12)] = "pfthreshold";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 13)] = "avic";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 15)] = "v_vmsave_vmload";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 16)] = "vgif";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::CPUID_8000000A_EDX, 31)] = "";

    // word 14

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 0)]  = "aperfmperf";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 1)]  = "epb";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 2)]  = "cat_l3";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 3)]  = "cat_l2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 4)]  = "cdp_l3";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 5)]  = "cdp_l2";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 6)]  = "mba";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 7)]  = "hw_pstate";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 8)]  = "cpb";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 9)]  = "proc_feedback";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 10)] = "sme";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 11)] = "sev";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 13)] = "ibrs";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 14)] = "ibpb";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 15)] = "stibp";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 16)] = "ssbd";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 17)] = "ibrs_enhanced";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_AUXILIARY_FLAGS, 31)] = "";

    // word 15

    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 0)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 1)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 2)]  = "cpuid";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 3)]  = "constant_tsc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 4)]  = "nonstop_tsc";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 5)]  = "nonstop_tsc_s3";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 6)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 7)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 8)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 9)]  = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 10)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 11)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 12)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 13)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 14)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 15)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 16)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 17)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 18)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 19)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 20)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 21)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 22)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 23)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 24)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 25)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 26)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 27)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 28)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 29)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 30)] = "";
    cpuFeaturesNames[WORD_BIT(x86FeatureWord::NGOS_OTHER_FLAGS, 31)] = "";



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_CPUFEATURESNAMES_H
