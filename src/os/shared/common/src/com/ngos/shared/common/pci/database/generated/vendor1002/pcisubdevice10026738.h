// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026738_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026738_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026738: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16823103 = 0x16823103,
    SUBDEVICE_1787201A = 0x1787201A,
    SUBDEVICE_1787201B = 0x1787201B
};



inline const char8* enumToString(PciSubDevice10026738 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026738::NONE:               return "NONE";
        case PciSubDevice10026738::SUBDEVICE_16823103: return "SUBDEVICE_16823103";
        case PciSubDevice10026738::SUBDEVICE_1787201A: return "SUBDEVICE_1787201A";
        case PciSubDevice10026738::SUBDEVICE_1787201B: return "SUBDEVICE_1787201B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026738 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026738 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026738::SUBDEVICE_16823103: return "Radeon HD 8670";
        case PciSubDevice10026738::SUBDEVICE_1787201A: return "Barts XT [Radeon HD 6870 X2]";
        case PciSubDevice10026738::SUBDEVICE_1787201B: return "Barts XT [Radeon HD 6870 X2]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026738_H
