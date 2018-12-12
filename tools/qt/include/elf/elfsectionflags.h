#ifndef ELF_ELFSECTIONFLAGS_H
#define ELF_ELFSECTIONFLAGS_H



#include <Qt>



typedef quint64 elf_section_flags;

enum class ElfSectionFlag: elf_section_flags
{
    NONE               = 0,
    WRITE              = (1ULL << 0),
    ALLOC              = (1ULL << 1),
    EXECINSTR          = (1ULL << 2),
    MERGE              = (1ULL << 4),
    STRINGS            = (1ULL << 5),
    INFO_LINK          = (1ULL << 6),
    LINK_ORDER         = (1ULL << 7),
    OS_NONCONFORMING   = (1ULL << 8),
    GROUP              = (1ULL << 9),
    TLS                = (1ULL << 10),
    ORDERED            = (1ULL << 26),
    EXCLUDE            = (1ULL << 27),

    MASKOS             = 0x0FF00000,
    MASKPROC           = 0xF0000000
};



#endif // ELF_ELFSECTIONFLAGS_H
