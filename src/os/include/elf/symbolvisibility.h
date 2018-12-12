#ifndef ELF_SYMBOLVISIBILITY_H
#define ELF_SYMBOLVISIBILITY_H



#include <ngos/types.h>



enum class ElfSymbolVisibility: u8
{
    DEFAULT,
    INTERNAL,
    HIDDEN,
    PROTECTED,
    EXPORTED,
    SINGLETON,
    ELIMINATE
};



#endif // ELF_SYMBOLVISIBILITY_H
