// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1538_PCIDEVICE1538_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1538_PCIDEVICE1538_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1538: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0303 = 0x0303
};



inline const char8* enumToString(PciDevice1538 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1538::NONE:        return "NONE";
        case PciDevice1538::DEVICE_0303: return "DEVICE_0303";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1538 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1538 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1538::DEVICE_0303: return "ARS106S Ultra ATA 133/100/66 Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1538_PCIDEVICE1538_H
