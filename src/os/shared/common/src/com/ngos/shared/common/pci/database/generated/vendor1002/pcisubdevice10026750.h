// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026750_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026750_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026750: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14622670 = 0x14622670,
    SUBDEVICE_17AA3079 = 0x17AA3079,
    SUBDEVICE_17AA307A = 0x17AA307A,
    SUBDEVICE_17AA3087 = 0x17AA3087,
    SUBDEVICE_17AA3618 = 0x17AA3618,
    SUBDEVICE_17AA3623 = 0x17AA3623,
    SUBDEVICE_17AA3627 = 0x17AA3627
};



inline const char8* enumToString(PciSubDevice10026750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026750::NONE:               return "NONE";
        case PciSubDevice10026750::SUBDEVICE_14622670: return "SUBDEVICE_14622670";
        case PciSubDevice10026750::SUBDEVICE_17AA3079: return "SUBDEVICE_17AA3079";
        case PciSubDevice10026750::SUBDEVICE_17AA307A: return "SUBDEVICE_17AA307A";
        case PciSubDevice10026750::SUBDEVICE_17AA3087: return "SUBDEVICE_17AA3087";
        case PciSubDevice10026750::SUBDEVICE_17AA3618: return "SUBDEVICE_17AA3618";
        case PciSubDevice10026750::SUBDEVICE_17AA3623: return "SUBDEVICE_17AA3623";
        case PciSubDevice10026750::SUBDEVICE_17AA3627: return "SUBDEVICE_17AA3627";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026750::SUBDEVICE_14622670: return "Radeon HD 6670A";
        case PciSubDevice10026750::SUBDEVICE_17AA3079: return "Radeon HD 7650A";
        case PciSubDevice10026750::SUBDEVICE_17AA307A: return "Radeon HD 6650A";
        case PciSubDevice10026750::SUBDEVICE_17AA3087: return "Radeon HD 7650A";
        case PciSubDevice10026750::SUBDEVICE_17AA3618: return "Radeon HD 6650A";
        case PciSubDevice10026750::SUBDEVICE_17AA3623: return "Radeon HD 6650A";
        case PciSubDevice10026750::SUBDEVICE_17AA3627: return "Radeon HD 6650A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026750_H
