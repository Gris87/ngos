// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00F1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00F1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE00F1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104381A6 = 0x104381A6,
    SUBDEVICE_104381C6 = 0x104381C6,
    SUBDEVICE_14583150 = 0x14583150,
    SUBDEVICE_15541191 = 0x15541191,
    SUBDEVICE_16822119 = 0x16822119
};



inline const char8* enumToString(PciSubDevice10DE00F1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00F1::NONE:               return "NONE";
        case PciSubDevice10DE00F1::SUBDEVICE_104381A6: return "SUBDEVICE_104381A6";
        case PciSubDevice10DE00F1::SUBDEVICE_104381C6: return "SUBDEVICE_104381C6";
        case PciSubDevice10DE00F1::SUBDEVICE_14583150: return "SUBDEVICE_14583150";
        case PciSubDevice10DE00F1::SUBDEVICE_15541191: return "SUBDEVICE_15541191";
        case PciSubDevice10DE00F1::SUBDEVICE_16822119: return "SUBDEVICE_16822119";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE00F1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE00F1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00F1::SUBDEVICE_104381A6: return "N6600GT TD 128M AGP";
        case PciSubDevice10DE00F1::SUBDEVICE_104381C6: return "N6600GT TD 128M AGP";
        case PciSubDevice10DE00F1::SUBDEVICE_14583150: return "GV-N66T128VP";
        case PciSubDevice10DE00F1::SUBDEVICE_15541191: return "PixelView PV-N43UA (128KD)";
        case PciSubDevice10DE00F1::SUBDEVICE_16822119: return "GeForce 6600 GT AGP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00F1_H
