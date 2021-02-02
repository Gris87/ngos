// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808615D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808615D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808615D1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_8086001B = 0x8086001B,
    SUBDEVICE_80860021 = 0x80860021,
    SUBDEVICE_808600A2 = 0x808600A2
};



inline const char8* enumToString(PciSubDevice808615D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808615D1::NONE:               return "NONE";
        case PciSubDevice808615D1::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice808615D1::SUBDEVICE_8086001B: return "SUBDEVICE_8086001B";
        case PciSubDevice808615D1::SUBDEVICE_80860021: return "SUBDEVICE_80860021";
        case PciSubDevice808615D1::SUBDEVICE_808600A2: return "SUBDEVICE_808600A2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808615D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808615D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808615D1::SUBDEVICE_80860002: return "Ethernet Converged Network Adapter X550-T1";
        case PciSubDevice808615D1::SUBDEVICE_8086001B: return "Ethernet Server Adapter X550-T1 for OCP";
        case PciSubDevice808615D1::SUBDEVICE_80860021: return "Ethernet Converged Network Adapter X550-T1";
        case PciSubDevice808615D1::SUBDEVICE_808600A2: return "Ethernet Converged Network Adapter X550-T1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808615D1_H
