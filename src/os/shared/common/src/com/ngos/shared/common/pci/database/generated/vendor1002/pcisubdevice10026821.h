// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026821_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026821_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026821: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002031E = 0x1002031E,
    SUBDEVICE_102805CC = 0x102805CC,
    SUBDEVICE_102815CC = 0x102815CC,
    SUBDEVICE_106B0149 = 0x106B0149
};



inline const char8* enumToString(PciSubDevice10026821 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026821::NONE:               return "NONE";
        case PciSubDevice10026821::SUBDEVICE_1002031E: return "SUBDEVICE_1002031E";
        case PciSubDevice10026821::SUBDEVICE_102805CC: return "SUBDEVICE_102805CC";
        case PciSubDevice10026821::SUBDEVICE_102815CC: return "SUBDEVICE_102815CC";
        case PciSubDevice10026821::SUBDEVICE_106B0149: return "SUBDEVICE_106B0149";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026821 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026821 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026821::SUBDEVICE_1002031E: return "FirePro SX4000";
        case PciSubDevice10026821::SUBDEVICE_102805CC: return "FirePro M5100";
        case PciSubDevice10026821::SUBDEVICE_102815CC: return "FirePro M5100";
        case PciSubDevice10026821::SUBDEVICE_106B0149: return "Radeon R9 M370X Mac Edition";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026821_H
