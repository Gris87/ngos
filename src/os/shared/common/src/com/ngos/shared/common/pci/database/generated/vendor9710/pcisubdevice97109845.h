// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109845_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109845_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice97109845: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000004 = 0x10000004,
    SUBDEVICE_10000006 = 0x10000006,
    SUBDEVICE_10000014 = 0x10000014
};



inline const char8* enumToString(PciSubDevice97109845 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice97109845::NONE:               return "NONE";
        case PciSubDevice97109845::SUBDEVICE_10000004: return "SUBDEVICE_10000004";
        case PciSubDevice97109845::SUBDEVICE_10000006: return "SUBDEVICE_10000006";
        case PciSubDevice97109845::SUBDEVICE_10000014: return "SUBDEVICE_10000014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice97109845 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice97109845 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice97109845::SUBDEVICE_10000004: return "0P4S (4 port 16550A serial card)";
        case PciSubDevice97109845::SUBDEVICE_10000006: return "0P6S (6 port 16550a serial card)";
        case PciSubDevice97109845::SUBDEVICE_10000014: return "1P4S (1 Parallel / 4 16550A Serial Port Adapter)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109845_H
