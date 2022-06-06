#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICEADDRESSTYPE_H                                                                                                                            // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICEADDRESSTYPE_H                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class DmiManagementDeviceAddressType: u8                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE    = 0,                                                                                                                                                                                         // Colorize: green
    OTHER   = 1,                                                                                                                                                                                         // Colorize: green
    UNKNOWN = 2,                                                                                                                                                                                         // Colorize: green
    IO_PORT = 3,                                                                                                                                                                                         // Colorize: green
    MEMORY  = 4,                                                                                                                                                                                         // Colorize: green
    SM_BUS  = 5                                                                                                                                                                                          // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiManagementDeviceAddressType type) // TEST: NO                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiManagementDeviceAddressType::NONE:    return "NONE";                                                                                                                                     // Colorize: green
        case DmiManagementDeviceAddressType::OTHER:   return "OTHER";                                                                                                                                    // Colorize: green
        case DmiManagementDeviceAddressType::UNKNOWN: return "UNKNOWN";                                                                                                                                  // Colorize: green
        case DmiManagementDeviceAddressType::IO_PORT: return "IO_PORT";                                                                                                                                  // Colorize: green
        case DmiManagementDeviceAddressType::MEMORY:  return "MEMORY";                                                                                                                                   // Colorize: green
        case DmiManagementDeviceAddressType::SM_BUS:  return "SM_BUS";                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiManagementDeviceAddressType type) // TEST: NO                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[15];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICEADDRESSTYPE_H                                                                                                                          // Colorize: green