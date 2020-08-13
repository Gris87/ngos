// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCIDEVICE1522_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCIDEVICE1522_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1522: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_4000 = 0x4000
};



inline const char8* enumToString(PciDevice1522 device1522) // TEST: NO
{
    // COMMON_LT((" | device1522 = %u", device1522)); // Commented to avoid bad looking logs



    switch (device1522)
    {
        case PciDevice1522::NONE:        return "NONE";
        case PciDevice1522::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1522::DEVICE_4000: return "DEVICE_4000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1522 device1522) // TEST: NO
{
    // COMMON_LT((" | device1522 = %u", device1522)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1522, enumToString(device1522));

    return res;
}



inline const char8* enumToHumanString(PciDevice1522 device1522) // TEST: NO
{
    // COMMON_LT((" | device1522 = %u", device1522)); // Commented to avoid bad looking logs



    switch (device1522)
    {
        case PciDevice1522::DEVICE_0100: return "PCI <-> IOBus Bridge";
        case PciDevice1522::DEVICE_4000: return "PCI Express UART";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCIDEVICE1522_H
