#ifndef COM_NGOS_SHARED_COMMON_ELF_DYNAMICTAG_H
#define COM_NGOS_SHARED_COMMON_ELF_DYNAMICTAG_H



#include <com/ngos/shared/common/ngos/tags.h>
#include <com/ngos/shared/common/printf/printf.h>



// Verified with ElfSpecVerifier [BEGIN] // https://www.uclibc.org/docs/elf-64-gen.pdf
enum class ElfDynamicTag: u64
{
    NONE         = 0,  // Marks the end of the dynamic array
    NEEDED       = 1,  // The string table offset of the name of a needed library.
    PLTRELSZ     = 2,  // Total size, in bytes, of the relocation entries associated with the procedure linkage table.
    PLTGOT       = 3,  // Contains an address associated with the linkage table. The specific meaning of this field is processor-dependent.
    HASH         = 4,  // Address of the symbol hash table, described below.
    STRTAB       = 5,  // Address of the dynamic string table.
    SYMTAB       = 6,  // Address of the dynamic symbol table.
    RELA         = 7,  // Address of a relocation table with Elf64_Rela entries.
    RELASZ       = 8,  // Total size, in bytes, of the DT_RELA relocation table.
    RELAENT      = 9,  // Size, in bytes, of each DT_RELA relocation entry.
    STRSZ        = 10, // Total size, in bytes, of the string table.
    SYMENT       = 11, // Size, in bytes, of each symbol table entry.
    INIT         = 12, // Address of the initialization function.
    FINI         = 13, // Address of the termination function.
    SONAME       = 14, // The string table offset of the name of this shared object.
    RPATH        = 15, // The string table offset of a shared library search path string.
    SYMBOLIC     = 16, // The presence of this dynamic table entry modifies the symbol resolution algorithm for references within the library. Symbols defined within the library are used to resolve references before the dynamic linker searches the usual search path.
    REL          = 17, // Address of a relocation table with Elf64_Rel entries.
    RELSZ        = 18, // Total size, in bytes, of the DT_REL relocation table.
    RELENT       = 19, // Size, in bytes, of each DT_REL relocation entry.
    PLTREL       = 20, // Type of relocation entry used for the procedure linkage table. The d_val member contains either DT_REL or DT_RELA.
    DEBUG        = 21, // Reserved for debugger use.
    TEXTREL      = 22, // The presence of this dynamic table entry signals that the relocation table contains relocations for a non-writable segment.
    JMPREL       = 23, // Address of the relocations associated with the procedure linkage table.
    BIND_NOW     = 24, // The presence of this dynamic table entry signals that the dynamic loader should process all relocations for this object before transferring control to the program.
    INIT_ARRAY   = 25, // Pointer to an array of pointers to initialization functions.
    FINI_ARRAY   = 26, // Pointer to an array of pointers to termination functions.
    INIT_ARRAYSZ = 27, // Size, in bytes, of the array of initialization functions.
    FINI_ARRAYSZ = 28  // Size, in bytes, of the array of termination functions.
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
