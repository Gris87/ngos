// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063106_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063106_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063106: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11060105 = 0x11060105,
    SUBDEVICE_11861403 = 0x11861403,
    SUBDEVICE_11861405 = 0x11861405,
    SUBDEVICE_11861406 = 0x11861406,
    SUBDEVICE_11861407 = 0x11861407
};



inline const char8* enumToString(PciSubDevice11063106 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063106::NONE:               return "NONE";
        case PciSubDevice11063106::SUBDEVICE_11060105: return "SUBDEVICE_11060105";
        case PciSubDevice11063106::SUBDEVICE_11861403: return "SUBDEVICE_11861403";
        case PciSubDevice11063106::SUBDEVICE_11861405: return "SUBDEVICE_11861405";
        case PciSubDevice11063106::SUBDEVICE_11861406: return "SUBDEVICE_11861406";
        case PciSubDevice11063106::SUBDEVICE_11861407: return "SUBDEVICE_11861407";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063106 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063106 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063106::SUBDEVICE_11060105: return "VT6106S [Rhine-III]";
        case PciSubDevice11063106::SUBDEVICE_11861403: return "DFE-530TX PCI Fast Ethernet Adapter (rev. C)";
        case PciSubDevice11063106::SUBDEVICE_11861405: return "DFE-520TX Fast Ethernet PCI Adapter";
        case PciSubDevice11063106::SUBDEVICE_11861406: return "DFE-530TX+ rev F2";
        case PciSubDevice11063106::SUBDEVICE_11861407: return "DFE-538TX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063106_H
