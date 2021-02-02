// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1158_PCIDEVICE1158_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1158_PCIDEVICE1158_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1158: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3011 = 0x3011,
    DEVICE_9050 = 0x9050,
    DEVICE_9051 = 0x9051
};



inline const char8* enumToString(PciDevice1158 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1158::NONE:        return "NONE";
        case PciDevice1158::DEVICE_3011: return "DEVICE_3011";
        case PciDevice1158::DEVICE_9050: return "DEVICE_9050";
        case PciDevice1158::DEVICE_9051: return "DEVICE_9051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1158 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1158 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1158::DEVICE_3011: return "Tokenet/vg 1001/10m anylan";
        case PciDevice1158::DEVICE_9050: return "Lanfleet/Truevalue";
        case PciDevice1158::DEVICE_9051: return "Lanfleet/Truevalue";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1158_PCIDEVICE1158_H
