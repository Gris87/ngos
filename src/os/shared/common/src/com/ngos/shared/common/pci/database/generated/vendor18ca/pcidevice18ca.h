// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18CA_PCIDEVICE18CA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18CA_PCIDEVICE18CA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18CA: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0027 = 0x0027,
    DEVICE_0040 = 0x0040,
    DEVICE_0047 = 0x0047
};



inline const char8* enumToString(PciDevice18CA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18CA::NONE:        return "NONE";
        case PciDevice18CA::DEVICE_0020: return "DEVICE_0020";
        case PciDevice18CA::DEVICE_0021: return "DEVICE_0021";
        case PciDevice18CA::DEVICE_0027: return "DEVICE_0027";
        case PciDevice18CA::DEVICE_0040: return "DEVICE_0040";
        case PciDevice18CA::DEVICE_0047: return "DEVICE_0047";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18CA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice18CA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18CA::DEVICE_0020: return "Z7/Z9 (XG20 core)";
        case PciDevice18CA::DEVICE_0021: return "Z9s/Z9m (XG21 core)";
        case PciDevice18CA::DEVICE_0027: return "Z11/Z11M";
        case PciDevice18CA::DEVICE_0040: return "Volari V3XT/V5/V8";
        case PciDevice18CA::DEVICE_0047: return "Volari 8300 (chip: XP10, codename: XG47)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18CA_PCIDEVICE18CA_H
