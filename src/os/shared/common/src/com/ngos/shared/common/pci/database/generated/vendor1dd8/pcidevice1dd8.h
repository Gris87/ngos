// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCIDEVICE1DD8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCIDEVICE1DD8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DD8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1007 = 0x1007
};



inline const char8* enumToString(PciDevice1DD8 device1DD8) // TEST: NO
{
    // COMMON_LT((" | device1DD8 = %u", device1DD8)); // Commented to avoid bad looking logs



    switch (device1DD8)
    {
        case PciDevice1DD8::NONE:        return "NONE";
        case PciDevice1DD8::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1DD8::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1DD8::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1DD8::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1DD8::DEVICE_1004: return "DEVICE_1004";
        case PciDevice1DD8::DEVICE_1007: return "DEVICE_1007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DD8 device1DD8) // TEST: NO
{
    // COMMON_LT((" | device1DD8 = %u", device1DD8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1DD8, enumToString(device1DD8));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DD8 device1DD8) // TEST: NO
{
    // COMMON_LT((" | device1DD8 = %u", device1DD8)); // Commented to avoid bad looking logs



    switch (device1DD8)
    {
        case PciDevice1DD8::DEVICE_1000: return "DSC Capri Upstream Port";
        case PciDevice1DD8::DEVICE_1001: return "DSC Virtual Downstream Port";
        case PciDevice1DD8::DEVICE_1002: return "DSC Ethernet Controller";
        case PciDevice1DD8::DEVICE_1003: return "DSC Ethernet Controller VF";
        case PciDevice1DD8::DEVICE_1004: return "DSC Management Controller";
        case PciDevice1DD8::DEVICE_1007: return "DSC Storage Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCIDEVICE1DD8_H
