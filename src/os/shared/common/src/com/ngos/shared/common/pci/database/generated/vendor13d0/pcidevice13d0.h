// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13D0_PCIDEVICE13D0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13D0_PCIDEVICE13D0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13D0: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2103 = 0x2103,
    DEVICE_2104 = 0x2104,
    DEVICE_2200 = 0x2200
};



inline const char8* enumToString(PciDevice13D0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13D0::NONE:        return "NONE";
        case PciDevice13D0::DEVICE_2103: return "DEVICE_2103";
        case PciDevice13D0::DEVICE_2104: return "DEVICE_2104";
        case PciDevice13D0::DEVICE_2200: return "DEVICE_2200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13D0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13D0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13D0::DEVICE_2103: return "B2C2 FlexCopII DVB chip / Technisat SkyStar2 DVB card";
        case PciDevice13D0::DEVICE_2104: return "B2C2 FlexCopIII DVB chip / Technisat SkyStar2 DVB card (rev 01)";
        case PciDevice13D0::DEVICE_2200: return "B2C2 FlexCopIII DVB chip / Technisat SkyStar2 DVB card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13D0_PCIDEVICE13D0_H
