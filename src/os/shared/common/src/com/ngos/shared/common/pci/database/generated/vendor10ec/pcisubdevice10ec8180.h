// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8180_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8180_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8180: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13854700 = 0x13854700,
    SUBDEVICE_17370019 = 0x17370019
};



inline const char8* enumToString(PciSubDevice10EC8180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8180::NONE:               return "NONE";
        case PciSubDevice10EC8180::SUBDEVICE_13854700: return "SUBDEVICE_13854700";
        case PciSubDevice10EC8180::SUBDEVICE_17370019: return "SUBDEVICE_17370019";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8180::SUBDEVICE_13854700: return "MA521 802.11b Wireless PC Card";
        case PciSubDevice10EC8180::SUBDEVICE_17370019: return "WPC11v4 802.11b Wireless-B Notebook Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8180_H
