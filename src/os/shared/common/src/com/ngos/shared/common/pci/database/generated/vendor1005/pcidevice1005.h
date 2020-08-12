// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1005_PCIDEVICE1005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1005_PCIDEVICE1005_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1005: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2064 = 0x2064,
    DEVICE_2128 = 0x2128,
    DEVICE_2301 = 0x2301,
    DEVICE_2302 = 0x2302,
    DEVICE_2364 = 0x2364,
    DEVICE_2464 = 0x2464,
    DEVICE_2501 = 0x2501
};



inline const char8* enumToString(PciDevice1005 device1005) // TEST: NO
{
    // COMMON_LT((" | device1005 = %u", device1005)); // Commented to avoid bad looking logs



    switch (device1005)
    {
        case PciDevice1005::NONE:        return "NONE";
        case PciDevice1005::DEVICE_2064: return "DEVICE_2064";
        case PciDevice1005::DEVICE_2128: return "DEVICE_2128";
        case PciDevice1005::DEVICE_2301: return "DEVICE_2301";
        case PciDevice1005::DEVICE_2302: return "DEVICE_2302";
        case PciDevice1005::DEVICE_2364: return "DEVICE_2364";
        case PciDevice1005::DEVICE_2464: return "DEVICE_2464";
        case PciDevice1005::DEVICE_2501: return "DEVICE_2501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1005 device1005) // TEST: NO
{
    // COMMON_LT((" | device1005 = %u", device1005)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1005, enumToString(device1005));

    return res;
}



inline const char8* enumToHumanString(PciDevice1005 device1005) // TEST: NO
{
    // COMMON_LT((" | device1005 = %u", device1005)); // Commented to avoid bad looking logs



    switch (device1005)
    {
        case PciDevice1005::DEVICE_2064: return "ALG2032/2064";
        case PciDevice1005::DEVICE_2128: return "ALG2364A";
        case PciDevice1005::DEVICE_2301: return "ALG2301";
        case PciDevice1005::DEVICE_2302: return "ALG2302";
        case PciDevice1005::DEVICE_2364: return "ALG2364";
        case PciDevice1005::DEVICE_2464: return "ALG2364A";
        case PciDevice1005::DEVICE_2501: return "ALG2564A/25128A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1005_PCIDEVICE1005_H
