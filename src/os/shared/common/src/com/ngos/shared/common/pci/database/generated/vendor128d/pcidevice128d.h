// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR128D_PCIDEVICE128D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR128D_PCIDEVICE128D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice128D: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0021 = 0x0021
};



inline const char8* enumToString(PciDevice128D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice128D::NONE:        return "NONE";
        case PciDevice128D::DEVICE_0021: return "DEVICE_0021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice128D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice128D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice128D::DEVICE_0021: return "ATM155 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR128D_PCIDEVICE128D_H
