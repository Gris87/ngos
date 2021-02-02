// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8686_PCIDEVICE8686_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8686_PCIDEVICE8686_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8686: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1010 = 0x1010,
    DEVICE_1011 = 0x1011
};



inline const char8* enumToString(PciDevice8686 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8686::NONE:        return "NONE";
        case PciDevice8686::DEVICE_1010: return "DEVICE_1010";
        case PciDevice8686::DEVICE_1011: return "DEVICE_1011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8686 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice8686 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8686::DEVICE_1010: return "vSMP Foundation controller [vSMP CTL]";
        case PciDevice8686::DEVICE_1011: return "vSMP Foundation MEX/FLX controller [vSMP CTL]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8686_PCIDEVICE8686_H
