// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7401_PCIDEVICE7401_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7401_PCIDEVICE7401_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice7401: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E100 = 0xE100
};



inline const char8* enumToString(PciDevice7401 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice7401::NONE:        return "NONE";
        case PciDevice7401::DEVICE_E100: return "DEVICE_E100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice7401 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice7401 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice7401::DEVICE_E100: return "PTP3100 PCIe PTP Slave Clock";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7401_PCIDEVICE7401_H
