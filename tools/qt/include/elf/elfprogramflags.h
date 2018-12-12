#ifndef ELF_ELFPROGRAMFLAGS_H
#define ELF_ELFPROGRAMFLAGS_H



#include <Qt>



typedef quint32 elf_program_flags;

enum class ElfProgramFlag: elf_program_flags
{
    NONE       = 0,
    EXECUTABLE = (1ULL << 0),
    WRITABLE   = (1ULL << 1),
    READABLE   = (1ULL << 2)
};



#endif // ELF_ELFPROGRAMFLAGS_H
