// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F2_PCIDEVICE14F2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F2_PCIDEVICE14F2_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14F2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0120 = 0x0120,
    DEVICE_0121 = 0x0121,
    DEVICE_0122 = 0x0122,
    DEVICE_0123 = 0x0123,
    DEVICE_0124 = 0x0124
};



inline const char8* enumToString(PciDevice14F2 device14F2) // TEST: NO
{
    // COMMON_LT((" | device14F2 = %u", device14F2)); // Commented to avoid bad looking logs



    switch (device14F2)
    {
        case PciDevice14F2::NONE:        return "NONE";
        case PciDevice14F2::DEVICE_0120: return "DEVICE_0120";
        case PciDevice14F2::DEVICE_0121: return "DEVICE_0121";
        case PciDevice14F2::DEVICE_0122: return "DEVICE_0122";
        case PciDevice14F2::DEVICE_0123: return "DEVICE_0123";
        case PciDevice14F2::DEVICE_0124: return "DEVICE_0124";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14F2 device14F2) // TEST: NO
{
    // COMMON_LT((" | device14F2 = %u", device14F2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14F2, enumToString(device14F2));

    return res;
}



inline const char8* enumToHumanString(PciDevice14F2 device14F2) // TEST: NO
{
    // COMMON_LT((" | device14F2 = %u", device14F2)); // Commented to avoid bad looking logs



    switch (device14F2)
    {
        case PciDevice14F2::DEVICE_0120: return "EV1000 bridge";
        case PciDevice14F2::DEVICE_0121: return "EV1000 Parallel port";
        case PciDevice14F2::DEVICE_0122: return "EV1000 Serial port";
        case PciDevice14F2::DEVICE_0123: return "EV1000 Keyboard controller";
        case PciDevice14F2::DEVICE_0124: return "EV1000 Mouse controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F2_PCIDEVICE14F2_H
