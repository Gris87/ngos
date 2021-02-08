// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DA_PCIDEVICE10DA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DA_PCIDEVICE10DA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10DA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0508 = 0x0508,
    DEVICE_3390 = 0x3390
};



inline const char8* enumToString(PciDevice10DA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10DA::NONE:        return "NONE";
        case PciDevice10DA::DEVICE_0508: return "DEVICE_0508";
        case PciDevice10DA::DEVICE_3390: return "DEVICE_3390";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10DA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10DA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10DA::DEVICE_0508: return "TC4048 Token Ring 4/16";
        case PciDevice10DA::DEVICE_3390: return "Tl3c3x9";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DA_PCIDEVICE10DA_H
