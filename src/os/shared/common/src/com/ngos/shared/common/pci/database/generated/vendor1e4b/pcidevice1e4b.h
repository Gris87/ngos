// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4B_PCIDEVICE1E4B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4B_PCIDEVICE1E4B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E4B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1201 = 0x1201,
    DEVICE_1202 = 0x1202,
    DEVICE_1601 = 0x1601
};



inline const char8* enumToString(PciDevice1E4B device1E4B) // TEST: NO
{
    // COMMON_LT((" | device1E4B = %u", device1E4B)); // Commented to avoid bad looking logs



    switch (device1E4B)
    {
        case PciDevice1E4B::NONE:        return "NONE";
        case PciDevice1E4B::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1E4B::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1E4B::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1E4B::DEVICE_1201: return "DEVICE_1201";
        case PciDevice1E4B::DEVICE_1202: return "DEVICE_1202";
        case PciDevice1E4B::DEVICE_1601: return "DEVICE_1601";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E4B device1E4B) // TEST: NO
{
    // COMMON_LT((" | device1E4B = %u", device1E4B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1E4B, enumToString(device1E4B));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E4B device1E4B) // TEST: NO
{
    // COMMON_LT((" | device1E4B = %u", device1E4B)); // Commented to avoid bad looking logs



    switch (device1E4B)
    {
        case PciDevice1E4B::DEVICE_1001: return "NVMe SSD Controller MAP1001";
        case PciDevice1E4B::DEVICE_1002: return "NVMe SSD Controller MAP1002";
        case PciDevice1E4B::DEVICE_1003: return "NVMe SSD Controller MAP1003";
        case PciDevice1E4B::DEVICE_1201: return "NVMe SSD Controller MAP1201";
        case PciDevice1E4B::DEVICE_1202: return "NVMe SSD Controller MAP1202";
        case PciDevice1E4B::DEVICE_1601: return "NVMe SSD Controller MAP1601";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4B_PCIDEVICE1E4B_H
