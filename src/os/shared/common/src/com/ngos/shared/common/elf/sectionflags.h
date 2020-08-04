#ifndef COM_NGOS_SHARED_COMMON_ELF_SECTIONFLAGS_H
#define COM_NGOS_SHARED_COMMON_ELF_SECTIONFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>
#endif



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

DEFINE_FLAGS(ElfSectionFlags, elf_section_flags); // TEST: NO



inline const char8* flagToString(ElfSectionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* flagToFullString(ElfSectionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%016lX (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const ElfSectionFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[137];

    FLAGS_TO_STRING(res, flags.flags, ElfSectionFlag);

    return res;
}



inline const char8* flagsToFullString(const ElfSectionFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[158];

    FLAGS_TO_FULL_STRING(res, flags.flags, ElfSectionFlag, "0x%016lX");

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_ELF_SECTIONFLAGS_H
