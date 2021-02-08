// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B91533_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B91533_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B91533: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014053B = 0x1014053B,
    SUBDEVICE_10B91533 = 0x10B91533
};



inline const char8* enumToString(PciSubDevice10B91533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B91533::NONE:               return "NONE";
        case PciSubDevice10B91533::SUBDEVICE_1014053B: return "SUBDEVICE_1014053B";
        case PciSubDevice10B91533::SUBDEVICE_10B91533: return "SUBDEVICE_10B91533";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B91533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B91533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B91533::SUBDEVICE_1014053B: return "ThinkPad R40e";
        case PciSubDevice10B91533::SUBDEVICE_10B91533: return "ALi M1533 Aladdin IV/V ISA Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B91533_H
