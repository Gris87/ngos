// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1389_PCIDEVICE1389_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1389_PCIDEVICE1389_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1389: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1389 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1389::NONE:        return "NONE";
        case PciDevice1389::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1389 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1389 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1389::DEVICE_0001: return "PCI1500PFB [Intelligent fieldbus adaptor]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1389_PCIDEVICE1389_H
