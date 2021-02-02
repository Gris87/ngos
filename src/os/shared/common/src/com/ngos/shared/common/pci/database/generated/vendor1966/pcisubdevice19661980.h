// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCISUBDEVICE19661980_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCISUBDEVICE19661980_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19661980: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12343160 = 0x12343160,
    SUBDEVICE_12343300 = 0x12343300,
    SUBDEVICE_12343410 = 0x12343410
};



inline const char8* enumToString(PciSubDevice19661980 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19661980::NONE:               return "NONE";
        case PciSubDevice19661980::SUBDEVICE_12343160: return "SUBDEVICE_12343160";
        case PciSubDevice19661980::SUBDEVICE_12343300: return "SUBDEVICE_12343300";
        case PciSubDevice19661980::SUBDEVICE_12343410: return "SUBDEVICE_12343410";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19661980 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19661980 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19661980::SUBDEVICE_12343160: return "UHD2LC";
        case PciSubDevice19661980::SUBDEVICE_12343300: return "Legacy UHD2";
        case PciSubDevice19661980::SUBDEVICE_12343410: return "UHD2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCISUBDEVICE19661980_H
