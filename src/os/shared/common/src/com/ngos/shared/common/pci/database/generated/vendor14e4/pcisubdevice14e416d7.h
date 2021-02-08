// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416D7: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14E41202 = 0x14E41202,
    SUBDEVICE_14E41402 = 0x14E41402,
    SUBDEVICE_14E41404 = 0x14E41404,
    SUBDEVICE_14E44140 = 0x14E44140,
    SUBDEVICE_14E44146 = 0x14E44146,
    SUBDEVICE_1590020E = 0x1590020E,
    SUBDEVICE_15900211 = 0x15900211
};



inline const char8* enumToString(PciSubDevice14E416D7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416D7::NONE:               return "NONE";
        case PciSubDevice14E416D7::SUBDEVICE_14E41202: return "SUBDEVICE_14E41202";
        case PciSubDevice14E416D7::SUBDEVICE_14E41402: return "SUBDEVICE_14E41402";
        case PciSubDevice14E416D7::SUBDEVICE_14E41404: return "SUBDEVICE_14E41404";
        case PciSubDevice14E416D7::SUBDEVICE_14E44140: return "SUBDEVICE_14E44140";
        case PciSubDevice14E416D7::SUBDEVICE_14E44146: return "SUBDEVICE_14E44146";
        case PciSubDevice14E416D7::SUBDEVICE_1590020E: return "SUBDEVICE_1590020E";
        case PciSubDevice14E416D7::SUBDEVICE_15900211: return "SUBDEVICE_15900211";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416D7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416D7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416D7::SUBDEVICE_14E41202: return "BCM957412M4122C OCP 1x25G Type1 wRoCE";
        case PciSubDevice14E416D7::SUBDEVICE_14E41402: return "BCM957414A4142CC 10Gb/25Gb Ethernet PCIe";
        case PciSubDevice14E416D7::SUBDEVICE_14E41404: return "BCM957414M4142C OCP 2x25G Type1 wRoCE";
        case PciSubDevice14E416D7::SUBDEVICE_14E44140: return "NetXtreme E-Series Advanced Dual-port 25Gb SFP28 Network Daughter Card";
        case PciSubDevice14E416D7::SUBDEVICE_14E44146: return "NetXtreme-E Dual-port 25G SFP28 Ethernet OCP 3.0 Adapter (BCM957414N4140C)";
        case PciSubDevice14E416D7::SUBDEVICE_1590020E: return "Ethernet 25Gb 2-port 631SFP28 Adapter";
        case PciSubDevice14E416D7::SUBDEVICE_15900211: return "Ethernet 25Gb 2-port 631FLR-SFP28 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D7_H
