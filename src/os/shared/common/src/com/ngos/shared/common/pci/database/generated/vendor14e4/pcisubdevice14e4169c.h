// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4169C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4169C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4169C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C308B = 0x103C308B,
    SUBDEVICE_103C30A1 = 0x103C30A1,
    SUBDEVICE_144DC018 = 0x144DC018,
    SUBDEVICE_1462590C = 0x1462590C
};



inline const char8* enumToString(PciSubDevice14E4169C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4169C::NONE:               return "NONE";
        case PciSubDevice14E4169C::SUBDEVICE_103C308B: return "SUBDEVICE_103C308B";
        case PciSubDevice14E4169C::SUBDEVICE_103C30A1: return "SUBDEVICE_103C30A1";
        case PciSubDevice14E4169C::SUBDEVICE_144DC018: return "SUBDEVICE_144DC018";
        case PciSubDevice14E4169C::SUBDEVICE_1462590C: return "SUBDEVICE_1462590C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4169C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4169C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4169C::SUBDEVICE_103C308B: return "MX6125";
        case PciSubDevice14E4169C::SUBDEVICE_103C30A1: return "NC2400";
        case PciSubDevice14E4169C::SUBDEVICE_144DC018: return "X20";
        case PciSubDevice14E4169C::SUBDEVICE_1462590C: return "KT6 Delta-FIS2R (MS-6590)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4169C_H
