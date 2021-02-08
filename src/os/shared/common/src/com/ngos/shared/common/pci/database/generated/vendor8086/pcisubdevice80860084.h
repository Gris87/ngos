// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860084_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860084_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860084: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861215 = 0x80861215,
    SUBDEVICE_80861216 = 0x80861216,
    SUBDEVICE_80861315 = 0x80861315,
    SUBDEVICE_80861316 = 0x80861316
};



inline const char8* enumToString(PciSubDevice80860084 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860084::NONE:               return "NONE";
        case PciSubDevice80860084::SUBDEVICE_80861215: return "SUBDEVICE_80861215";
        case PciSubDevice80860084::SUBDEVICE_80861216: return "SUBDEVICE_80861216";
        case PciSubDevice80860084::SUBDEVICE_80861315: return "SUBDEVICE_80861315";
        case PciSubDevice80860084::SUBDEVICE_80861316: return "SUBDEVICE_80861316";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860084 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860084 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860084::SUBDEVICE_80861215: return "Centrino Wireless-N 1000 BGN";
        case PciSubDevice80860084::SUBDEVICE_80861216: return "Centrino Wireless-N 1000 BG";
        case PciSubDevice80860084::SUBDEVICE_80861315: return "Centrino Wireless-N 1000 BGN";
        case PciSubDevice80860084::SUBDEVICE_80861316: return "Centrino Wireless-N 1000 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860084_H
