// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086158A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086158A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086158A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15900000 = 0x15900000,
    SUBDEVICE_15900286 = 0x15900286,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_8086000A = 0x8086000A
};



inline const char8* enumToString(PciSubDevice8086158A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086158A::NONE:               return "NONE";
        case PciSubDevice8086158A::SUBDEVICE_15900000: return "SUBDEVICE_15900000";
        case PciSubDevice8086158A::SUBDEVICE_15900286: return "SUBDEVICE_15900286";
        case PciSubDevice8086158A::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice8086158A::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086158A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086158A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086158A::SUBDEVICE_15900000: return "10/25Gb Ethernet Adapter";
        case PciSubDevice8086158A::SUBDEVICE_15900286: return "Synergy 4610C 10/25Gb Ethernet Adapter";
        case PciSubDevice8086158A::SUBDEVICE_80860000: return "Ethernet Controller XXV710 for 25GbE backplane";
        case PciSubDevice8086158A::SUBDEVICE_8086000A: return "Ethernet 25G 2P XXV710 Mezz";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086158A_H
