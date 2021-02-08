// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR149D_PCIDEVICE149D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR149D_PCIDEVICE149D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice149D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice149D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice149D::NONE:        return "NONE";
        case PciDevice149D::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice149D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice149D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice149D::DEVICE_0001: return "Video Toaster for PC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR149D_PCIDEVICE149D_H
