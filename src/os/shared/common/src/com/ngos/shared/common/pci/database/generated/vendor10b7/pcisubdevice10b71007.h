// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B71007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B71007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B71007: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B7615B = 0x10B7615B,
    SUBDEVICE_10B7615C = 0x10B7615C
};



inline const char8* enumToString(PciSubDevice10B71007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B71007::NONE:               return "NONE";
        case PciSubDevice10B71007::SUBDEVICE_10B7615B: return "SUBDEVICE_10B7615B";
        case PciSubDevice10B71007::SUBDEVICE_10B7615C: return "SUBDEVICE_10B7615C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B71007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B71007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B71007::SUBDEVICE_10B7615B: return "Mini PCI 56K Modem";
        case PciSubDevice10B71007::SUBDEVICE_10B7615C: return "Mini PCI 56K Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B71007_H
