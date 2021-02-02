// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE4BF_PCIDEVICEE4BF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE4BF_PCIDEVICEE4BF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceE4BF: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0CCD = 0x0CCD,
    DEVICE_0CD1 = 0x0CD1,
    DEVICE_0CD2 = 0x0CD2,
    DEVICE_0CD3 = 0x0CD3,
    DEVICE_50C1 = 0x50C1,
    DEVICE_50C2 = 0x50C2,
    DEVICE_53C1 = 0x53C1,
    DEVICE_CC47 = 0xCC47,
    DEVICE_CC4D = 0xCC4D
};



inline const char8* enumToString(PciDeviceE4BF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE4BF::NONE:        return "NONE";
        case PciDeviceE4BF::DEVICE_0CCD: return "DEVICE_0CCD";
        case PciDeviceE4BF::DEVICE_0CD1: return "DEVICE_0CD1";
        case PciDeviceE4BF::DEVICE_0CD2: return "DEVICE_0CD2";
        case PciDeviceE4BF::DEVICE_0CD3: return "DEVICE_0CD3";
        case PciDeviceE4BF::DEVICE_50C1: return "DEVICE_50C1";
        case PciDeviceE4BF::DEVICE_50C2: return "DEVICE_50C2";
        case PciDeviceE4BF::DEVICE_53C1: return "DEVICE_53C1";
        case PciDeviceE4BF::DEVICE_CC47: return "DEVICE_CC47";
        case PciDeviceE4BF::DEVICE_CC4D: return "DEVICE_CC4D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceE4BF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceE4BF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE4BF::DEVICE_0CCD: return "CCD-CALYPSO";
        case PciDeviceE4BF::DEVICE_0CD1: return "CD1-OPERA";
        case PciDeviceE4BF::DEVICE_0CD2: return "CD2-BEBOP";
        case PciDeviceE4BF::DEVICE_0CD3: return "CD3-JIVE";
        case PciDeviceE4BF::DEVICE_50C1: return "PC1-GROOVE";
        case PciDeviceE4BF::DEVICE_50C2: return "PC2-LIMBO";
        case PciDeviceE4BF::DEVICE_53C1: return "SC1-ALLEGRO";
        case PciDeviceE4BF::DEVICE_CC47: return "CCG-RUMBA";
        case PciDeviceE4BF::DEVICE_CC4D: return "CCM-BOOGIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE4BF_PCIDEVICEE4BF_H
