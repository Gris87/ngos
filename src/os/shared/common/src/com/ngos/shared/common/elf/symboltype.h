#ifndef COM_NGOS_SHARED_COMMON_ELF_SYMBOLTYPE_H
#define COM_NGOS_SHARED_COMMON_ELF_SYMBOLTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class ElfSymbolType: u8
{
    NOTYPE  = 0,
    OBJECT  = 1,
    FUNC    = 2,
    SECTION = 3,
    FILE    = 4,
    COMMON  = 5,
    TLS     = 6
};



inline const char8* enumToString(ElfSymbolType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case ElfSymbolType::NOTYPE:  return "NOTYPE";
        case ElfSymbolType::OBJECT:  return "OBJECT";
        case ElfSymbolType::FUNC:    return "FUNC";
        case ElfSymbolType::SECTION: return "SECTION";
        case ElfSymbolType::FILE:    return "FILE";
        case ElfSymbolType::COMMON:  return "COMMON";
        case ElfSymbolType::TLS:     return "TLS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfSymbolType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_ELF_SYMBOLTYPE_H
