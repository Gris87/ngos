#ifndef ELF_TYPE_H
#define ELF_TYPE_H



#include <ngos/types.h>



enum class ElfType: u16
{
    NONE,
    RELOCATABLE,
    EXECUTABLE,
    DYNAMIC_LIBRARY,
    CORE
};



#endif // ELF_TYPE_H
