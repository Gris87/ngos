// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140601_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140601_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18140601: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1799801C = 0x1799801C,
    SUBDEVICE_187E3412 = 0x187E3412
};



inline const char8* enumToString(PciSubDevice18140601 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140601::NONE:               return "NONE";
        case PciSubDevice18140601::SUBDEVICE_1799801C: return "SUBDEVICE_1799801C";
        case PciSubDevice18140601::SUBDEVICE_187E3412: return "SUBDEVICE_187E3412";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18140601 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18140601 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140601::SUBDEVICE_1799801C: return "F5D8011 v3 802.11n N1 Wireless Notebook Card";
        case PciSubDevice18140601::SUBDEVICE_187E3412: return "NWD-310N 802.11n Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140601_H
