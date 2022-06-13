#ifndef COM_NGOS_SHARED_COMMON_ELF_SECTIONFLAGS_H
#define COM_NGOS_SHARED_COMMON_ELF_SECTIONFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
typedef u64 elf_section_flags;

enum class ElfSectionFlag: elf_section_flags
{
    NONE             = 0,
    WRITE            = BIT_0,  // Section contains writable data
    ALLOC            = BIT_1,  // Section is allocated in memory image of program
    EXECINSTR        = BIT_2,  // Section contains executable instructions
    MERGE            = BIT_4,
    STRINGS          = BIT_5,
    INFO_LINK        = BIT_6,
    LINK_ORDER       = BIT_7,
    OS_NONCONFORMING = BIT_8,
    GROUP            = BIT_9,
    TLS              = BIT_10,
    ORDERED          = BIT_26,
    EXCLUDE          = BIT_27
};

DEFINE_FLAGS(ElfSectionFlags, elf_section_flags); // TEST: NO
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



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



inline const char8* flagToFullString(ElfSectionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%016llX (%s)", (elf_section_flags)flag, flagToString(flag));

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

    FLAGS_TO_FULL_STRING(res, flags.flags, ElfSectionFlag, "0x%016llX");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_SECTIONFLAGS_H
