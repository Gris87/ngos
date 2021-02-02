// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119F_PCIDEVICE119F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119F_PCIDEVICE119F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice119F: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1081 = 0x1081,
    DEVICE_1101 = 0x1101,
    DEVICE_1121 = 0x1121
};



inline const char8* enumToString(PciDevice119F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice119F::NONE:        return "NONE";
        case PciDevice119F::DEVICE_1081: return "DEVICE_1081";
        case PciDevice119F::DEVICE_1101: return "DEVICE_1101";
        case PciDevice119F::DEVICE_1121: return "DEVICE_1121";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice119F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice119F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice119F::DEVICE_1081: return "BXI Host Channel Adapter";
        case PciDevice119F::DEVICE_1101: return "BXI Host Channel Adapter v1.2";
        case PciDevice119F::DEVICE_1121: return "BXI Host Channel Adapter v1.3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119F_PCIDEVICE119F_H
