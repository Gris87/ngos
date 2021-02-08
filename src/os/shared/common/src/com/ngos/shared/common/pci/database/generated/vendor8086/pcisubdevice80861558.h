// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861558_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861558_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861558: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086011A = 0x8086011A,
    SUBDEVICE_8086011B = 0x8086011B
};



inline const char8* enumToString(PciSubDevice80861558 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861558::NONE:               return "NONE";
        case PciSubDevice80861558::SUBDEVICE_8086011A: return "SUBDEVICE_8086011A";
        case PciSubDevice80861558::SUBDEVICE_8086011B: return "SUBDEVICE_8086011B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861558 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861558 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861558::SUBDEVICE_8086011A: return "Ethernet Converged Network Adapter X520-Q1";
        case PciSubDevice80861558::SUBDEVICE_8086011B: return "Ethernet Converged Network Adapter X520-Q1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861558_H
