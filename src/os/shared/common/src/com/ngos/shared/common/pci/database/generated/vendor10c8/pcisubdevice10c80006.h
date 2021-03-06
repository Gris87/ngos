// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C80006_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C80006_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10C80006: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140152 = 0x10140152
};



inline const char8* enumToString(PciSubDevice10C80006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10C80006::NONE:               return "NONE";
        case PciSubDevice10C80006::SUBDEVICE_10140152: return "SUBDEVICE_10140152";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10C80006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10C80006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10C80006::SUBDEVICE_10140152: return "ThinkPad 600X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C80006_H
