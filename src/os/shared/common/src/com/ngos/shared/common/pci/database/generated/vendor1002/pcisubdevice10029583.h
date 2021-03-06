// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029583_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029583_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029583: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B0083 = 0x106B0083,
    SUBDEVICE_17341107 = 0x17341107
};



inline const char8* enumToString(PciSubDevice10029583 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029583::NONE:               return "NONE";
        case PciSubDevice10029583::SUBDEVICE_106B0083: return "SUBDEVICE_106B0083";
        case PciSubDevice10029583::SUBDEVICE_17341107: return "SUBDEVICE_17341107";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029583 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029583 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029583::SUBDEVICE_106B0083: return "iMac 7, 1";
        case PciSubDevice10029583::SUBDEVICE_17341107: return "Mobility Radeon HD 2700";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029583_H
