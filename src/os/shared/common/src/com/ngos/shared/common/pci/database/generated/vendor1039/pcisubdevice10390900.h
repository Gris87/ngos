// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10390900_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10390900_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10390900: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190A14 = 0x10190A14,
    SUBDEVICE_10390900 = 0x10390900,
    SUBDEVICE_10438035 = 0x10438035,
    SUBDEVICE_104380A7 = 0x104380A7,
    SUBDEVICE_14620900 = 0x14620900
};



inline const char8* enumToString(PciSubDevice10390900 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10390900::NONE:               return "NONE";
        case PciSubDevice10390900::SUBDEVICE_10190A14: return "SUBDEVICE_10190A14";
        case PciSubDevice10390900::SUBDEVICE_10390900: return "SUBDEVICE_10390900";
        case PciSubDevice10390900::SUBDEVICE_10438035: return "SUBDEVICE_10438035";
        case PciSubDevice10390900::SUBDEVICE_104380A7: return "SUBDEVICE_104380A7";
        case PciSubDevice10390900::SUBDEVICE_14620900: return "SUBDEVICE_14620900";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10390900 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10390900 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10390900::SUBDEVICE_10190A14: return "K7S5A motherboard";
        case PciSubDevice10390900::SUBDEVICE_10390900: return "SiS900 10/100 Ethernet Adapter onboard";
        case PciSubDevice10390900::SUBDEVICE_10438035: return "CUSI-FX motherboard";
        case PciSubDevice10390900::SUBDEVICE_104380A7: return "Motherboard P4S800D-X";
        case PciSubDevice10390900::SUBDEVICE_14620900: return "MS-6701 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10390900_H
