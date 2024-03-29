#ifndef COM_NGOS_SHARED_COMMON_ELF_RELOCATIONTYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_RELOCATIONTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfRelocationType: u32
{
    NONE      = 0,  // No reloc
    D64       = 1,  // Direct 64 bit
    PC32      = 2,  // PC relative 32 bit signed
    GOT32     = 3,  // 32 bit GOT entry
    PLT32     = 4,  // 32 bit PLT address
    COPY      = 5,  // Copy symbol at runtime
    GLOB_DAT  = 6,  // Create GOT entry
    JUMP_SLOT = 7,  // Create PLT entry
    RELATIVE  = 8,  // Adjust by program base
    GOTPCREL  = 9,  // 32 bit signed pc relative offset to GOT
    D32       = 10, // Direct 32 bit zero extended
    D32S      = 11, // Direct 32 bit sign extended
    D16       = 12, // Direct 16 bit zero extended
    PC16      = 13, // 16 bit sign extended pc relative
    D8        = 14, // Direct 8 bit sign extended
    PC8       = 15  // 8 bit sign extended pc relative
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* enumToString(ElfRelocationType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case ElfRelocationType::NONE:      return "NONE";
        case ElfRelocationType::D64:       return "D64";
        case ElfRelocationType::PC32:      return "PC32";
        case ElfRelocationType::GOT32:     return "GOT32";
        case ElfRelocationType::PLT32:     return "PLT32";
        case ElfRelocationType::COPY:      return "COPY";
        case ElfRelocationType::GLOB_DAT:  return "GLOB_DAT";
        case ElfRelocationType::JUMP_SLOT: return "JUMP_SLOT";
        case ElfRelocationType::RELATIVE:  return "RELATIVE";
        case ElfRelocationType::GOTPCREL:  return "GOTPCREL";
        case ElfRelocationType::D32:       return "D32";
        case ElfRelocationType::D32S:      return "D32S";
        case ElfRelocationType::D16:       return "D16";
        case ElfRelocationType::PC16:      return "PC16";
        case ElfRelocationType::D8:        return "D8";
        case ElfRelocationType::PC8:       return "PC8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfRelocationType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%08X (%s)", (u32)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_RELOCATIONTYPE_H
