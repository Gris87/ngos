#ifndef COM_NGOS_SHARED_COMMON_ELF_PROGRAMFLAGS_H
#define COM_NGOS_SHARED_COMMON_ELF_PROGRAMFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
typedef u32 elf_program_flags;

enum class ElfProgramFlag: elf_program_flags
{
    NONE       = 0,
    EXECUTABLE = BIT_0, // Execute permission
    WRITABLE   = BIT_1, // Write permission
    READABLE   = BIT_2  // Read permission
};

DEFINE_FLAGS(ElfProgramFlags, elf_program_flags); // TEST: NO
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* flagToString(ElfProgramFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case ElfProgramFlag::NONE:       return "NONE";
        case ElfProgramFlag::EXECUTABLE: return "EXECUTABLE";
        case ElfProgramFlag::WRITABLE:   return "WRITABLE";
        case ElfProgramFlag::READABLE:   return "READABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(ElfProgramFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%08X (%s)", (elf_program_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const ElfProgramFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[48];

    FLAGS_TO_STRING(res, flags.flags, ElfProgramFlag);

    return res;
}



inline const char8* flagsToFullString(const ElfProgramFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[61];

    FLAGS_TO_FULL_STRING(res, flags.flags, ElfProgramFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_PROGRAMFLAGS_H
