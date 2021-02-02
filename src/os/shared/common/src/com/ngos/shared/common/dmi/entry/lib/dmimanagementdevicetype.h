#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICETYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiManagementDeviceType: bad_uint8
{
    NONE                         = 0,
    OTHER                        = 1,
    UNKNOWN                      = 2,
    NATIONAL_SEMICONDUCTOR_LM_75 = 3,
    NATIONAL_SEMICONDUCTOR_LM_78 = 4,
    NATIONAL_SEMICONDUCTOR_LM_79 = 5,
    NATIONAL_SEMICONDUCTOR_LM_80 = 6,
    NATIONAL_SEMICONDUCTOR_LM_81 = 7,
    ANALOG_DEVICES_ADM9240       = 8,
    DALLAS_SEMICONDUCTOR_DS1780  = 9,
    MAXIM_1617                   = 10,
    GENESYS_GL518SM              = 11,
    WINBOND_W83781D              = 12,
    HOLTEK_HT82H791              = 13
};



inline const char8* enumToString(DmiManagementDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiManagementDeviceType::NONE:                         return "NONE";
        case DmiManagementDeviceType::OTHER:                        return "OTHER";
        case DmiManagementDeviceType::UNKNOWN:                      return "UNKNOWN";
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_75: return "NATIONAL_SEMICONDUCTOR_LM_75";
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_78: return "NATIONAL_SEMICONDUCTOR_LM_78";
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_79: return "NATIONAL_SEMICONDUCTOR_LM_79";
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_80: return "NATIONAL_SEMICONDUCTOR_LM_80";
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_81: return "NATIONAL_SEMICONDUCTOR_LM_81";
        case DmiManagementDeviceType::ANALOG_DEVICES_ADM9240:       return "ANALOG_DEVICES_ADM9240";
        case DmiManagementDeviceType::DALLAS_SEMICONDUCTOR_DS1780:  return "DALLAS_SEMICONDUCTOR_DS1780";
        case DmiManagementDeviceType::MAXIM_1617:                   return "MAXIM_1617";
        case DmiManagementDeviceType::GENESYS_GL518SM:              return "GENESYS_GL518SM";
        case DmiManagementDeviceType::WINBOND_W83781D:              return "WINBOND_W83781D";
        case DmiManagementDeviceType::HOLTEK_HT82H791:              return "HOLTEK_HT82H791";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiManagementDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[36];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICETYPE_H
