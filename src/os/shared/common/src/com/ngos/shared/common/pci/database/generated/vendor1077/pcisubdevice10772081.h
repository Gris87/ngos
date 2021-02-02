// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772081_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772081_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772081: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107702E1 = 0x107702E1,
    SUBDEVICE_107702E3 = 0x107702E3
};



inline const char8* enumToString(PciSubDevice10772081 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772081::NONE:               return "NONE";
        case PciSubDevice10772081::SUBDEVICE_107702E1: return "SUBDEVICE_107702E1";
        case PciSubDevice10772081::SUBDEVICE_107702E3: return "SUBDEVICE_107702E3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772081 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772081 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772081::SUBDEVICE_107702E1: return "QLE2874 Quad Port 64GFC PCIe Gen4 x16 Adapter";
        case PciSubDevice10772081::SUBDEVICE_107702E3: return "QLE2774 Quad Port 32GFC PCIe Gen4 x16 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772081_H
