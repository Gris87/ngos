// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D9B_PCIDEVICE1D9B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D9B_PCIDEVICE1D9B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D9B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011
};



inline const char8* enumToString(PciDevice1D9B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D9B::NONE:        return "NONE";
        case PciDevice1D9B::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1D9B::DEVICE_0011: return "DEVICE_0011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D9B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D9B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D9B::DEVICE_0010: return "Networking DOM Engine";
        case PciDevice1D9B::DEVICE_0011: return "IO Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D9B_PCIDEVICE1D9B_H
