// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026800_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026800_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026800: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020124 = 0x10020124,
    SUBDEVICE_80862110 = 0x80862110,
    SUBDEVICE_80862111 = 0x80862111
};



inline const char8* enumToString(PciSubDevice10026800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026800::NONE:               return "NONE";
        case PciSubDevice10026800::SUBDEVICE_10020124: return "SUBDEVICE_10020124";
        case PciSubDevice10026800::SUBDEVICE_80862110: return "SUBDEVICE_80862110";
        case PciSubDevice10026800::SUBDEVICE_80862111: return "SUBDEVICE_80862111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026800::SUBDEVICE_10020124: return "Radeon HD 7970M";
        case PciSubDevice10026800::SUBDEVICE_80862110: return "Radeon HD 7970M";
        case PciSubDevice10026800::SUBDEVICE_80862111: return "Radeon HD 7970M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026800_H
