// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95451_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95451_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B95451: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140506 = 0x10140506,
    SUBDEVICE_1014053E = 0x1014053E,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_103C0025 = 0x103C0025
};



inline const char8* enumToString(PciSubDevice10B95451 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95451::NONE:               return "NONE";
        case PciSubDevice10B95451::SUBDEVICE_10140506: return "SUBDEVICE_10140506";
        case PciSubDevice10B95451::SUBDEVICE_1014053E: return "SUBDEVICE_1014053E";
        case PciSubDevice10B95451::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice10B95451::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B95451 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B95451 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95451::SUBDEVICE_10140506: return "ThinkPad R30";
        case PciSubDevice10B95451::SUBDEVICE_1014053E: return "ThinkPad R40e";
        case PciSubDevice10B95451::SUBDEVICE_103C0024: return "Pavilion ze4400 builtin Audio";
        case PciSubDevice10B95451::SUBDEVICE_103C0025: return "XE4500 Notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95451_H
