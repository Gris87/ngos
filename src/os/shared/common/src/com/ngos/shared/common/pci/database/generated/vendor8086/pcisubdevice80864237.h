// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864237_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864237_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864237: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861211 = 0x80861211,
    SUBDEVICE_80861214 = 0x80861214,
    SUBDEVICE_80861215 = 0x80861215,
    SUBDEVICE_80861216 = 0x80861216,
    SUBDEVICE_80861311 = 0x80861311,
    SUBDEVICE_80861314 = 0x80861314,
    SUBDEVICE_80861315 = 0x80861315,
    SUBDEVICE_80861316 = 0x80861316
};



inline const char8* enumToString(PciSubDevice80864237 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864237::NONE:               return "NONE";
        case PciSubDevice80864237::SUBDEVICE_80861211: return "SUBDEVICE_80861211";
        case PciSubDevice80864237::SUBDEVICE_80861214: return "SUBDEVICE_80861214";
        case PciSubDevice80864237::SUBDEVICE_80861215: return "SUBDEVICE_80861215";
        case PciSubDevice80864237::SUBDEVICE_80861216: return "SUBDEVICE_80861216";
        case PciSubDevice80864237::SUBDEVICE_80861311: return "SUBDEVICE_80861311";
        case PciSubDevice80864237::SUBDEVICE_80861314: return "SUBDEVICE_80861314";
        case PciSubDevice80864237::SUBDEVICE_80861315: return "SUBDEVICE_80861315";
        case PciSubDevice80864237::SUBDEVICE_80861316: return "SUBDEVICE_80861316";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864237 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864237 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864237::SUBDEVICE_80861211: return "WiFi Link 5100 AGN";
        case PciSubDevice80864237::SUBDEVICE_80861214: return "WiFi Link 5100 AGN";
        case PciSubDevice80864237::SUBDEVICE_80861215: return "WiFi Link 5100 BGN";
        case PciSubDevice80864237::SUBDEVICE_80861216: return "WiFi Link 5100 ABG";
        case PciSubDevice80864237::SUBDEVICE_80861311: return "WiFi Link 5100 AGN";
        case PciSubDevice80864237::SUBDEVICE_80861314: return "WiFi Link 5100 AGN";
        case PciSubDevice80864237::SUBDEVICE_80861315: return "WiFi Link 5100 BGN";
        case PciSubDevice80864237::SUBDEVICE_80861316: return "WiFi Link 5100 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864237_H
