// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10027300: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B36 = 0x10020B36,
    SUBDEVICE_10021B36 = 0x10021B36,
    SUBDEVICE_1043049E = 0x1043049E,
    SUBDEVICE_104304A0 = 0x104304A0,
    SUBDEVICE_174BE329 = 0x174BE329
};



inline const char8* enumToString(PciSubDevice10027300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027300::NONE:               return "NONE";
        case PciSubDevice10027300::SUBDEVICE_10020B36: return "SUBDEVICE_10020B36";
        case PciSubDevice10027300::SUBDEVICE_10021B36: return "SUBDEVICE_10021B36";
        case PciSubDevice10027300::SUBDEVICE_1043049E: return "SUBDEVICE_1043049E";
        case PciSubDevice10027300::SUBDEVICE_104304A0: return "SUBDEVICE_104304A0";
        case PciSubDevice10027300::SUBDEVICE_174BE329: return "SUBDEVICE_174BE329";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10027300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10027300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027300::SUBDEVICE_10020B36: return "Radeon R9 FURY X / NANO";
        case PciSubDevice10027300::SUBDEVICE_10021B36: return "Radeon Pro Duo";
        case PciSubDevice10027300::SUBDEVICE_1043049E: return "Radeon R9 FURY";
        case PciSubDevice10027300::SUBDEVICE_104304A0: return "Radeon R9 FURY X";
        case PciSubDevice10027300::SUBDEVICE_174BE329: return "Radeon R9 FURY";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027300_H
