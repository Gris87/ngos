// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4432B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4432B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4432B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028000D = 0x1028000D,
    SUBDEVICE_106B008D = 0x106B008D,
    SUBDEVICE_106B008E = 0x106B008E
};



inline const char8* enumToString(PciSubDevice14E4432B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4432B::NONE:               return "NONE";
        case PciSubDevice14E4432B::SUBDEVICE_1028000D: return "SUBDEVICE_1028000D";
        case PciSubDevice14E4432B::SUBDEVICE_106B008D: return "SUBDEVICE_106B008D";
        case PciSubDevice14E4432B::SUBDEVICE_106B008E: return "SUBDEVICE_106B008E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4432B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4432B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4432B::SUBDEVICE_1028000D: return "Wireless 1510 Wireless-N WLAN Mini-Card";
        case PciSubDevice14E4432B::SUBDEVICE_106B008D: return "AirPort Extreme";
        case PciSubDevice14E4432B::SUBDEVICE_106B008E: return "AirPort Extreme";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4432B_H
