#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICEADDRESSTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICEADDRESSTYPE_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiManagementDeviceAddressType: u8
{
    NONE    = 0,
    OTHER   = 1,
    UNKNOWN = 2,
    IO_PORT = 3,
    MEMORY  = 4,
    SM_BUS  = 5
};



inline const char8* enumToString(DmiManagementDeviceAddressType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiManagementDeviceAddressType::NONE:    return "NONE";
        case DmiManagementDeviceAddressType::OTHER:   return "OTHER";
        case DmiManagementDeviceAddressType::UNKNOWN: return "UNKNOWN";
        case DmiManagementDeviceAddressType::IO_PORT: return "IO_PORT";
        case DmiManagementDeviceAddressType::MEMORY:  return "MEMORY";
        case DmiManagementDeviceAddressType::SM_BUS:  return "SM_BUS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiManagementDeviceAddressType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICEADDRESSTYPE_H
