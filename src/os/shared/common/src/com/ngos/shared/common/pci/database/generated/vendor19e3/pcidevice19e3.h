// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E3_PCIDEVICE19E3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E3_PCIDEVICE19E3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19E3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5801 = 0x5801,
    DEVICE_5808 = 0x5808,
    DEVICE_DD52 = 0xDD52
};



inline const char8* enumToString(PciDevice19E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice19E3::NONE:        return "NONE";
        case PciDevice19E3::DEVICE_5801: return "DEVICE_5801";
        case PciDevice19E3::DEVICE_5808: return "DEVICE_5808";
        case PciDevice19E3::DEVICE_DD52: return "DEVICE_DD52";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice19E3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice19E3::DEVICE_5801: return "DDRdrive X1";
        case PciDevice19E3::DEVICE_5808: return "DDRdrive X8";
        case PciDevice19E3::DEVICE_DD52: return "DDRdrive X1-30";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E3_PCIDEVICE19E3_H
