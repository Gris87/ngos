// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C2_PCIDEVICE13C2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C2_PCIDEVICE13C2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13C2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000E = 0x000E,
    DEVICE_1019 = 0x1019
};



inline const char8* enumToString(PciDevice13C2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C2::NONE:        return "NONE";
        case PciDevice13C2::DEVICE_000E: return "DEVICE_000E";
        case PciDevice13C2::DEVICE_1019: return "DEVICE_1019";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13C2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13C2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C2::DEVICE_000E: return "Technotrend/Hauppauge DVB card rev2.3";
        case PciDevice13C2::DEVICE_1019: return "TTechnoTrend-budget DVB S2-3200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C2_PCIDEVICE13C2_H
