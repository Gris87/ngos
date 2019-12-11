#ifndef ELF_FILEVERSION_H
#define ELF_FILEVERSION_H



#include <ngos/types.h>



enum class ElfFileVersion: u8
{
    NONE    = 0,
    CURRENT = 1
};



inline const char8* enumToString(ElfFileVersion version) // TEST: NO
{
    switch (version)
    {
        case ElfFileVersion::NONE:    return "NONE";
        case ElfFileVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ElfFileVersion version) // TEST: NO
{
    switch (version)
    {
        case ElfFileVersion::NONE:    return "NONE";
        case ElfFileVersion::CURRENT: return "CURRENT";

        default: return "UNKNOWN";
    }
}



#endif // ELF_FILEVERSION_H
