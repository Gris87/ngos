// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063227_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063227_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063227: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380ED = 0x104380ED,
    SUBDEVICE_11063227 = 0x11063227,
    SUBDEVICE_14585001 = 0x14585001,
    SUBDEVICE_147B1407 = 0x147B1407,
    SUBDEVICE_18493227 = 0x18493227
};



inline const char8* enumToString(PciSubDevice11063227 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063227::NONE:               return "NONE";
        case PciSubDevice11063227::SUBDEVICE_104380ED: return "SUBDEVICE_104380ED";
        case PciSubDevice11063227::SUBDEVICE_11063227: return "SUBDEVICE_11063227";
        case PciSubDevice11063227::SUBDEVICE_14585001: return "SUBDEVICE_14585001";
        case PciSubDevice11063227::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";
        case PciSubDevice11063227::SUBDEVICE_18493227: return "SUBDEVICE_18493227";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063227 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063227 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063227::SUBDEVICE_104380ED: return "A7V600/K8V-X/A8V Deluxe motherboard";
        case PciSubDevice11063227::SUBDEVICE_11063227: return "DFI KT600-AL / Soltek SL-B9D-FGR Motherboard";
        case PciSubDevice11063227::SUBDEVICE_14585001: return "GA-7VT600 Motherboard";
        case PciSubDevice11063227::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";
        case PciSubDevice11063227::SUBDEVICE_18493227: return "K7VT4 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063227_H
