// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C2839_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C2839_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C5C2839: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282143 = 0x10282143,
    SUBDEVICE_10282144 = 0x10282144,
    SUBDEVICE_10282145 = 0x10282145,
    SUBDEVICE_10282146 = 0x10282146,
    SUBDEVICE_10282147 = 0x10282147,
    SUBDEVICE_10282148 = 0x10282148,
    SUBDEVICE_10282149 = 0x10282149,
    SUBDEVICE_1028214A = 0x1028214A,
    SUBDEVICE_1C5C0100 = 0x1C5C0100
};



inline const char8* enumToString(PciSubDevice1C5C2839 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5C2839::NONE:               return "NONE";
        case PciSubDevice1C5C2839::SUBDEVICE_10282143: return "SUBDEVICE_10282143";
        case PciSubDevice1C5C2839::SUBDEVICE_10282144: return "SUBDEVICE_10282144";
        case PciSubDevice1C5C2839::SUBDEVICE_10282145: return "SUBDEVICE_10282145";
        case PciSubDevice1C5C2839::SUBDEVICE_10282146: return "SUBDEVICE_10282146";
        case PciSubDevice1C5C2839::SUBDEVICE_10282147: return "SUBDEVICE_10282147";
        case PciSubDevice1C5C2839::SUBDEVICE_10282148: return "SUBDEVICE_10282148";
        case PciSubDevice1C5C2839::SUBDEVICE_10282149: return "SUBDEVICE_10282149";
        case PciSubDevice1C5C2839::SUBDEVICE_1028214A: return "SUBDEVICE_1028214A";
        case PciSubDevice1C5C2839::SUBDEVICE_1C5C0100: return "SUBDEVICE_1C5C0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C5C2839 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C5C2839 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5C2839::SUBDEVICE_10282143: return "DC NVMe SED PE8010 RI U.2 960GB";
        case PciSubDevice1C5C2839::SUBDEVICE_10282144: return "DC NVMe PE8010 RI U.2 960GB";
        case PciSubDevice1C5C2839::SUBDEVICE_10282145: return "DC NVMe SED PE8010 RI U.2 1.92TB";
        case PciSubDevice1C5C2839::SUBDEVICE_10282146: return "DC NVMe PE8010 RI U.2 1.92TB";
        case PciSubDevice1C5C2839::SUBDEVICE_10282147: return "DC NVMe SED PE8010 RI U.2 3.84TB";
        case PciSubDevice1C5C2839::SUBDEVICE_10282148: return "DC NVMe PE8010 RI U.2 3.84TB";
        case PciSubDevice1C5C2839::SUBDEVICE_10282149: return "DC NVMe SED PE8010 RI U.2 7.68TB";
        case PciSubDevice1C5C2839::SUBDEVICE_1028214A: return "DC NVMe PE8010 RI U.2 7.68TB";
        case PciSubDevice1C5C2839::SUBDEVICE_1C5C0100: return "PE8000 Series NVMe Solid State Drive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCISUBDEVICE1C5C2839_H
