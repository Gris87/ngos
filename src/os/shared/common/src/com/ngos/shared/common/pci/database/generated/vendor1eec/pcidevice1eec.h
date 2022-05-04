// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EEC_PCIDEVICE1EEC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EEC_PCIDEVICE1EEC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EEC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0102 = 0x0102,
    DEVICE_1EEC = 0x1EEC
};



inline const char8* enumToString(PciDevice1EEC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EEC::NONE:        return "NONE";
        case PciDevice1EEC::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1EEC::DEVICE_1EEC: return "DEVICE_1EEC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EEC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EEC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EEC::DEVICE_0102: return "VSE250231S Dual-port 10Gb/25Gb Ethernet PCIe";
        case PciDevice1EEC::DEVICE_1EEC: return "VSE250231S Dual-port 10Gb/25Gb Ethernet PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EEC_PCIDEVICE1EEC_H
