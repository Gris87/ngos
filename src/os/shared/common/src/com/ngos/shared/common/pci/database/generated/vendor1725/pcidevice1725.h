// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1725_PCIDEVICE1725_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1725_PCIDEVICE1725_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1725: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7174 = 0x7174
};



inline const char8* enumToString(PciDevice1725 device1725) // TEST: NO
{
    // COMMON_LT((" | device1725 = %u", device1725)); // Commented to avoid bad looking logs



    switch (device1725)
    {
        case PciDevice1725::NONE:        return "NONE";
        case PciDevice1725::DEVICE_7174: return "DEVICE_7174";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1725 device1725) // TEST: NO
{
    // COMMON_LT((" | device1725 = %u", device1725)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1725, enumToString(device1725));

    return res;
}



inline const char8* enumToHumanString(PciDevice1725 device1725) // TEST: NO
{
    // COMMON_LT((" | device1725 = %u", device1725)); // Commented to avoid bad looking logs



    switch (device1725)
    {
        case PciDevice1725::DEVICE_7174: return "VSC7174 PCI/PCI-X Serial ATA Host Bus Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1725_PCIDEVICE1725_H
