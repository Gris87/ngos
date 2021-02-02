// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D87_PCIDEVICE1D87_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D87_PCIDEVICE1D87_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D87: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_1808 = 0x1808
};



inline const char8* enumToString(PciDevice1D87 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D87::NONE:        return "NONE";
        case PciDevice1D87::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1D87::DEVICE_1808: return "DEVICE_1808";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D87 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D87 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D87::DEVICE_0100: return "RK3399 PCI Express Root Port";
        case PciDevice1D87::DEVICE_1808: return "RK1808 Neural Network Processor Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D87_PCIDEVICE1D87_H
