#ifndef ELF_SECTIONFLAGS_H
#define ELF_SECTIONFLAGS_H



#include <ngos/types.h>



#define ELF_SECTION_FLAGS_OS_MASK        0x0FF00000
#define ELF_SECTION_FLAGS_PROCESSOR_MASK 0xF0000000



typedef u64 elf_section_flags;

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
    EXCLUDE            = (1ULL << 27)
};



inline const char* elfSectionFlagToString(ElfSectionFlag flag) // TEST: NO
{
    switch (flag)
    {
        case ElfSectionFlag::NONE:             return "NONE";
        case ElfSectionFlag::WRITE:            return "WRITE";
        case ElfSectionFlag::ALLOC:            return "ALLOC";
        case ElfSectionFlag::EXECINSTR:        return "EXECINSTR";
        case ElfSectionFlag::MERGE:            return "MERGE";
        case ElfSectionFlag::STRINGS:          return "STRINGS";
        case ElfSectionFlag::INFO_LINK:        return "INFO_LINK";
        case ElfSectionFlag::LINK_ORDER:       return "LINK_ORDER";
        case ElfSectionFlag::OS_NONCONFORMING: return "OS_NONCONFORMING";
        case ElfSectionFlag::GROUP:            return "GROUP";
        case ElfSectionFlag::TLS:              return "TLS";
        case ElfSectionFlag::ORDERED:          return "ORDERED";
        case ElfSectionFlag::EXCLUDE:          return "EXCLUDE";

        default: return "UNKNOWN";
    }
}



#endif // ELF_SECTIONFLAGS_H
