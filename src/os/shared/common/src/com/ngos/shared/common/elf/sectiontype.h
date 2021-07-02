#ifndef COM_NGOS_SHARED_COMMON_ELF_SECTIONTYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_SECTIONTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class ElfSectionType: u32
{
    NONE           = 0,
    PROGBITS       = 0x00000001,
    SYMTAB         = 0x00000002,
    STRTAB         = 0x00000003,
    RELA           = 0x00000004,
    HASH           = 0x00000005,
    DYNAMIC        = 0x00000006,
    NOTE           = 0x00000007,
    NOBITS         = 0x00000008,
    REL            = 0x00000009,
    SHLIB          = 0x0000000A,
    DYNSYM         = 0x0000000B,
    INIT_ARRAY     = 0x0000000E,
    FINI_ARRAY     = 0x0000000F,
    PREINIT_ARRAY  = 0x00000010,
    GROUP          = 0x00000011,
    SYMTAB_SHNDX   = 0x00000012,
    NUM            = 0x00000013
};



inline const char8* enumToString(ElfSectionType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case ElfSectionType::NONE:          return "NONE";
        case ElfSectionType::PROGBITS:      return "PROGBITS";
        case ElfSectionType::SYMTAB:        return "SYMTAB";
        case ElfSectionType::STRTAB:        return "STRTAB";
        case ElfSectionType::RELA:          return "RELA";
        case ElfSectionType::HASH:          return "HASH";
        case ElfSectionType::DYNAMIC:       return "DYNAMIC";
        case ElfSectionType::NOTE:          return "NOTE";
        case ElfSectionType::NOBITS:        return "NOBITS";
        case ElfSectionType::REL:           return "REL";
        case ElfSectionType::SHLIB:         return "SHLIB";
        case ElfSectionType::DYNSYM:        return "DYNSYM";
        case ElfSectionType::INIT_ARRAY:    return "INIT_ARRAY";
        case ElfSectionType::FINI_ARRAY:    return "FINI_ARRAY";
        case ElfSectionType::PREINIT_ARRAY: return "PREINIT_ARRAY";
        case ElfSectionType::GROUP:         return "GROUP";
        case ElfSectionType::SYMTAB_SHNDX:  return "SYMTAB_SHNDX";
        case ElfSectionType::NUM:           return "NUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfSectionType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[27];

    sprintf(res, "0x%08X (%s)", (u32)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_SECTIONTYPE_H
