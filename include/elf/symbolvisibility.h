#ifndef ELF_SYMBOLVISIBILITY_H
#define ELF_SYMBOLVISIBILITY_H



#include <ngos/types.h>



enum class ElfSymbolVisibility: u8
{
    DEFAULT   = 0,
    INTERNAL  = 1,
    HIDDEN    = 2,
    PROTECTED = 3,
    EXPORTED  = 4,
    SINGLETON = 5,
    ELIMINATE = 6
};



inline const char* elfSymbolVisibilityToString(ElfSymbolVisibility visibility) // TEST: NO
{
    switch (visibility)
    {
        case ElfSymbolVisibility::DEFAULT:   return "DEFAULT";
        case ElfSymbolVisibility::INTERNAL:  return "INTERNAL";
        case ElfSymbolVisibility::HIDDEN:    return "HIDDEN";
        case ElfSymbolVisibility::PROTECTED: return "PROTECTED";
        case ElfSymbolVisibility::EXPORTED:  return "EXPORTED";
        case ElfSymbolVisibility::SINGLETON: return "SINGLETON";
        case ElfSymbolVisibility::ELIMINATE: return "ELIMINATE";

        default: return "UNKNOWN";
    }
}



#endif // ELF_SYMBOLVISIBILITY_H
