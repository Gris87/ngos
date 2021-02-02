// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1677_PCIDEVICE1677_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1677_PCIDEVICE1677_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1677: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_104E = 0x104E,
    DEVICE_12D7 = 0x12D7,
    DEVICE_20AD = 0x20AD
};



inline const char8* enumToString(PciDevice1677 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1677::NONE:        return "NONE";
        case PciDevice1677::DEVICE_104E: return "DEVICE_104E";
        case PciDevice1677::DEVICE_12D7: return "DEVICE_12D7";
        case PciDevice1677::DEVICE_20AD: return "DEVICE_20AD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1677 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1677 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1677::DEVICE_104E: return "5LS172.6 B&R Dual CAN Interface Card";
        case PciDevice1677::DEVICE_12D7: return "5LS172.61 B&R Dual CAN Interface Card";
        case PciDevice1677::DEVICE_20AD: return "5ACPCI.MFIO-K01 Profibus DP / K-Feldbus / COM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1677_PCIDEVICE1677_H
