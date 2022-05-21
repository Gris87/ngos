#ifndef COM_NGOS_SHARED_COMMON_ELF_SECTIONTYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_SECTIONTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfSectionType: u32
{
    NONE           = 0,          // Marks an unused section header
    PROGBITS       = 0x00000001, // Contains information defined by the program
    SYMTAB         = 0x00000002, // Contains a linker symbol table
    STRTAB         = 0x00000003, // Contains a string table
    RELA           = 0x00000004, // Contains "Rela" type relocation entries
    HASH           = 0x00000005, // Contains a symbol hash table
    DYNAMIC        = 0x00000006, // Contains dynamic linking tables
    NOTE           = 0x00000007, // Contains note information
    NOBITS         = 0x00000008, // Contains uninitialized space; does not occupy any space in the file
    REL            = 0x00000009, // Contains "Rel" type relocation entries
    SHLIB          = 0x0000000A, // Reserved
    DYNSYM         = 0x0000000B, // Contains a dynamic loader symbol table
    INIT_ARRAY     = 0x0000000E,
    FINI_ARRAY     = 0x0000000F,
    PREINIT_ARRAY  = 0x00000010,
    GROUP          = 0x00000011,
    SYMTAB_SHNDX   = 0x00000012,
    NUM            = 0x00000013
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



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
