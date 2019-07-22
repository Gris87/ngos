#ifndef ELF_PROGRAMTYPE_H
#define ELF_PROGRAMTYPE_H



#include <ngos/types.h>



#define ELF_PROGRAM_TYPE_OS_LOW         0x60000000
#define ELF_PROGRAM_TYPE_OS_HIGH        0x6FFFFFFF
#define ELF_PROGRAM_TYPE_PROCESSOR_LOW  0x70000000
#define ELF_PROGRAM_TYPE_PROCESSOR_HIGH 0x7FFFFFFF



enum class ElfProgramType: u32
{
    NONE       = 0,
    LOAD       = 0x00000001,
    DYNAMIC    = 0x00000002,
    INTERP     = 0x00000003,
    NOTE       = 0x00000004,
    SHLIB      = 0x00000005,
    PHDR       = 0x00000006
};



inline const char* elfProgramTypeToString(ElfProgramType type) // TEST: NO
{
    switch (type)
    {
        case ElfProgramType::NONE:    return "NONE";
        case ElfProgramType::LOAD:    return "LOAD";
        case ElfProgramType::DYNAMIC: return "DYNAMIC";
        case ElfProgramType::INTERP:  return "INTERP";
        case ElfProgramType::NOTE:    return "NOTE";
        case ElfProgramType::SHLIB:   return "SHLIB";
        case ElfProgramType::PHDR:    return "PHDR";

        default: return "UNKNOWN";
    }
}



#endif // ELF_PROGRAMTYPE_H
