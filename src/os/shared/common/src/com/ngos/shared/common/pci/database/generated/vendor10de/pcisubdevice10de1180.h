// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1180_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1180_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1180: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104383F1 = 0x104383F1,
    SUBDEVICE_38423682 = 0x38423682
};



inline const char8* enumToString(PciSubDevice10DE1180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1180::NONE:               return "NONE";
        case PciSubDevice10DE1180::SUBDEVICE_104383F1: return "SUBDEVICE_104383F1";
        case PciSubDevice10DE1180::SUBDEVICE_38423682: return "SUBDEVICE_38423682";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1180 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1180::SUBDEVICE_104383F1: return "GTX680-DC2-2GD5";
        case PciSubDevice10DE1180::SUBDEVICE_38423682: return "GeForce GTX 680 Mac Edition";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1180_H
