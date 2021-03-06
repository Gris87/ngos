// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1017_PCIDEVICE1017_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1017_PCIDEVICE1017_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1017: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5343 = 0x5343
};



inline const char8* enumToString(PciDevice1017 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1017::NONE:        return "NONE";
        case PciDevice1017::DEVICE_5343: return "DEVICE_5343";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1017 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1017 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1017::DEVICE_5343: return "SPEA 3D Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1017_PCIDEVICE1017_H
