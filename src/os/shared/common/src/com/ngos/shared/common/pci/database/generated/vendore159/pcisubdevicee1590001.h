// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE159_PCISUBDEVICEE1590001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE159_PCISUBDEVICEE1590001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDeviceE1590001: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00590001 = 0x00590001,
    SUBDEVICE_00590003 = 0x00590003,
    SUBDEVICE_00A70001 = 0x00A70001,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_B1000003 = 0xB1000003,
    SUBDEVICE_B1D90003 = 0xB1D90003
};



inline const char8* enumToString(PciSubDeviceE1590001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceE1590001::NONE:               return "NONE";
        case PciSubDeviceE1590001::SUBDEVICE_00590001: return "SUBDEVICE_00590001";
        case PciSubDeviceE1590001::SUBDEVICE_00590003: return "SUBDEVICE_00590003";
        case PciSubDeviceE1590001::SUBDEVICE_00A70001: return "SUBDEVICE_00A70001";
        case PciSubDeviceE1590001::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDeviceE1590001::SUBDEVICE_B1000003: return "SUBDEVICE_B1000003";
        case PciSubDeviceE1590001::SUBDEVICE_B1D90003: return "SUBDEVICE_B1D90003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDeviceE1590001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDeviceE1590001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceE1590001::SUBDEVICE_00590001: return "128k ISDN-S/T Adapter";
        case PciSubDeviceE1590001::SUBDEVICE_00590003: return "128k ISDN-U Adapter";
        case PciSubDeviceE1590001::SUBDEVICE_00A70001: return "TELES.S0/PCI 2.x ISDN Adapter";
        case PciSubDeviceE1590001::SUBDEVICE_80860003: return "Digium X100P/X101P analogue PSTN FXO interface";
        case PciSubDeviceE1590001::SUBDEVICE_B1000003: return "OpenVox A400P 4-port analog card";
        case PciSubDeviceE1590001::SUBDEVICE_B1D90003: return "AX400P 4-port analog card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE159_PCISUBDEVICEE1590001_H
