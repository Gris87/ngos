// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026751_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026751_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026751: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280548 = 0x10280548,
    SUBDEVICE_14622671 = 0x14622671,
    SUBDEVICE_14622672 = 0x14622672,
    SUBDEVICE_14622680 = 0x14622680,
    SUBDEVICE_14622681 = 0x14622681,
    SUBDEVICE_17AA3087 = 0x17AA3087
};



inline const char8* enumToString(PciSubDevice10026751 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026751::NONE:               return "NONE";
        case PciSubDevice10026751::SUBDEVICE_10280548: return "SUBDEVICE_10280548";
        case PciSubDevice10026751::SUBDEVICE_14622671: return "SUBDEVICE_14622671";
        case PciSubDevice10026751::SUBDEVICE_14622672: return "SUBDEVICE_14622672";
        case PciSubDevice10026751::SUBDEVICE_14622680: return "SUBDEVICE_14622680";
        case PciSubDevice10026751::SUBDEVICE_14622681: return "SUBDEVICE_14622681";
        case PciSubDevice10026751::SUBDEVICE_17AA3087: return "SUBDEVICE_17AA3087";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026751 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026751 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026751::SUBDEVICE_10280548: return "Radeon HD 7650A";
        case PciSubDevice10026751::SUBDEVICE_14622671: return "Radeon HD 7670A";
        case PciSubDevice10026751::SUBDEVICE_14622672: return "Radeon HD 7670A";
        case PciSubDevice10026751::SUBDEVICE_14622680: return "Radeon HD 7650A";
        case PciSubDevice10026751::SUBDEVICE_14622681: return "Radeon HD 7650A";
        case PciSubDevice10026751::SUBDEVICE_17AA3087: return "Radeon HD 7650A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026751_H
