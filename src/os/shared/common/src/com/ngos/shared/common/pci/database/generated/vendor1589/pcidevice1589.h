// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1589_PCIDEVICE1589_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1589_PCIDEVICE1589_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1589: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009
};



inline const char8* enumToString(PciDevice1589 device1589) // TEST: NO
{
    // COMMON_LT((" | device1589 = %u", device1589)); // Commented to avoid bad looking logs



    switch (device1589)
    {
        case PciDevice1589::NONE:        return "NONE";
        case PciDevice1589::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1589::DEVICE_0009: return "DEVICE_0009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1589 device1589) // TEST: NO
{
    // COMMON_LT((" | device1589 = %u", device1589)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1589, enumToString(device1589));

    return res;
}



inline const char8* enumToHumanString(PciDevice1589 device1589) // TEST: NO
{
    // COMMON_LT((" | device1589 = %u", device1589)); // Commented to avoid bad looking logs



    switch (device1589)
    {
        case PciDevice1589::DEVICE_0008: return "Leutron Vision PicPortExpress CL";
        case PciDevice1589::DEVICE_0009: return "Leutron Vision PicPortExpress CL Stereo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1589_PCIDEVICE1589_H
