#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYDEVICECHEMISTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYDEVICECHEMISTRY_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiPortableBatteryDeviceChemistry: u8
{
    NONE                 = 0,
    OTHER                = 1,
    UNKNOWN              = 2,
    LEAD_ACID            = 3,
    NICKEL_CADMIUM       = 4,
    NICKEL_METAL_HYDRIDE = 5,
    LITHIUM_ION          = 6,
    ZINC_AIR             = 7,
    LITHIUM_POLYMER      = 8
};



inline const char8* enumToString(DmiPortableBatteryDeviceChemistry chemistry) // TEST: NO
{
    // COMMON_LT((" | chemistry = %u", chemistry)); // Commented to avoid bad looking logs



    switch (chemistry)
    {
        case DmiPortableBatteryDeviceChemistry::NONE:                 return "NONE";
        case DmiPortableBatteryDeviceChemistry::OTHER:                return "OTHER";
        case DmiPortableBatteryDeviceChemistry::UNKNOWN:              return "UNKNOWN";
        case DmiPortableBatteryDeviceChemistry::LEAD_ACID:            return "LEAD_ACID";
        case DmiPortableBatteryDeviceChemistry::NICKEL_CADMIUM:       return "NICKEL_CADMIUM";
        case DmiPortableBatteryDeviceChemistry::NICKEL_METAL_HYDRIDE: return "NICKEL_METAL_HYDRIDE";
        case DmiPortableBatteryDeviceChemistry::LITHIUM_ION:          return "LITHIUM_ION";
        case DmiPortableBatteryDeviceChemistry::ZINC_AIR:             return "ZINC_AIR";
        case DmiPortableBatteryDeviceChemistry::LITHIUM_POLYMER:      return "LITHIUM_POLYMER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiPortableBatteryDeviceChemistry chemistry) // TEST: NO
{
    // COMMON_LT((" | chemistry = %u", chemistry)); // Commented to avoid bad looking logs



    static char8 res[28];

    sprintf(res, "0x%02X (%s)", chemistry, enumToString(chemistry));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYDEVICECHEMISTRY_H
