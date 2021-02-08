// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060691_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060691_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060691: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190985 = 0x10190985,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_14580691 = 0x14580691
};



inline const char8* enumToString(PciSubDevice11060691 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060691::NONE:               return "NONE";
        case PciSubDevice11060691::SUBDEVICE_10190985: return "SUBDEVICE_10190985";
        case PciSubDevice11060691::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11060691::SUBDEVICE_14580691: return "SUBDEVICE_14580691";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060691 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060691 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060691::SUBDEVICE_10190985: return "P6VXA Motherboard";
        case PciSubDevice11060691::SUBDEVICE_11790001: return "Magnia Z310";
        case PciSubDevice11060691::SUBDEVICE_14580691: return "VT82C691 Apollo Pro System Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060691_H
