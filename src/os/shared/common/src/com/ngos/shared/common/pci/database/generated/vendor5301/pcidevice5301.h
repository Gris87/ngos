// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5301_PCIDEVICE5301_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5301_PCIDEVICE5301_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5301: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice5301 device5301) // TEST: NO
{
    // COMMON_LT((" | device5301 = %u", device5301)); // Commented to avoid bad looking logs



    switch (device5301)
    {
        case PciDevice5301::NONE:        return "NONE";
        case PciDevice5301::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5301 device5301) // TEST: NO
{
    // COMMON_LT((" | device5301 = %u", device5301)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5301, enumToString(device5301));

    return res;
}



inline const char8* enumToHumanString(PciDevice5301 device5301) // TEST: NO
{
    // COMMON_LT((" | device5301 = %u", device5301)); // Commented to avoid bad looking logs



    switch (device5301)
    {
        case PciDevice5301::DEVICE_0001: return "ProMotion aT3D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5301_PCIDEVICE5301_H
