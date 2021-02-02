// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C28_PCIDEVICE1C28_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C28_PCIDEVICE1C28_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C28: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0122 = 0x0122
};



inline const char8* enumToString(PciDevice1C28 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C28::NONE:        return "NONE";
        case PciDevice1C28::DEVICE_0122: return "DEVICE_0122";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C28 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C28 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C28::DEVICE_0122: return "M6e PCI Express SSD [Marvell 88SS9183]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C28_PCIDEVICE1C28_H
