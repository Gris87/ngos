// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026837_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026837_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026837: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14622796 = 0x14622796,
    SUBDEVICE_14628092 = 0x14628092,
    SUBDEVICE_148C8730 = 0x148C8730,
    SUBDEVICE_17873000 = 0x17873000
};



inline const char8* enumToString(PciSubDevice10026837 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026837::NONE:               return "NONE";
        case PciSubDevice10026837::SUBDEVICE_14622796: return "SUBDEVICE_14622796";
        case PciSubDevice10026837::SUBDEVICE_14628092: return "SUBDEVICE_14628092";
        case PciSubDevice10026837::SUBDEVICE_148C8730: return "SUBDEVICE_148C8730";
        case PciSubDevice10026837::SUBDEVICE_17873000: return "SUBDEVICE_17873000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026837 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026837 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026837::SUBDEVICE_14622796: return "Radeon HD 8730";
        case PciSubDevice10026837::SUBDEVICE_14628092: return "Radeon HD 8730";
        case PciSubDevice10026837::SUBDEVICE_148C8730: return "Radeon HD 8730";
        case PciSubDevice10026837::SUBDEVICE_17873000: return "Radeon HD 6570";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026837_H
