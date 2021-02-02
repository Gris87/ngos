// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1745_PCIDEVICE1745_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1745_PCIDEVICE1745_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1745: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2020 = 0x2020,
    DEVICE_2100 = 0x2100
};



inline const char8* enumToString(PciDevice1745 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1745::NONE:        return "NONE";
        case PciDevice1745::DEVICE_2020: return "DEVICE_2020";
        case PciDevice1745::DEVICE_2100: return "DEVICE_2100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1745 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1745 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1745::DEVICE_2020: return "XCode II Series";
        case PciDevice1745::DEVICE_2100: return "XCode 2100 Series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1745_PCIDEVICE1745_H
