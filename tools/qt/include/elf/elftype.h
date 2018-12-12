#ifndef ELF_ELFTYPE_H
#define ELF_ELFTYPE_H



#include <Qt>



enum class ElfType: quint16
{
    NONE,
    RELOCATABLE,
    EXECUTABLE,
    DYNAMIC_LIBRARY,
    CORE
};



#endif // ELF_ELFTYPE_H
