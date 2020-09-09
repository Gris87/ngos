// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR186C_PCIDEVICE186C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR186C_PCIDEVICE186C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice186C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0612 = 0x0612,
    DEVICE_0614 = 0x0614,
    DEVICE_0622 = 0x0622,
    DEVICE_0624 = 0x0624,
    DEVICE_0625 = 0x0625,
    DEVICE_0634 = 0x0634,
    DEVICE_0644 = 0x0644
};



inline const char8* enumToString(PciDevice186C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice186C::NONE:        return "NONE";
        case PciDevice186C::DEVICE_0612: return "DEVICE_0612";
        case PciDevice186C::DEVICE_0614: return "DEVICE_0614";
        case PciDevice186C::DEVICE_0622: return "DEVICE_0622";
        case PciDevice186C::DEVICE_0624: return "DEVICE_0624";
        case PciDevice186C::DEVICE_0625: return "DEVICE_0625";
        case PciDevice186C::DEVICE_0634: return "DEVICE_0634";
        case PciDevice186C::DEVICE_0644: return "DEVICE_0644";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice186C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice186C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice186C::DEVICE_0612: return "AD612 Data Acquisition Device";
        case PciDevice186C::DEVICE_0614: return "MF614 Multifunction I/O Card";
        case PciDevice186C::DEVICE_0622: return "AD622 Data Acquisition Device";
        case PciDevice186C::DEVICE_0624: return "MF624 Multifunction I/O PCI Card";
        case PciDevice186C::DEVICE_0625: return "MF625 3-phase Motor Driver";
        case PciDevice186C::DEVICE_0634: return "MF634 Multifunction I/O PCIe Card";
        case PciDevice186C::DEVICE_0644: return "MF644 Multifunction I/O Thb Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR186C_PCIDEVICE186C_H
