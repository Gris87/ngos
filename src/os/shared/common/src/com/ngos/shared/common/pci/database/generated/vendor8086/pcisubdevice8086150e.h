// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086150E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086150E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086150E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1780 = 0x103C1780,
    SUBDEVICE_808612A1 = 0x808612A1,
    SUBDEVICE_808612A2 = 0x808612A2
};



inline const char8* enumToString(PciSubDevice8086150E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086150E::NONE:               return "NONE";
        case PciSubDevice8086150E::SUBDEVICE_103C1780: return "SUBDEVICE_103C1780";
        case PciSubDevice8086150E::SUBDEVICE_808612A1: return "SUBDEVICE_808612A1";
        case PciSubDevice8086150E::SUBDEVICE_808612A2: return "SUBDEVICE_808612A2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086150E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086150E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086150E::SUBDEVICE_103C1780: return "NC365T 4-port Ethernet Server Adapter";
        case PciSubDevice8086150E::SUBDEVICE_808612A1: return "Ethernet Server Adapter I340-T4";
        case PciSubDevice8086150E::SUBDEVICE_808612A2: return "Ethernet Server Adapter I340-T4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086150E_H
