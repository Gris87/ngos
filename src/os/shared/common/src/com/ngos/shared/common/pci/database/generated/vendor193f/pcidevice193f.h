// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR193F_PCIDEVICE193F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR193F_PCIDEVICE193F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice193F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0360 = 0x0360,
    DEVICE_0363 = 0x0363,
    DEVICE_0364 = 0x0364,
    DEVICE_0367 = 0x0367,
    DEVICE_0370 = 0x0370,
    DEVICE_0604 = 0x0604,
    DEVICE_0605 = 0x0605,
    DEVICE_3641 = 0x3641,
    DEVICE_3642 = 0x3642,
    DEVICE_6101 = 0x6101,
    DEVICE_6102 = 0x6102
};



inline const char8* enumToString(PciDevice193F device193F) // TEST: NO
{
    // COMMON_LT((" | device193F = %u", device193F)); // Commented to avoid bad looking logs



    switch (device193F)
    {
        case PciDevice193F::NONE:        return "NONE";
        case PciDevice193F::DEVICE_0001: return "DEVICE_0001";
        case PciDevice193F::DEVICE_0360: return "DEVICE_0360";
        case PciDevice193F::DEVICE_0363: return "DEVICE_0363";
        case PciDevice193F::DEVICE_0364: return "DEVICE_0364";
        case PciDevice193F::DEVICE_0367: return "DEVICE_0367";
        case PciDevice193F::DEVICE_0370: return "DEVICE_0370";
        case PciDevice193F::DEVICE_0604: return "DEVICE_0604";
        case PciDevice193F::DEVICE_0605: return "DEVICE_0605";
        case PciDevice193F::DEVICE_3641: return "DEVICE_3641";
        case PciDevice193F::DEVICE_3642: return "DEVICE_3642";
        case PciDevice193F::DEVICE_6101: return "DEVICE_6101";
        case PciDevice193F::DEVICE_6102: return "DEVICE_6102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice193F device193F) // TEST: NO
{
    // COMMON_LT((" | device193F = %u", device193F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device193F, enumToString(device193F));

    return res;
}



inline const char8* enumToHumanString(PciDevice193F device193F) // TEST: NO
{
    // COMMON_LT((" | device193F = %u", device193F)); // Commented to avoid bad looking logs



    switch (device193F)
    {
        case PciDevice193F::DEVICE_0001: return "AHA36x-PCIX";
        case PciDevice193F::DEVICE_0360: return "AHA360-PCIe";
        case PciDevice193F::DEVICE_0363: return "AHA363-PCIe";
        case PciDevice193F::DEVICE_0364: return "AHA364-PCIe";
        case PciDevice193F::DEVICE_0367: return "AHA367-PCIe";
        case PciDevice193F::DEVICE_0370: return "AHA370-PCIe";
        case PciDevice193F::DEVICE_0604: return "AHA604";
        case PciDevice193F::DEVICE_0605: return "AHA605";
        case PciDevice193F::DEVICE_3641: return "AHA3641";
        case PciDevice193F::DEVICE_3642: return "AHA3642";
        case PciDevice193F::DEVICE_6101: return "AHA6101";
        case PciDevice193F::DEVICE_6102: return "AHA6102";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR193F_PCIDEVICE193F_H
