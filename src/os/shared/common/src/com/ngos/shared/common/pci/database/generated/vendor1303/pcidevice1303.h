// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1303_PCIDEVICE1303_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1303_PCIDEVICE1303_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1303: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0030 = 0x0030
};



inline const char8* enumToString(PciDevice1303 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1303::NONE:        return "NONE";
        case PciDevice1303::DEVICE_0030: return "DEVICE_0030";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1303 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1303 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1303::DEVICE_0030: return "X3-SDF 4-channel XMC acquisition board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1303_PCIDEVICE1303_H
