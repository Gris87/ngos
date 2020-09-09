// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10280003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280003 = 0x10280003
};



inline const char8* enumToString(PciSubDevice10280003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280003::NONE:               return "NONE";
        case PciSubDevice10280003::SUBDEVICE_10280003: return "SUBDEVICE_10280003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10280003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10280003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280003::SUBDEVICE_10280003: return "PowerEdge 2450";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280003_H
