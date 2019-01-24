// This file generated with the code_generator
// Please do not modify it manually
#ifndef OS_COMMON_SRC_BITS64_CPU_GENERATED_CPUBUGSNAMES_H
#define OS_COMMON_SRC_BITS64_CPU_GENERATED_CPUBUGSNAMES_H



#include <ngos/status.h>
#include <src/bits64/cpu/cpubugs.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>



extern const char* cpuBugsNames[AMOUNT_OF_WORDS_FOR_X86_BUGS << 5]; // cpuBugsNames declared in cpu.cpp file // "<< 5" == "* 32"



inline NgosStatus initCpuBugsNames() // TEST: NO
{
    COMMON_LT((""));




    // word 0

    cpuBugsNames[WORD_BIT(0, 0)]  = "cpu_meltdown";
    cpuBugsNames[WORD_BIT(0, 1)]  = "spectre_v1";
    cpuBugsNames[WORD_BIT(0, 2)]  = "spectre_v2";
    cpuBugsNames[WORD_BIT(0, 3)]  = "spec_store_bypass";
    cpuBugsNames[WORD_BIT(0, 4)]  = "l1tf";
    cpuBugsNames[WORD_BIT(0, 5)]  = "";
    cpuBugsNames[WORD_BIT(0, 6)]  = "";
    cpuBugsNames[WORD_BIT(0, 7)]  = "";
    cpuBugsNames[WORD_BIT(0, 8)]  = "";
    cpuBugsNames[WORD_BIT(0, 9)]  = "";
    cpuBugsNames[WORD_BIT(0, 10)] = "";
    cpuBugsNames[WORD_BIT(0, 11)] = "";
    cpuBugsNames[WORD_BIT(0, 12)] = "";
    cpuBugsNames[WORD_BIT(0, 13)] = "";
    cpuBugsNames[WORD_BIT(0, 14)] = "";
    cpuBugsNames[WORD_BIT(0, 15)] = "";
    cpuBugsNames[WORD_BIT(0, 16)] = "";
    cpuBugsNames[WORD_BIT(0, 17)] = "";
    cpuBugsNames[WORD_BIT(0, 18)] = "";
    cpuBugsNames[WORD_BIT(0, 19)] = "";
    cpuBugsNames[WORD_BIT(0, 20)] = "";
    cpuBugsNames[WORD_BIT(0, 21)] = "";
    cpuBugsNames[WORD_BIT(0, 22)] = "";
    cpuBugsNames[WORD_BIT(0, 23)] = "";
    cpuBugsNames[WORD_BIT(0, 24)] = "";
    cpuBugsNames[WORD_BIT(0, 25)] = "";
    cpuBugsNames[WORD_BIT(0, 26)] = "";
    cpuBugsNames[WORD_BIT(0, 27)] = "";
    cpuBugsNames[WORD_BIT(0, 28)] = "";
    cpuBugsNames[WORD_BIT(0, 29)] = "";
    cpuBugsNames[WORD_BIT(0, 30)] = "";
    cpuBugsNames[WORD_BIT(0, 31)] = "";



    return NgosStatus::OK;
}



#endif // OS_COMMON_SRC_BITS64_CPU_GENERATED_CPUBUGSNAMES_H
