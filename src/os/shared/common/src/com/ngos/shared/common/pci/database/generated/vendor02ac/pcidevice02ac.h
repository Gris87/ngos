// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR02AC_PCIDEVICE02AC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR02AC_PCIDEVICE02AC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice02AC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1012 = 0x1012
};



inline const char8* enumToString(PciDevice02AC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice02AC::NONE:        return "NONE";
        case PciDevice02AC::DEVICE_1012: return "DEVICE_1012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice02AC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice02AC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice02AC::DEVICE_1012: return "1012 PCMCIA 10/100 Ethernet Card [RTL81xx]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR02AC_PCIDEVICE02AC_H
