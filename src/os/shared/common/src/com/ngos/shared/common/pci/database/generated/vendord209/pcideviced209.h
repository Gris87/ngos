// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD209_PCIDEVICED209_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD209_PCIDEVICED209_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceD209: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1500 = 0x1500,
    DEVICE_15A2 = 0x15A2,
    DEVICE_1601 = 0x1601
};



inline const char8* enumToString(PciDeviceD209 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceD209::NONE:        return "NONE";
        case PciDeviceD209::DEVICE_1500: return "DEVICE_1500";
        case PciDeviceD209::DEVICE_15A2: return "DEVICE_15A2";
        case PciDeviceD209::DEVICE_1601: return "DEVICE_1601";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceD209 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceD209 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceD209::DEVICE_1500: return "PAC Drive";
        case PciDeviceD209::DEVICE_15A2: return "SpinTrak";
        case PciDeviceD209::DEVICE_1601: return "AimTrak";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD209_PCIDEVICED209_H
