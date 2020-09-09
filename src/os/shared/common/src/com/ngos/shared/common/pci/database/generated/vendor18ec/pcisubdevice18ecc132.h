// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCISUBDEVICE18ECC132_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCISUBDEVICE18ECC132_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18ECC132: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_18EC0100 = 0x18EC0100,
    SUBDEVICE_18EC0200 = 0x18EC0200,
    SUBDEVICE_18EC0201 = 0x18EC0201,
    SUBDEVICE_18EC0300 = 0x18EC0300,
    SUBDEVICE_18EC0302 = 0x18EC0302,
    SUBDEVICE_18EC4200 = 0x18EC4200,
    SUBDEVICE_18ECFF00 = 0x18ECFF00,
    SUBDEVICE_18ECFF01 = 0x18ECFF01
};



inline const char8* enumToString(PciSubDevice18ECC132 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18ECC132::NONE:               return "NONE";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0100: return "SUBDEVICE_18EC0100";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0200: return "SUBDEVICE_18EC0200";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0201: return "SUBDEVICE_18EC0201";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0300: return "SUBDEVICE_18EC0300";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0302: return "SUBDEVICE_18EC0302";
        case PciSubDevice18ECC132::SUBDEVICE_18EC4200: return "SUBDEVICE_18EC4200";
        case PciSubDevice18ECC132::SUBDEVICE_18ECFF00: return "SUBDEVICE_18ECFF00";
        case PciSubDevice18ECC132::SUBDEVICE_18ECFF01: return "SUBDEVICE_18ECFF01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18ECC132 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18ECC132 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18ECC132::SUBDEVICE_18EC0100: return "NIC (ethernet interfaces)";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0200: return "NIC (szedata2) 4x1G";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0201: return "NIC (szedata2) 2x10G";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0300: return "NIFIC (szedata2) 4x1G";
        case PciSubDevice18ECC132::SUBDEVICE_18EC0302: return "NIFIC (szedata2) 2x10G";
        case PciSubDevice18ECC132::SUBDEVICE_18EC4200: return "Flexible FlowMon (szedata2) 1x10G";
        case PciSubDevice18ECC132::SUBDEVICE_18ECFF00: return "Testing design";
        case PciSubDevice18ECC132::SUBDEVICE_18ECFF01: return "Boot design";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCISUBDEVICE18ECC132_H
