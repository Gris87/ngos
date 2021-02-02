// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1432_PCIDEVICE1432_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1432_PCIDEVICE1432_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1432: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9130 = 0x9130
};



inline const char8* enumToString(PciDevice1432 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1432::NONE:        return "NONE";
        case PciDevice1432::DEVICE_9130: return "DEVICE_9130";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1432 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1432 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1432::DEVICE_9130: return "RTL81xx Fast Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1432_PCIDEVICE1432_H
