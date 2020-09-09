// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11489E00_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11489E00_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11489E00: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11482100 = 0x11482100,
    SUBDEVICE_114821D0 = 0x114821D0,
    SUBDEVICE_11482200 = 0x11482200,
    SUBDEVICE_11488100 = 0x11488100,
    SUBDEVICE_11488200 = 0x11488200,
    SUBDEVICE_11489100 = 0x11489100,
    SUBDEVICE_11489200 = 0x11489200
};



inline const char8* enumToString(PciSubDevice11489E00 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11489E00::NONE:               return "NONE";
        case PciSubDevice11489E00::SUBDEVICE_11482100: return "SUBDEVICE_11482100";
        case PciSubDevice11489E00::SUBDEVICE_114821D0: return "SUBDEVICE_114821D0";
        case PciSubDevice11489E00::SUBDEVICE_11482200: return "SUBDEVICE_11482200";
        case PciSubDevice11489E00::SUBDEVICE_11488100: return "SUBDEVICE_11488100";
        case PciSubDevice11489E00::SUBDEVICE_11488200: return "SUBDEVICE_11488200";
        case PciSubDevice11489E00::SUBDEVICE_11489100: return "SUBDEVICE_11489100";
        case PciSubDevice11489E00::SUBDEVICE_11489200: return "SUBDEVICE_11489200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11489E00 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11489E00 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11489E00::SUBDEVICE_11482100: return "SK-9E21 Server Adapter";
        case PciSubDevice11489E00::SUBDEVICE_114821D0: return "SK-9E21D 10/100/1000Base-T Adapter";
        case PciSubDevice11489E00::SUBDEVICE_11482200: return "SK-9E22 Server Adapter";
        case PciSubDevice11489E00::SUBDEVICE_11488100: return "SK-9E81 Server Adapter";
        case PciSubDevice11489E00::SUBDEVICE_11488200: return "SK-9E82 Server Adapter";
        case PciSubDevice11489E00::SUBDEVICE_11489100: return "SK-9E91 Server Adapter";
        case PciSubDevice11489E00::SUBDEVICE_11489200: return "SK-9E92 Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11489E00_H
