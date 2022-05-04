// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EB4_PCIDEVICE1EB4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EB4_PCIDEVICE1EB4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EB4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3401 = 0x3401
};



inline const char8* enumToString(PciDevice1EB4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EB4::NONE:        return "NONE";
        case PciDevice1EB4::DEVICE_3401: return "DEVICE_3401";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EB4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EB4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EB4::DEVICE_3401: return "SSD Contoller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EB4_PCIDEVICE1EB4_H
