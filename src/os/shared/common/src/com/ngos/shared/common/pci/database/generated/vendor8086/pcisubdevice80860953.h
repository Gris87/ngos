// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860953_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860953_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860953: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80863702 = 0x80863702,
    SUBDEVICE_80863703 = 0x80863703,
    SUBDEVICE_80863704 = 0x80863704,
    SUBDEVICE_80863705 = 0x80863705,
    SUBDEVICE_80863709 = 0x80863709,
    SUBDEVICE_8086370A = 0x8086370A,
    SUBDEVICE_8086370D = 0x8086370D,
    SUBDEVICE_8086370E = 0x8086370E
};



inline const char8* enumToString(PciSubDevice80860953 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860953::NONE:               return "NONE";
        case PciSubDevice80860953::SUBDEVICE_80863702: return "SUBDEVICE_80863702";
        case PciSubDevice80860953::SUBDEVICE_80863703: return "SUBDEVICE_80863703";
        case PciSubDevice80860953::SUBDEVICE_80863704: return "SUBDEVICE_80863704";
        case PciSubDevice80860953::SUBDEVICE_80863705: return "SUBDEVICE_80863705";
        case PciSubDevice80860953::SUBDEVICE_80863709: return "SUBDEVICE_80863709";
        case PciSubDevice80860953::SUBDEVICE_8086370A: return "SUBDEVICE_8086370A";
        case PciSubDevice80860953::SUBDEVICE_8086370D: return "SUBDEVICE_8086370D";
        case PciSubDevice80860953::SUBDEVICE_8086370E: return "SUBDEVICE_8086370E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860953 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860953 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860953::SUBDEVICE_80863702: return "DC P3700 SSD";
        case PciSubDevice80860953::SUBDEVICE_80863703: return "DC P3700 SSD [2.5\" SFF]";
        case PciSubDevice80860953::SUBDEVICE_80863704: return "DC P3500 SSD [Add-in Card]";
        case PciSubDevice80860953::SUBDEVICE_80863705: return "DC P3500 SSD [2.5\" SFF]";
        case PciSubDevice80860953::SUBDEVICE_80863709: return "DC P3600 SSD [Add-in Card]";
        case PciSubDevice80860953::SUBDEVICE_8086370A: return "DC P3600 SSD [2.5\" SFF]";
        case PciSubDevice80860953::SUBDEVICE_8086370D: return "SSD 750 Series [Add-in Card]";
        case PciSubDevice80860953::SUBDEVICE_8086370E: return "SSD 750 Series [2.5\" SFF]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860953_H
