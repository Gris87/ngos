#ifndef ELF_ELFSYMBOLVISIBILITY_H
#define ELF_ELFSYMBOLVISIBILITY_H



#include <Qt>



enum class ElfSymbolVisibility: quint8
{
    DEFAULT,
    INTERNAL,
    HIDDEN,
    PROTECTED,
    EXPORTED,
    SINGLETON,
    ELIMINATE
};



#endif // ELF_ELFSYMBOLVISIBILITY_H
