// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B70001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B70001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B70001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_98500001 = 0x98500001
};



inline const char8* enumToString(PciSubDevice10B70001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B70001::NONE:               return "NONE";
        case PciSubDevice10B70001::SUBDEVICE_98500001: return "SUBDEVICE_98500001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B70001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B70001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B70001::SUBDEVICE_98500001: return "3c985B-SX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B70001_H
