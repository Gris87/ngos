// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1353_PCIDEVICE1353_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1353_PCIDEVICE1353_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1353: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007
};



inline const char8* enumToString(PciDevice1353 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1353::NONE:        return "NONE";
        case PciDevice1353::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1353::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1353::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1353::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1353::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1353::DEVICE_0007: return "DEVICE_0007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1353 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1353 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1353::DEVICE_0002: return "Proserver";
        case PciDevice1353::DEVICE_0003: return "PCI-FUT";
        case PciDevice1353::DEVICE_0004: return "PCI-S0";
        case PciDevice1353::DEVICE_0005: return "PCI-FUT-S0";
        case PciDevice1353::DEVICE_0006: return "OTDU-1U (FPGA Zynq-7000)";
        case PciDevice1353::DEVICE_0007: return "OTDU-EX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1353_PCIDEVICE1353_H
