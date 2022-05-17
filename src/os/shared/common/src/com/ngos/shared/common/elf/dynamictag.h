#ifndef COM_NGOS_SHARED_COMMON_ELF_DYNAMICTAG_H
#define COM_NGOS_SHARED_COMMON_ELF_DYNAMICTAG_H



#include <com/ngos/shared/common/ngos/tags.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfDynamicTag: u64
{
    NONE         = 0,
    NEEDED       = 1,
    PLTRELSZ     = 2,
    PLTGOT       = 3,
    HASH         = 4,
    STRTAB       = 5,
    SYMTAB       = 6,
    RELA         = 7,
    RELASZ       = 8,
    RELAENT      = 9,
    STRSZ        = 10,
    SYMENT       = 11,
    INIT         = 12,
    FINI         = 13,
    SONAME       = 14,
    RPATH        = 15,
    SYMBOLIC     = 16,
    REL          = 17,
    RELSZ        = 18,
    RELENT       = 19,
    PLTREL       = 20,
    DEBUG        = 21,
    TEXTREL      = 22,
    JMPREL       = 23,
    BIND_NOW     = 24,
    INIT_ARRAY   = 25,
    FINI_ARRAY   = 26,
    INIT_ARRAYSZ = 27,
    FINI_ARRAYSZ = 28
};
// Verified with ElfSpecVerifier [END] // https://www.uclibc.org/docs/elf-64-gen.pdf



inline const char8* enumToString(ElfDynamicTag tag) // TEST: NO
{
    // COMMON_LT((" | tag = %u", tag)); // Commented to avoid bad looking logs



    switch (tag)
    {
        case ElfDynamicTag::NONE:  return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfDynamicTag tag) // TEST: NO
{
    // COMMON_LT((" | tag = %u", tag)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)tag, enumToString(tag));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_DYNAMICTAG_H
