#ifndef ELF_SYMBOLTYPE_H
#define ELF_SYMBOLTYPE_H



#include <ngos/types.h>



#define ELF_SYMBOL_TYPE_OS_LOW         10
#define ELF_SYMBOL_TYPE_OS_HIGH        12
#define ELF_SYMBOL_TYPE_PROCESSOR_LOW  13
#define ELF_SYMBOL_TYPE_PROCESSOR_HIGH 15



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



#endif // ELF_SYMBOLTYPE_H
