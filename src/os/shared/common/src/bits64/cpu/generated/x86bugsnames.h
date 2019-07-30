#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_X86BUGSNAMES_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_X86BUGSNAMES_H



#include <common/src/bits64/cpu/x86bugword.h>
#include <ngos/status.h>



extern const char8* x86BugsNames[(u64)x86BugWord::MAXIMUM << 5]; // x86BugsNames declared in x86bugsnames.cpp file // "<< 5" == "* 32"



NgosStatus initX86BugsNames(); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_GENERATED_X86BUGSNAMES_H
