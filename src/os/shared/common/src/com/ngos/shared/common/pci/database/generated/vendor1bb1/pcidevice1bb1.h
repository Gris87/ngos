// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCIDEVICE1BB1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCIDEVICE1BB1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BB1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_005D = 0x005D,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1BB1 device1BB1) // TEST: NO
{
    // COMMON_LT((" | device1BB1 = %u", device1BB1)); // Commented to avoid bad looking logs



    switch (device1BB1)
    {
        case PciDevice1BB1::NONE:        return "NONE";
        case PciDevice1BB1::DEVICE_005D: return "DEVICE_005D";
        case PciDevice1BB1::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BB1 device1BB1) // TEST: NO
{
    // COMMON_LT((" | device1BB1 = %u", device1BB1)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1BB1, enumToString(device1BB1));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BB1 device1BB1) // TEST: NO
{
    // COMMON_LT((" | device1BB1 = %u", device1BB1)); // Commented to avoid bad looking logs



    switch (device1BB1)
    {
        case PciDevice1BB1::DEVICE_005D: return "Nytro PCIe Flash Storage";
        case PciDevice1BB1::DEVICE_0100: return "Nytro Flash Storage";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCIDEVICE1BB1_H
