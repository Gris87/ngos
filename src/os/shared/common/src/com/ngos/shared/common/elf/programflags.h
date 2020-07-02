#ifndef ELF_PROGRAMFLAGS_H
#define ELF_PROGRAMFLAGS_H



#include <common/src/com/ngos/shared/common/ngos/flags.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#endif



typedef u32 elf_program_flags;

enum class ElfProgramFlag: elf_program_flags
{
    NONE       = 0,
    EXECUTABLE = (1ULL << 0),
    WRITABLE   = (1ULL << 1),
    READABLE   = (1ULL << 2)
};

DEFINE_FLAGS(ElfProgramFlags, elf_program_flags); // TEST: NO



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* flagToFullString(ElfProgramFlag flag) // TEST: NO
{
    static char8 res[24];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const ElfProgramFlags &flags) // TEST: NO
{
    static char8 res[48];

    FLAGS_TO_STRING(res, flags.flags, ElfProgramFlag);

    return res;
}



inline const char8* flagsToFullString(const ElfProgramFlags &flags) // TEST: NO
{
    static char8 res[61];

    FLAGS_TO_FULL_STRING(res, flags.flags, ElfProgramFlag, "0x%08X");

    return res;
}



#endif



#endif // ELF_PROGRAMFLAGS_H
