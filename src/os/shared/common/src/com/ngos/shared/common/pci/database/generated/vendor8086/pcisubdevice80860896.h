// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860896_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860896_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860896: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865005 = 0x80865005,
    SUBDEVICE_80865007 = 0x80865007,
    SUBDEVICE_80865025 = 0x80865025,
    SUBDEVICE_80865027 = 0x80865027
};



inline const char8* enumToString(PciSubDevice80860896 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860896::NONE:               return "NONE";
        case PciSubDevice80860896::SUBDEVICE_80865005: return "SUBDEVICE_80865005";
        case PciSubDevice80860896::SUBDEVICE_80865007: return "SUBDEVICE_80865007";
        case PciSubDevice80860896::SUBDEVICE_80865025: return "SUBDEVICE_80865025";
        case PciSubDevice80860896::SUBDEVICE_80865027: return "SUBDEVICE_80865027";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860896 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860896 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860896::SUBDEVICE_80865005: return "Centrino Wireless-N 130 BGN";
        case PciSubDevice80860896::SUBDEVICE_80865007: return "Centrino Wireless-N 130 BG";
        case PciSubDevice80860896::SUBDEVICE_80865025: return "Centrino Wireless-N 130 BGN";
        case PciSubDevice80860896::SUBDEVICE_80865027: return "Centrino Wireless-N 130 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860896_H
