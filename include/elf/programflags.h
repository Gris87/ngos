#ifndef ELF_PROGRAMFLAGS_H
#define ELF_PROGRAMFLAGS_H



#include <ngos/types.h>



typedef u32 elf_program_flags;

enum class ElfProgramFlag: elf_program_flags
{
    NONE       = 0,
    EXECUTABLE = (1ULL << 0),
    WRITABLE   = (1ULL << 1),
    READABLE   = (1ULL << 2)
};



#endif // ELF_PROGRAMFLAGS_H
