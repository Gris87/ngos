#ifndef COM_NGOS_SHARED_COMMON_ELF_TYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_TYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfType: u16
{
    NONE            = 0, // No file type
    RELOCATABLE     = 1, // Relocatable object file
    EXECUTABLE      = 2, // Executable file
    DYNAMIC_LIBRARY = 3, // Shared object file
    CORE            = 4  // Core file
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* enumToString(ElfType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case ElfType::NONE:            return "NONE";
        case ElfType::RELOCATABLE:     return "RELOCATABLE";
        case ElfType::EXECUTABLE:      return "EXECUTABLE";
        case ElfType::DYNAMIC_LIBRARY: return "DYNAMIC_LIBRARY";
        case ElfType::CORE:            return "CORE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%04X (%s)", (u16)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_TYPE_H
