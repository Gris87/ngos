#ifndef ELF_CLASS_H
#define ELF_CLASS_H



#include <ngos/types.h>



enum class ElfClass: u8
{
    NONE     = 0,
    CLASS_32 = 1,
    CLASS_64 = 2
};



inline const char* elfClassToString(ElfClass elfClass) // TEST: NO
{
    switch (elfClass)
    {
        case ElfClass::NONE:     return "NONE";
        case ElfClass::CLASS_32: return "CLASS_32";
        case ElfClass::CLASS_64: return "CLASS_64";

        default: return "UNKNOWN";
    }
}



#endif // ELF_CLASS_H
