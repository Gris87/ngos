// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCACE_PCIDEVICECACE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCACE_PCIDEVICECACE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceCACE: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0023 = 0x0023
};



inline const char8* enumToString(PciDeviceCACE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceCACE::NONE:        return "NONE";
        case PciDeviceCACE::DEVICE_0001: return "DEVICE_0001";
        case PciDeviceCACE::DEVICE_0002: return "DEVICE_0002";
        case PciDeviceCACE::DEVICE_0023: return "DEVICE_0023";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceCACE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceCACE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceCACE::DEVICE_0001: return "TurboCap Port A";
        case PciDeviceCACE::DEVICE_0002: return "TurboCap Port B";
        case PciDeviceCACE::DEVICE_0023: return "AirPcap N";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCACE_PCIDEVICECACE_H
