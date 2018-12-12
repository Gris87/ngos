#ifndef ELF_ELFDATA_H
#define ELF_ELFDATA_H



#include <Qt>



enum class ElfData: quint8
{
    NONE,
    LEAST_SIGNIFICANT_BYTE,
    MOST_SIGNIFICANT_BYTE
};



#endif // ELF_ELFDATA_H
