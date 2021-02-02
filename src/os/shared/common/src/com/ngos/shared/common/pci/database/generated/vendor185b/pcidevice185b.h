// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR185B_PCIDEVICE185B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR185B_PCIDEVICE185B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice185B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1489 = 0x1489
};



inline const char8* enumToString(PciDevice185B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice185B::NONE:        return "NONE";
        case PciDevice185B::DEVICE_1489: return "DEVICE_1489";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice185B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice185B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice185B::DEVICE_1489: return "VideoMate Vista T100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR185B_PCIDEVICE185B_H
