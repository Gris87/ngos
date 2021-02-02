// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1042_PCIDEVICE1042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1042_PCIDEVICE1042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1042: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_3000 = 0x3000,
    DEVICE_3010 = 0x3010,
    DEVICE_3020 = 0x3020
};



inline const char8* enumToString(PciDevice1042 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1042::NONE:        return "NONE";
        case PciDevice1042::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1042::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1042::DEVICE_3000: return "DEVICE_3000";
        case PciDevice1042::DEVICE_3010: return "DEVICE_3010";
        case PciDevice1042::DEVICE_3020: return "DEVICE_3020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1042 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1042 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1042::DEVICE_1000: return "PC Tech RZ1000";
        case PciDevice1042::DEVICE_1001: return "PC Tech RZ1001";
        case PciDevice1042::DEVICE_3000: return "Samurai_0";
        case PciDevice1042::DEVICE_3010: return "Samurai_1";
        case PciDevice1042::DEVICE_3020: return "Samurai_IDE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1042_PCIDEVICE1042_H
