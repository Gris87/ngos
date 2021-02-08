// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086154A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086154A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086154A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086011A = 0x8086011A,
    SUBDEVICE_8086011B = 0x8086011B,
    SUBDEVICE_8086011C = 0x8086011C
};



inline const char8* enumToString(PciSubDevice8086154A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086154A::NONE:               return "NONE";
        case PciSubDevice8086154A::SUBDEVICE_8086011A: return "SUBDEVICE_8086011A";
        case PciSubDevice8086154A::SUBDEVICE_8086011B: return "SUBDEVICE_8086011B";
        case PciSubDevice8086154A::SUBDEVICE_8086011C: return "SUBDEVICE_8086011C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086154A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086154A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086154A::SUBDEVICE_8086011A: return "Ethernet Converged Network Adapter X520-4";
        case PciSubDevice8086154A::SUBDEVICE_8086011B: return "Ethernet Converged Network Adapter X520-4";
        case PciSubDevice8086154A::SUBDEVICE_8086011C: return "Ethernet Converged Network Adapter X520-4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086154A_H
