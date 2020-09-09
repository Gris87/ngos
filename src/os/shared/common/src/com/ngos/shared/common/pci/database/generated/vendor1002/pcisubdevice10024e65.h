// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E65_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E65_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024E65: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020003 = 0x10020003,
    SUBDEVICE_16810003 = 0x16810003
};



inline const char8* enumToString(PciSubDevice10024E65 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E65::NONE:               return "NONE";
        case PciSubDevice10024E65::SUBDEVICE_10020003: return "SUBDEVICE_10020003";
        case PciSubDevice10024E65::SUBDEVICE_16810003: return "SUBDEVICE_16810003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024E65 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024E65 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E65::SUBDEVICE_10020003: return "Radeon R300 NE [Radeon 9500 Pro]";
        case PciSubDevice10024E65::SUBDEVICE_16810003: return "Hercules 3D Prophet 9500 PRO [Radeon 9500 Pro] (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E65_H
