// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2000_PCIDEVICE2000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2000_PCIDEVICE2000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2000: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2800 = 0x2800
};



inline const char8* enumToString(PciDevice2000 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2000::NONE:        return "NONE";
        case PciDevice2000::DEVICE_2800: return "DEVICE_2800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice2000 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice2000 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2000::DEVICE_2800: return "SmartPCI2800 V.92 PCI Soft DFT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2000_PCIDEVICE2000_H
