// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCIDEVICE1319_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCIDEVICE1319_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1319: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0801 = 0x0801,
    DEVICE_0802 = 0x0802,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001
};



inline const char8* enumToString(PciDevice1319 device1319) // TEST: NO
{
    // COMMON_LT((" | device1319 = %u", device1319)); // Commented to avoid bad looking logs



    switch (device1319)
    {
        case PciDevice1319::NONE:        return "NONE";
        case PciDevice1319::DEVICE_0801: return "DEVICE_0801";
        case PciDevice1319::DEVICE_0802: return "DEVICE_0802";
        case PciDevice1319::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1319::DEVICE_1001: return "DEVICE_1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1319 device1319) // TEST: NO
{
    // COMMON_LT((" | device1319 = %u", device1319)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1319, enumToString(device1319));

    return res;
}



inline const char8* enumToHumanString(PciDevice1319 device1319) // TEST: NO
{
    // COMMON_LT((" | device1319 = %u", device1319)); // Commented to avoid bad looking logs



    switch (device1319)
    {
        case PciDevice1319::DEVICE_0801: return "Xwave QS3000A [FM801]";
        case PciDevice1319::DEVICE_0802: return "Xwave QS3000A [FM801 game port]";
        case PciDevice1319::DEVICE_1000: return "FM801 PCI Audio";
        case PciDevice1319::DEVICE_1001: return "FM801 PCI Joystick";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCIDEVICE1319_H
