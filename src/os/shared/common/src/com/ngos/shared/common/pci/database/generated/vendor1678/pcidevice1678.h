// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1678_PCIDEVICE1678_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1678_PCIDEVICE1678_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1678: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1678 device1678) // TEST: NO
{
    // COMMON_LT((" | device1678 = %u", device1678)); // Commented to avoid bad looking logs



    switch (device1678)
    {
        case PciDevice1678::NONE:        return "NONE";
        case PciDevice1678::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1678 device1678) // TEST: NO
{
    // COMMON_LT((" | device1678 = %u", device1678)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1678, enumToString(device1678));

    return res;
}



inline const char8* enumToHumanString(PciDevice1678 device1678) // TEST: NO
{
    // COMMON_LT((" | device1678 = %u", device1678)); // Commented to avoid bad looking logs



    switch (device1678)
    {
        case PciDevice1678::DEVICE_0100: return "NE020 10Gb Accelerated Ethernet Adapter (iWARP RNIC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1678_PCIDEVICE1678_H
