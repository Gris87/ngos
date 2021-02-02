// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800552_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800552_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800552: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140511 = 0x10140511,
    SUBDEVICE_1028014F = 0x1028014F,
    SUBDEVICE_10280188 = 0x10280188,
    SUBDEVICE_10431237 = 0x10431237,
    SUBDEVICE_10431757 = 0x10431757,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_17AA201E = 0x17AA201E
};



inline const char8* enumToString(PciSubDevice11800552 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800552::NONE:               return "NONE";
        case PciSubDevice11800552::SUBDEVICE_10140511: return "SUBDEVICE_10140511";
        case PciSubDevice11800552::SUBDEVICE_1028014F: return "SUBDEVICE_1028014F";
        case PciSubDevice11800552::SUBDEVICE_10280188: return "SUBDEVICE_10280188";
        case PciSubDevice11800552::SUBDEVICE_10431237: return "SUBDEVICE_10431237";
        case PciSubDevice11800552::SUBDEVICE_10431757: return "SUBDEVICE_10431757";
        case PciSubDevice11800552::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice11800552::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice11800552::SUBDEVICE_17AA201E: return "SUBDEVICE_17AA201E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800552 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800552 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800552::SUBDEVICE_10140511: return "ThinkPad A/T/X Series";
        case PciSubDevice11800552::SUBDEVICE_1028014F: return "Latitude X300 laptop";
        case PciSubDevice11800552::SUBDEVICE_10280188: return "Inspiron 6000 laptop";
        case PciSubDevice11800552::SUBDEVICE_10431237: return "A6J-Q008";
        case PciSubDevice11800552::SUBDEVICE_10431757: return "M2400N laptop";
        case PciSubDevice11800552::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice11800552::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice11800552::SUBDEVICE_17AA201E: return "ThinkPad X60/X60s";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800552_H
