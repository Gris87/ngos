#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_PROGRAMTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_PROGRAMTYPE_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



#define ELF_PROGRAM_TYPE_OS_LOW         0x60000000
#define ELF_PROGRAM_TYPE_OS_HIGH        0x6FFFFFFF
#define ELF_PROGRAM_TYPE_PROCESSOR_LOW  0x70000000
#define ELF_PROGRAM_TYPE_PROCESSOR_HIGH 0x7FFFFFFF



enum class ElfProgramType: u32
{
    NONE       = 0,
    LOAD       = 0x00000001,
    DYNAMIC    = 0x00000002,
    INTERP     = 0x00000003,
    NOTE       = 0x00000004,
    SHLIB      = 0x00000005,
    PHDR       = 0x00000006
};



inline const char8* enumToString(ElfProgramType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case ElfProgramType::NONE:    return "NONE";
        case ElfProgramType::LOAD:    return "LOAD";
        case ElfProgramType::DYNAMIC: return "DYNAMIC";
        case ElfProgramType::INTERP:  return "INTERP";
        case ElfProgramType::NOTE:    return "NOTE";
        case ElfProgramType::SHLIB:   return "SHLIB";
        case ElfProgramType::PHDR:    return "PHDR";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfProgramType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_PROGRAMTYPE_H
