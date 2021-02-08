// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A2B_PCIDEVICE1A2B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A2B_PCIDEVICE1A2B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A2B: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0005 = 0x0005,
    DEVICE_000A = 0x000A,
    DEVICE_000E = 0x000E
};



inline const char8* enumToString(PciDevice1A2B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A2B::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1A2B::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1A2B::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1A2B::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1A2B::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1A2B::DEVICE_000E: return "DEVICE_000E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A2B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A2B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A2B::DEVICE_0000: return "GESP v1.2";
        case PciDevice1A2B::DEVICE_0001: return "GESP v1.3";
        case PciDevice1A2B::DEVICE_0002: return "ECOMP v1.3";
        case PciDevice1A2B::DEVICE_0005: return "ETP v1.4";
        case PciDevice1A2B::DEVICE_000A: return "ETP-104 v1.1";
        case PciDevice1A2B::DEVICE_000E: return "DSLP-104 v1.1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A2B_PCIDEVICE1A2B_H
