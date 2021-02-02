// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1947_PCIDEVICE1947_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1947_PCIDEVICE1947_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1947: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4743 = 0x4743
};



inline const char8* enumToString(PciDevice1947 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1947::NONE:        return "NONE";
        case PciDevice1947::DEVICE_4743: return "DEVICE_4743";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1947 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1947 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1947::DEVICE_4743: return "CG200 Dual SD/SDIO Host controller device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1947_PCIDEVICE1947_H
