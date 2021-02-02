// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182D_PCIDEVICE182D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182D_PCIDEVICE182D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice182D: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3069 = 0x3069,
    DEVICE_9790 = 0x9790
};



inline const char8* enumToString(PciDevice182D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice182D::NONE:        return "NONE";
        case PciDevice182D::DEVICE_3069: return "DEVICE_3069";
        case PciDevice182D::DEVICE_9790: return "DEVICE_9790";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice182D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice182D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice182D::DEVICE_3069: return "ISDN PCI DC-105V2";
        case PciDevice182D::DEVICE_9790: return "WL-121 Wireless Network Adapter 100g+ [Ver.3]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182D_PCIDEVICE182D_H
