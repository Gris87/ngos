#ifndef ELF_CLASS_H
#define ELF_CLASS_H



#include <ngos/types.h>



enum class ElfClass: u8
{
    NONE,
    CLASS_32,
    CLASS_64
};



#endif // ELF_CLASS_H
