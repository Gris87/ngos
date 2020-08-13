// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR199D_PCIDEVICE199D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR199D_PCIDEVICE199D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice199D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8209 = 0x8209,
    DEVICE_890A = 0x890A
};



inline const char8* enumToString(PciDevice199D device199D) // TEST: NO
{
    // COMMON_LT((" | device199D = %u", device199D)); // Commented to avoid bad looking logs



    switch (device199D)
    {
        case PciDevice199D::NONE:        return "NONE";
        case PciDevice199D::DEVICE_8209: return "DEVICE_8209";
        case PciDevice199D::DEVICE_890A: return "DEVICE_890A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice199D device199D) // TEST: NO
{
    // COMMON_LT((" | device199D = %u", device199D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device199D, enumToString(device199D));

    return res;
}



inline const char8* enumToHumanString(PciDevice199D device199D) // TEST: NO
{
    // COMMON_LT((" | device199D = %u", device199D)); // Commented to avoid bad looking logs



    switch (device199D)
    {
        case PciDevice199D::DEVICE_8209: return "Virtual NIC Device";
        case PciDevice199D::DEVICE_890A: return "Virtual HBA Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR199D_PCIDEVICE199D_H
