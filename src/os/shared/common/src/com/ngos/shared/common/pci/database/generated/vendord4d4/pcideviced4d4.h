// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD4D4_PCIDEVICED4D4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD4D4_PCIDEVICED4D4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceD4D4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0601 = 0x0601
};



inline const char8* enumToString(PciDeviceD4D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceD4D4::NONE:        return "NONE";
        case PciDeviceD4D4::DEVICE_0601: return "DEVICE_0601";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceD4D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceD4D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceD4D4::DEVICE_0601: return "PCI Mezzanine Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD4D4_PCIDEVICED4D4_H
