#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDTYPE_H



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



inline const char8* dmiBaseboardTypeToString(DmiBaseboardType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiBaseboardType::NONE:              return "NONE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDTYPE_H
