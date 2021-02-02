// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR122E_PCIDEVICE122E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR122E_PCIDEVICE122E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice122E: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7722 = 0x7722,
    DEVICE_7724 = 0x7724,
    DEVICE_7729 = 0x7729
};



inline const char8* enumToString(PciDevice122E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice122E::NONE:        return "NONE";
        case PciDevice122E::DEVICE_7722: return "DEVICE_7722";
        case PciDevice122E::DEVICE_7724: return "DEVICE_7724";
        case PciDevice122E::DEVICE_7729: return "DEVICE_7729";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice122E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice122E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice122E::DEVICE_7722: return "Napatech XL1";
        case PciDevice122E::DEVICE_7724: return "Napatech XL2/XA";
        case PciDevice122E::DEVICE_7729: return "Napatech XD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR122E_PCIDEVICE122E_H
