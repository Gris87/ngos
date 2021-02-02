// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREA01_PCIDEVICEEA01_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREA01_PCIDEVICEEA01_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceEA01: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000A = 0x000A,
    DEVICE_0032 = 0x0032,
    DEVICE_003E = 0x003E,
    DEVICE_0041 = 0x0041,
    DEVICE_0043 = 0x0043,
    DEVICE_0046 = 0x0046,
    DEVICE_0052 = 0x0052,
    DEVICE_0800 = 0x0800
};



inline const char8* enumToString(PciDeviceEA01 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceEA01::NONE:        return "NONE";
        case PciDeviceEA01::DEVICE_000A: return "DEVICE_000A";
        case PciDeviceEA01::DEVICE_0032: return "DEVICE_0032";
        case PciDeviceEA01::DEVICE_003E: return "DEVICE_003E";
        case PciDeviceEA01::DEVICE_0041: return "DEVICE_0041";
        case PciDeviceEA01::DEVICE_0043: return "DEVICE_0043";
        case PciDeviceEA01::DEVICE_0046: return "DEVICE_0046";
        case PciDeviceEA01::DEVICE_0052: return "DEVICE_0052";
        case PciDeviceEA01::DEVICE_0800: return "DEVICE_0800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceEA01 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceEA01 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceEA01::DEVICE_000A: return "PCI-773 Temperature Card";
        case PciDeviceEA01::DEVICE_0032: return "PCI-730 & PC104P-30 Card";
        case PciDeviceEA01::DEVICE_003E: return "PCI-762 Opto-Isolator Card";
        case PciDeviceEA01::DEVICE_0041: return "PCI-763 Reed Relay Card";
        case PciDeviceEA01::DEVICE_0043: return "PCI-769 Opto-Isolator Reed Relay Combo Card";
        case PciDeviceEA01::DEVICE_0046: return "PCI-766 Analog Output Card";
        case PciDeviceEA01::DEVICE_0052: return "PCI-703 Analog I/O Card";
        case PciDeviceEA01::DEVICE_0800: return "PCI-800 Digital I/O Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREA01_PCIDEVICEEA01_H
