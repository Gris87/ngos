// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16C3_PCIDEVICE16C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16C3_PCIDEVICE16C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16C3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_ABCD = 0xABCD,
    DEVICE_ABCE = 0xABCE,
    DEVICE_ABCF = 0xABCF,
    DEVICE_EDDA = 0xEDDA
};



inline const char8* enumToString(PciDevice16C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16C3::NONE:        return "NONE";
        case PciDevice16C3::DEVICE_ABCD: return "DEVICE_ABCD";
        case PciDevice16C3::DEVICE_ABCE: return "DEVICE_ABCE";
        case PciDevice16C3::DEVICE_ABCF: return "DEVICE_ABCF";
        case PciDevice16C3::DEVICE_EDDA: return "DEVICE_EDDA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16C3::DEVICE_ABCD: return "DWC_usb3 / PCIe bridge";
        case PciDevice16C3::DEVICE_ABCE: return "DWC_usb3";
        case PciDevice16C3::DEVICE_ABCF: return "DWC_usb31";
        case PciDevice16C3::DEVICE_EDDA: return "EPMockUp";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16C3_PCIDEVICE16C3_H
