// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1124_PCIDEVICE1124_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1124_PCIDEVICE1124_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1124: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2581 = 0x2581
};



inline const char8* enumToString(PciDevice1124 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1124::NONE:        return "NONE";
        case PciDevice1124::DEVICE_2581: return "DEVICE_2581";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1124 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1124 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1124::DEVICE_2581: return "Picport Monochrome";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1124_PCIDEVICE1124_H
