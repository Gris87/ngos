#ifndef ELF_ELFSECTIONTYPE_H
#define ELF_ELFSECTIONTYPE_H



#include <Qt>



enum class ElfSectionType: quint32
{
    NONE           = 0x00000000,
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
    NUM            = 0x00000013,
    LOOS           = 0x60000000
};



#endif // ELF_ELFSECTIONTYPE_H
