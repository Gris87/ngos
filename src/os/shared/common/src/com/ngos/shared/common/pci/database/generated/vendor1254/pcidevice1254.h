// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1254_PCIDEVICE1254_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1254_PCIDEVICE1254_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1254: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0065 = 0x0065,
    DEVICE_007C = 0x007C
};



inline const char8* enumToString(PciDevice1254 device1254) // TEST: NO
{
    // COMMON_LT((" | device1254 = %u", device1254)); // Commented to avoid bad looking logs



    switch (device1254)
    {
        case PciDevice1254::NONE:        return "NONE";
        case PciDevice1254::DEVICE_0065: return "DEVICE_0065";
        case PciDevice1254::DEVICE_007C: return "DEVICE_007C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1254 device1254) // TEST: NO
{
    // COMMON_LT((" | device1254 = %u", device1254)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1254, enumToString(device1254));

    return res;
}



inline const char8* enumToHumanString(PciDevice1254 device1254) // TEST: NO
{
    // COMMON_LT((" | device1254 = %u", device1254)); // Commented to avoid bad looking logs



    switch (device1254)
    {
        case PciDevice1254::DEVICE_0065: return "DVB Master FD";
        case PciDevice1254::DEVICE_007C: return "DVB Master Quad/o";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1254_PCIDEVICE1254_H
