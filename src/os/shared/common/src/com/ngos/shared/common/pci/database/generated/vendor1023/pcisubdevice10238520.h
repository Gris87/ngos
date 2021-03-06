// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10238520_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10238520_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10238520: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B16E = 0x0E11B16E,
    SUBDEVICE_10238520 = 0x10238520
};



inline const char8* enumToString(PciSubDevice10238520 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10238520::NONE:               return "NONE";
        case PciSubDevice10238520::SUBDEVICE_0E11B16E: return "SUBDEVICE_0E11B16E";
        case PciSubDevice10238520::SUBDEVICE_10238520: return "SUBDEVICE_10238520";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10238520 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10238520 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10238520::SUBDEVICE_0E11B16E: return "CyberBlade i1 AGP";
        case PciSubDevice10238520::SUBDEVICE_10238520: return "CyberBlade i1 AGP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10238520_H
