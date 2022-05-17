#ifndef COM_NGOS_SHARED_COMMON_ELF_HEADERFLAGS_H
#define COM_NGOS_SHARED_COMMON_ELF_HEADERFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
typedef u32 elf_header_flags;

enum class ElfHeaderFlag: elf_header_flags
{
    NONE = 0
};

DEFINE_FLAGS(ElfHeaderFlags, elf_header_flags); // TEST: NO
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* flagToString(ElfHeaderFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case ElfHeaderFlag::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(ElfHeaderFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%08X (%s)", (elf_header_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const ElfHeaderFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[48];

    FLAGS_TO_STRING(res, flags.flags, ElfHeaderFlag);

    return res;
}



inline const char8* flagsToFullString(const ElfHeaderFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[61];

    FLAGS_TO_FULL_STRING(res, flags.flags, ElfHeaderFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_HEADERFLAGS_H
