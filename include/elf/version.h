#ifndef ELF_VERSION_H
#define ELF_VERSION_H



#include <ngos/types.h>



enum class ElfVersion: u32
{
    NONE    = 0,
    CURRENT = 1
};



inline const char8* elfVersionToString(ElfVersion version) // TEST: NO
{
    switch (version)
    {
        case ElfVersion::NONE:    return "NONE";
        case ElfVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



#endif // ELF_VERSION_H
