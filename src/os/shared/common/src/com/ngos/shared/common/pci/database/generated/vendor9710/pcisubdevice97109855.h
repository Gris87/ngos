// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109855_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109855_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice97109855: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000014 = 0x10000014,
    SUBDEVICE_10000022 = 0x10000022
};



inline const char8* enumToString(PciSubDevice97109855 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice97109855::NONE:               return "NONE";
        case PciSubDevice97109855::SUBDEVICE_10000014: return "SUBDEVICE_10000014";
        case PciSubDevice97109855::SUBDEVICE_10000022: return "SUBDEVICE_10000022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice97109855 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice97109855 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice97109855::SUBDEVICE_10000014: return "1P4S";
        case PciSubDevice97109855::SUBDEVICE_10000022: return "2P2S (2 Parallel / 2 16550A Serial Port Adapter)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109855_H
