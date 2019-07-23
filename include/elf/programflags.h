#ifndef ELF_PROGRAMFLAGS_H
#define ELF_PROGRAMFLAGS_H



#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 elf_program_flags;

enum class ElfProgramFlag: elf_program_flags // Ignore CppEnumVerifier
{
    NONE       = 0,
    EXECUTABLE = (1ULL << 0),
    WRITABLE   = (1ULL << 1),
    READABLE   = (1ULL << 2)
};



inline const char* elfProgramFlagToString(ElfProgramFlag flag) // TEST: NO
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



#endif // ELF_PROGRAMFLAGS_H
