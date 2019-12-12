#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiBaseboardType: u8
{
    NONE                     = 0,
    UNKNOWN                  = 1,
    OTHER                    = 2,
    SERVER_BLADE             = 3,
    CONNECTIVITY_SWITCH      = 4,
    SYSTEM_MANAGEMENT_MODULE = 5,
    PROCESSOR_MODULE         = 6,
    IO_MODULE                = 7,
    MEMORY_MODULE            = 8,
    DAUGHTER_BOARD           = 9,
    MOTHERBOARD              = 10,
    PROCESSOR_MEMORY_MODULE  = 11,
    PROCESSOR_IO_MODULE      = 12,
    INTERCONNECT_BOARD       = 13
};



inline const char8* enumToString(DmiBaseboardType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiBaseboardType::NONE:                     return "NONE";
        case DmiBaseboardType::UNKNOWN:                  return "UNKNOWN";
        case DmiBaseboardType::OTHER:                    return "OTHER";
        case DmiBaseboardType::SERVER_BLADE:             return "SERVER_BLADE";
        case DmiBaseboardType::CONNECTIVITY_SWITCH:      return "CONNECTIVITY_SWITCH";
        case DmiBaseboardType::SYSTEM_MANAGEMENT_MODULE: return "SYSTEM_MANAGEMENT_MODULE";
        case DmiBaseboardType::PROCESSOR_MODULE:         return "PROCESSOR_MODULE";
        case DmiBaseboardType::IO_MODULE:                return "IO_MODULE";
        case DmiBaseboardType::MEMORY_MODULE:            return "MEMORY_MODULE";
        case DmiBaseboardType::DAUGHTER_BOARD:           return "DAUGHTER_BOARD";
        case DmiBaseboardType::MOTHERBOARD:              return "MOTHERBOARD";
        case DmiBaseboardType::PROCESSOR_MEMORY_MODULE:  return "PROCESSOR_MEMORY_MODULE";
        case DmiBaseboardType::PROCESSOR_IO_MODULE:      return "PROCESSOR_IO_MODULE";
        case DmiBaseboardType::INTERCONNECT_BOARD:       return "INTERCONNECT_BOARD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBaseboardType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDTYPE_H
