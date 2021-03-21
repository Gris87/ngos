// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4150_PCIDEVICE4150_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4150_PCIDEVICE4150_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4150: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007
};



inline const char8* enumToString(PciDevice4150 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4150::NONE:        return "NONE";
        case PciDevice4150::DEVICE_0001: return "DEVICE_0001";
        case PciDevice4150::DEVICE_0006: return "DEVICE_0006";
        case PciDevice4150::DEVICE_0007: return "DEVICE_0007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4150 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4150 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4150::DEVICE_0001: return "PCI32TLITE FILSTRUP1 PCI to VME Bridge Controller";
        case PciDevice4150::DEVICE_0006: return "PCI32TLITE UART 16550 Opencores";
        case PciDevice4150::DEVICE_0007: return "PCI32TLITE CAN Controller Opencores";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4150_PCIDEVICE4150_H
