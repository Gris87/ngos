// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3A_PCIDEVICE1B3A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3A_PCIDEVICE1B3A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B3A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7589 = 0x7589
};



inline const char8* enumToString(PciDevice1B3A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B3A::NONE:        return "NONE";
        case PciDevice1B3A::DEVICE_7589: return "DEVICE_7589";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B3A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B3A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B3A::DEVICE_7589: return "HRED J2000 - JPEG 2000 Video Codec Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3A_PCIDEVICE1B3A_H
