// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1462_PCIDEVICE1462_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1462_PCIDEVICE1462_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1462: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_AAF0 = 0xAAF0
};



inline const char8* enumToString(PciDevice1462 device1462) // TEST: NO
{
    // COMMON_LT((" | device1462 = %u", device1462)); // Commented to avoid bad looking logs



    switch (device1462)
    {
        case PciDevice1462::NONE:        return "NONE";
        case PciDevice1462::DEVICE_AAF0: return "DEVICE_AAF0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1462 device1462) // TEST: NO
{
    // COMMON_LT((" | device1462 = %u", device1462)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1462, enumToString(device1462));

    return res;
}



inline const char8* enumToHumanString(PciDevice1462 device1462) // TEST: NO
{
    // COMMON_LT((" | device1462 = %u", device1462)); // Commented to avoid bad looking logs



    switch (device1462)
    {
        case PciDevice1462::DEVICE_AAF0: return "Radeon RX 580 Gaming X 8G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1462_PCIDEVICE1462_H
