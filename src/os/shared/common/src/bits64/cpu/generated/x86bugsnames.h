#ifndef X86BUGSNAMES_H
#define X86BUGSNAMES_H



#include <common/src/bits64/cpu/x86bugword.h>
#include <ngos/status.h>



extern const char8* x86BugsNames[(u64)x86BugWord::MAXIMUM << 5]; // x86BugsNames declared in x86bugsnames.cpp file // "<< 5" == "* 32"



NgosStatus initX86BugsNames(); // TEST: NO



#endif // X86BUGSNAMES_H
