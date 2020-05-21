// This file generated with the code_generator
// Please do not modify it manually
#include "x86bugsnames.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/utils.h>



const char8* x86BugsNames[(u64)x86BugWord::MAXIMUM * 32];



NgosStatus initX86BugsNames()
{
    COMMON_LT((""));



    // word 0

    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 0)]  = "test";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 1)]  = "cpu_meltdown";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 2)]  = "spectre_v1";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 3)]  = "spectre_v2";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 4)]  = "spec_store_bypass";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 5)]  = "l1tf";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 6)]  = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 7)]  = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 8)]  = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 9)]  = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 10)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 11)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 12)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 13)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 14)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 15)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 16)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 17)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 18)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 19)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 20)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 21)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 22)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 23)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 24)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 25)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 26)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 27)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 28)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 29)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 30)] = "";
    x86BugsNames[WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 31)] = "";



    return NgosStatus::OK;
}
