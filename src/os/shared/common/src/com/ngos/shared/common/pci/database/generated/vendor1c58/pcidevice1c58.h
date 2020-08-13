// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCIDEVICE1C58_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCIDEVICE1C58_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C58: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0023 = 0x0023
};



inline const char8* enumToString(PciDevice1C58 device1C58) // TEST: NO
{
    // COMMON_LT((" | device1C58 = %u", device1C58)); // Commented to avoid bad looking logs



    switch (device1C58)
    {
        case PciDevice1C58::NONE:        return "NONE";
        case PciDevice1C58::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1C58::DEVICE_0023: return "DEVICE_0023";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C58 device1C58) // TEST: NO
{
    // COMMON_LT((" | device1C58 = %u", device1C58)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C58, enumToString(device1C58));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C58 device1C58) // TEST: NO
{
    // COMMON_LT((" | device1C58 = %u", device1C58)); // Commented to avoid bad looking logs



    switch (device1C58)
    {
        case PciDevice1C58::DEVICE_0003: return "Ultrastar SN100 Series NVMe SSD";
        case PciDevice1C58::DEVICE_0023: return "Ultrastar SN200 Series NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCIDEVICE1C58_H
