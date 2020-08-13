// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14AF_PCIDEVICE14AF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14AF_PCIDEVICE14AF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14AF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7102 = 0x7102
};



inline const char8* enumToString(PciDevice14AF device14AF) // TEST: NO
{
    // COMMON_LT((" | device14AF = %u", device14AF)); // Commented to avoid bad looking logs



    switch (device14AF)
    {
        case PciDevice14AF::NONE:        return "NONE";
        case PciDevice14AF::DEVICE_7102: return "DEVICE_7102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14AF device14AF) // TEST: NO
{
    // COMMON_LT((" | device14AF = %u", device14AF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14AF, enumToString(device14AF));

    return res;
}



inline const char8* enumToHumanString(PciDevice14AF device14AF) // TEST: NO
{
    // COMMON_LT((" | device14AF = %u", device14AF)); // Commented to avoid bad looking logs



    switch (device14AF)
    {
        case PciDevice14AF::DEVICE_7102: return "3D Prophet II MX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14AF_PCIDEVICE14AF_H
