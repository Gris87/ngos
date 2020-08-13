// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCIDEVICE1CC4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCIDEVICE1CC4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CC4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_17AB = 0x17AB
};



inline const char8* enumToString(PciDevice1CC4 device1CC4) // TEST: NO
{
    // COMMON_LT((" | device1CC4 = %u", device1CC4)); // Commented to avoid bad looking logs



    switch (device1CC4)
    {
        case PciDevice1CC4::NONE:        return "NONE";
        case PciDevice1CC4::DEVICE_17AB: return "DEVICE_17AB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CC4 device1CC4) // TEST: NO
{
    // COMMON_LT((" | device1CC4 = %u", device1CC4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CC4, enumToString(device1CC4));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CC4 device1CC4) // TEST: NO
{
    // COMMON_LT((" | device1CC4 = %u", device1CC4)); // Commented to avoid bad looking logs



    switch (device1CC4)
    {
        case PciDevice1CC4::DEVICE_17AB: return "NVMe 256G SSD device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCIDEVICE1CC4_H
