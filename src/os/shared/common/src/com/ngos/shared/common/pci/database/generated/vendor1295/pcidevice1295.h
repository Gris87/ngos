// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1295_PCIDEVICE1295_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1295_PCIDEVICE1295_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1295: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0800 = 0x0800,
    DEVICE_1000 = 0x1000
};



inline const char8* enumToString(PciDevice1295 device1295) // TEST: NO
{
    // COMMON_LT((" | device1295 = %u", device1295)); // Commented to avoid bad looking logs



    switch (device1295)
    {
        case PciDevice1295::NONE:        return "NONE";
        case PciDevice1295::DEVICE_0800: return "DEVICE_0800";
        case PciDevice1295::DEVICE_1000: return "DEVICE_1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1295 device1295) // TEST: NO
{
    // COMMON_LT((" | device1295 = %u", device1295)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1295, enumToString(device1295));

    return res;
}



inline const char8* enumToHumanString(PciDevice1295 device1295) // TEST: NO
{
    // COMMON_LT((" | device1295 = %u", device1295)); // Commented to avoid bad looking logs



    switch (device1295)
    {
        case PciDevice1295::DEVICE_0800: return "PXR800";
        case PciDevice1295::DEVICE_1000: return "PXD1000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1295_PCIDEVICE1295_H
