// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D82_PCIDEVICE1D82_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D82_PCIDEVICE1D82_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D82: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0202 = 0x0202
};



inline const char8* enumToString(PciDevice1D82 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D82::NONE:        return "NONE";
        case PciDevice1D82::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1D82::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1D82::DEVICE_0202: return "DEVICE_0202";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D82 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D82 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D82::DEVICE_0101: return "Codensity D400 SSD";
        case PciDevice1D82::DEVICE_0102: return "Codensity D408 PCIe Gen4 NVMe SSD";
        case PciDevice1D82::DEVICE_0202: return "Codensity T408 Video Encoding-Decoding Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D82_PCIDEVICE1D82_H
