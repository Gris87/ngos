#ifndef ELF_ELFCLASS_H
#define ELF_ELFCLASS_H



#include <Qt>



enum class ElfClass: quint8
{
    NONE,
    CLASS_32,
    CLASS_64
};



#endif // ELF_ELFCLASS_H
