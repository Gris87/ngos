#ifndef COM_NGOS_SHARED_COMMON_ELF_PROGRAMTYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_PROGRAMTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfProgramType: u32
{
    NONE    = 0,          // Unused entry
    LOAD    = 0x00000001, // Loadable segment
    DYNAMIC = 0x00000002, // Dynamic linking tables
    INTERP  = 0x00000003, // Program interpreter path name
    NOTE    = 0x00000004, // Note sections
    SHLIB   = 0x00000005, // Reserved
    PHDR    = 0x00000006  // Program header table
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



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



inline const char8* enumToFullString(ElfProgramType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%08X (%s)", (u32)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_PROGRAMTYPE_H
