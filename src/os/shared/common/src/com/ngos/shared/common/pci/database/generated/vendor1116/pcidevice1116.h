// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1116_PCIDEVICE1116_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1116_PCIDEVICE1116_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1116: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0026 = 0x0026,
    DEVICE_0027 = 0x0027,
    DEVICE_0028 = 0x0028,
    DEVICE_0051 = 0x0051,
    DEVICE_0060 = 0x0060,
    DEVICE_0069 = 0x0069,
    DEVICE_80C2 = 0x80C2
};



inline const char8* enumToString(PciDevice1116 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1116::NONE:        return "NONE";
        case PciDevice1116::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1116::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1116::DEVICE_0024: return "DEVICE_0024";
        case PciDevice1116::DEVICE_0025: return "DEVICE_0025";
        case PciDevice1116::DEVICE_0026: return "DEVICE_0026";
        case PciDevice1116::DEVICE_0027: return "DEVICE_0027";
        case PciDevice1116::DEVICE_0028: return "DEVICE_0028";
        case PciDevice1116::DEVICE_0051: return "DEVICE_0051";
        case PciDevice1116::DEVICE_0060: return "DEVICE_0060";
        case PciDevice1116::DEVICE_0069: return "DEVICE_0069";
        case PciDevice1116::DEVICE_80C2: return "DEVICE_80C2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1116 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1116 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1116::DEVICE_0022: return "DT3001";
        case PciDevice1116::DEVICE_0023: return "DT3002";
        case PciDevice1116::DEVICE_0024: return "DT3003";
        case PciDevice1116::DEVICE_0025: return "DT3004";
        case PciDevice1116::DEVICE_0026: return "DT3005";
        case PciDevice1116::DEVICE_0027: return "DT3001-PGL";
        case PciDevice1116::DEVICE_0028: return "DT3003-PGL";
        case PciDevice1116::DEVICE_0051: return "DT322";
        case PciDevice1116::DEVICE_0060: return "DT340";
        case PciDevice1116::DEVICE_0069: return "DT332";
        case PciDevice1116::DEVICE_80C2: return "DT3162";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1116_PCIDEVICE1116_H
