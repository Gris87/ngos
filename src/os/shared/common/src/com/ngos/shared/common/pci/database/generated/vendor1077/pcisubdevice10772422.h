// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772422_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772422_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772422: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C12D7 = 0x103C12D7,
    SUBDEVICE_103C12DD = 0x103C12DD
};



inline const char8* enumToString(PciSubDevice10772422 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772422::NONE:               return "NONE";
        case PciSubDevice10772422::SUBDEVICE_103C12D7: return "SUBDEVICE_103C12D7";
        case PciSubDevice10772422::SUBDEVICE_103C12DD: return "SUBDEVICE_103C12DD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772422 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772422 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772422::SUBDEVICE_103C12D7: return "4Gb Fibre Channel [AB379A]";
        case PciSubDevice10772422::SUBDEVICE_103C12DD: return "4Gb Fibre Channel [AB429A]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772422_H
