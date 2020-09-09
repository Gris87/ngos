// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE0_PCIDEVICE1AE0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE0_PCIDEVICE1AE0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AE0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0042 = 0x0042,
    DEVICE_ABCD = 0xABCD
};



inline const char8* enumToString(PciDevice1AE0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE0::NONE:        return "NONE";
        case PciDevice1AE0::DEVICE_0042: return "DEVICE_0042";
        case PciDevice1AE0::DEVICE_ABCD: return "DEVICE_ABCD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AE0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AE0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE0::DEVICE_0042: return "Compute Engine Virtual Ethernet [gVNIC]";
        case PciDevice1AE0::DEVICE_ABCD: return "Airbrush Combined Paintbox IPU/Oscar Edge TPU [Pixel Neural Core]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE0_PCIDEVICE1AE0_H
