// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D26_PCIDEVICE1D26_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D26_PCIDEVICE1D26_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D26: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0040 = 0x0040,
    DEVICE_0080 = 0x0080,
    DEVICE_00C0 = 0x00C0,
    DEVICE_0140 = 0x0140,
    DEVICE_E004 = 0xE004
};



inline const char8* enumToString(PciDevice1D26 device1D26) // TEST: NO
{
    // COMMON_LT((" | device1D26 = %u", device1D26)); // Commented to avoid bad looking logs



    switch (device1D26)
    {
        case PciDevice1D26::NONE:        return "NONE";
        case PciDevice1D26::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1D26::DEVICE_0080: return "DEVICE_0080";
        case PciDevice1D26::DEVICE_00C0: return "DEVICE_00C0";
        case PciDevice1D26::DEVICE_0140: return "DEVICE_0140";
        case PciDevice1D26::DEVICE_E004: return "DEVICE_E004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D26 device1D26) // TEST: NO
{
    // COMMON_LT((" | device1D26 = %u", device1D26)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D26, enumToString(device1D26));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D26 device1D26) // TEST: NO
{
    // COMMON_LT((" | device1D26 = %u", device1D26)); // Commented to avoid bad looking logs



    switch (device1D26)
    {
        case PciDevice1D26::DEVICE_0040: return "Turbocard2 Accelerator";
        case PciDevice1D26::DEVICE_0080: return "Open Network Interface Card 80G";
        case PciDevice1D26::DEVICE_00C0: return "Turbocard3 Accelerator";
        case PciDevice1D26::DEVICE_0140: return "Open Network Interface Card 40G";
        case PciDevice1D26::DEVICE_E004: return "AB01/EMB01 Development Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D26_PCIDEVICE1D26_H
