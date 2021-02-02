// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1142_PCIDEVICE1142_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1142_PCIDEVICE1142_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1142: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3210 = 0x3210,
    DEVICE_6422 = 0x6422,
    DEVICE_6424 = 0x6424,
    DEVICE_6425 = 0x6425,
    DEVICE_643D = 0x643D
};



inline const char8* enumToString(PciDevice1142 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1142::NONE:        return "NONE";
        case PciDevice1142::DEVICE_3210: return "DEVICE_3210";
        case PciDevice1142::DEVICE_6422: return "DEVICE_6422";
        case PciDevice1142::DEVICE_6424: return "DEVICE_6424";
        case PciDevice1142::DEVICE_6425: return "DEVICE_6425";
        case PciDevice1142::DEVICE_643D: return "DEVICE_643D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1142 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1142 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1142::DEVICE_3210: return "AP6410";
        case PciDevice1142::DEVICE_6422: return "ProVideo 6422";
        case PciDevice1142::DEVICE_6424: return "ProVideo 6424";
        case PciDevice1142::DEVICE_6425: return "ProMotion AT25";
        case PciDevice1142::DEVICE_643D: return "ProMotion AT3D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1142_PCIDEVICE1142_H
