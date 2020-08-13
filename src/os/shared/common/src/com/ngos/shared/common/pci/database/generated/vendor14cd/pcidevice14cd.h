// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14CD_PCIDEVICE14CD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14CD_PCIDEVICE14CD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14CD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice14CD device14CD) // TEST: NO
{
    // COMMON_LT((" | device14CD = %u", device14CD)); // Commented to avoid bad looking logs



    switch (device14CD)
    {
        case PciDevice14CD::NONE:        return "NONE";
        case PciDevice14CD::DEVICE_0001: return "DEVICE_0001";
        case PciDevice14CD::DEVICE_0002: return "DEVICE_0002";
        case PciDevice14CD::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14CD device14CD) // TEST: NO
{
    // COMMON_LT((" | device14CD = %u", device14CD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14CD, enumToString(device14CD));

    return res;
}



inline const char8* enumToHumanString(PciDevice14CD device14CD) // TEST: NO
{
    // COMMON_LT((" | device14CD = %u", device14CD)); // Commented to avoid bad looking logs



    switch (device14CD)
    {
        case PciDevice14CD::DEVICE_0001: return "USI-1514-1GbaseT [OCP1]";
        case PciDevice14CD::DEVICE_0002: return "USI-4227-SFP [OCP2]";
        case PciDevice14CD::DEVICE_0003: return "USI-X557-10GbaseT [OCP3]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14CD_PCIDEVICE14CD_H
