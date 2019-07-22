#ifndef ELF_RELATYPE_H
#define ELF_RELATYPE_H



#include <ngos/types.h>



enum class ElfRelaType: u8
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



inline const char* elfRelaTypeToString(ElfRelaType type) // TEST: NO
{
    switch (type)
    {
        case ElfRelaType::NONE:      return "NONE";
        case ElfRelaType::D64:       return "D64";
        case ElfRelaType::PC32:      return "PC32";
        case ElfRelaType::GOT32:     return "GOT32";
        case ElfRelaType::PLT32:     return "PLT32";
        case ElfRelaType::COPY:      return "COPY";
        case ElfRelaType::GLOB_DAT:  return "GLOB_DAT";
        case ElfRelaType::JUMP_SLOT: return "JUMP_SLOT";
        case ElfRelaType::RELATIVE:  return "RELATIVE";
        case ElfRelaType::GOTPCREL:  return "GOTPCREL";
        case ElfRelaType::D32:       return "D32";
        case ElfRelaType::D32S:      return "D32S";
        case ElfRelaType::D16:       return "D16";
        case ElfRelaType::PC16:      return "PC16";
        case ElfRelaType::D8:        return "D8";
        case ElfRelaType::PC8:       return "PC8";

        default: return "UNKNOWN";
    }
}



#endif // ELF_RELATYPE_H
