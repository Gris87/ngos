#ifndef ELF_DATA_H
#define ELF_DATA_H



#include <ngos/types.h>



enum class ElfData: u8
{
    NONE,
    LEAST_SIGNIFICANT_BYTE,
    MOST_SIGNIFICANT_BYTE
};



#endif // ELF_DATA_H
