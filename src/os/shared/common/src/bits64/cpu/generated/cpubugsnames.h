// This file generated with the code_generator
// Please do not modify it manually
#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_CPUBUGSNAMES_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_CPUBUGSNAMES_H



#include <common/src/bits64/cpu/cpubugs.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/status.h>



extern const char* cpuBugsNames[AMOUNT_OF_WORDS_FOR_X86_BUGS << 5]; // cpuBugsNames declared in cpu.cpp file // "<< 5" == "* 32"



inline NgosStatus initCpuBugsNames() // TEST: NO
{
    COMMON_LT((""));



    // word 0

    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 0)]  = "test";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 1)]  = "cpu_meltdown";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 2)]  = "spectre_v1";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 3)]  = "spectre_v2";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 4)]  = "spec_store_bypass";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 5)]  = "l1tf";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 6)]  = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 7)]  = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 8)]  = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 9)]  = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 10)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 11)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 12)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 13)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 14)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 15)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 16)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 17)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 18)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 19)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 20)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 21)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 22)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 23)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 24)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 25)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 26)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 27)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 28)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 29)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 30)] = "";
    cpuBugsNames[WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 31)] = "";



    return NgosStatus::OK;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_CPUBUGSNAMES_H
