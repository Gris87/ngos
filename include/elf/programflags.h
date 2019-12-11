#ifndef ELF_PROGRAMFLAGS_H
#define ELF_PROGRAMFLAGS_H



#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 elf_program_flags;

enum class ElfProgramFlag: elf_program_flags
{
    NONE       = 0,
    EXECUTABLE = (1ULL << 0),
    WRITABLE   = (1ULL << 1),
    READABLE   = (1ULL << 2)
};

DEFINE_FLAGS(ElfProgramFlags, elf_program_flags);



inline const char8* flagToString(ElfProgramFlag flag) // TEST: NO
{
    switch (flag)
    {
        case ElfProgramFlag::NONE:       return "NONE";
        case ElfProgramFlag::EXECUTABLE: return "EXECUTABLE";
        case ElfProgramFlag::WRITABLE:   return "WRITABLE";
        case ElfProgramFlag::READABLE:   return "READABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagsToString(const ElfProgramFlags &flags) // TEST: NO
{
    AVOID_UNUSED(flags);

    return "NOT_SUPPORTED";
}



inline const char8* flagsToFullString(const ElfProgramFlags &flags) // TEST: NO
{
    AVOID_UNUSED(flags);

    return "NOT_SUPPORTED";
}



#endif // ELF_PROGRAMFLAGS_H
