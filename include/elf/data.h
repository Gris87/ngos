#ifndef ELF_DATA_H
#define ELF_DATA_H



#include <ngos/types.h>



enum class ElfData: u8
{
    NONE                   = 0,
    LEAST_SIGNIFICANT_BYTE = 1 ,
    MOST_SIGNIFICANT_BYTE  = 2
};



inline const char* elfDataToString(ElfData data) // TEST: NO
{
    switch (data)
    {
        case ElfData::NONE:                   return "NONE";
        case ElfData::LEAST_SIGNIFICANT_BYTE: return "LEAST_SIGNIFICANT_BYTE";
        case ElfData::MOST_SIGNIFICANT_BYTE:  return "MOST_SIGNIFICANT_BYTE";

        default: return "UNKNOWN";
    }
}



#endif // ELF_DATA_H
