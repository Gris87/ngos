// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627A1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_10718209 = 0x10718209
};



inline const char8* enumToString(PciSubDevice808627A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627A1::NONE:               return "NONE";
        case PciSubDevice808627A1::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice808627A1::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice808627A1::SUBDEVICE_10718209: return "SUBDEVICE_10718209";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627A1::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice808627A1::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice808627A1::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A1_H
