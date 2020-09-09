// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1292_PCIDEVICE1292_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1292_PCIDEVICE1292_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1292: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_FC02 = 0xFC02
};



inline const char8* enumToString(PciDevice1292 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1292::NONE:        return "NONE";
        case PciDevice1292::DEVICE_FC02: return "DEVICE_FC02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1292 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1292 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1292::DEVICE_FC02: return "Pyramid3D TR25202";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1292_PCIDEVICE1292_H
