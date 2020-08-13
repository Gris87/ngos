// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1500_PCIDEVICE1500_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1500_PCIDEVICE1500_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1500: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1360 = 0x1360
};



inline const char8* enumToString(PciDevice1500 device1500) // TEST: NO
{
    // COMMON_LT((" | device1500 = %u", device1500)); // Commented to avoid bad looking logs



    switch (device1500)
    {
        case PciDevice1500::NONE:        return "NONE";
        case PciDevice1500::DEVICE_1360: return "DEVICE_1360";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1500 device1500) // TEST: NO
{
    // COMMON_LT((" | device1500 = %u", device1500)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1500, enumToString(device1500));

    return res;
}



inline const char8* enumToHumanString(PciDevice1500 device1500) // TEST: NO
{
    // COMMON_LT((" | device1500 = %u", device1500)); // Commented to avoid bad looking logs



    switch (device1500)
    {
        case PciDevice1500::DEVICE_1360: return "RTL81xx RealTek Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1500_PCIDEVICE1500_H
