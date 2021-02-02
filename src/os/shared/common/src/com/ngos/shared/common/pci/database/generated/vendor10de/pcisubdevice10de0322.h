// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0322_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0322_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0322: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104302FB = 0x104302FB,
    SUBDEVICE_10438180 = 0x10438180,
    SUBDEVICE_107D2967 = 0x107D2967,
    SUBDEVICE_14629110 = 0x14629110,
    SUBDEVICE_14629171 = 0x14629171,
    SUBDEVICE_14629360 = 0x14629360,
    SUBDEVICE_16821351 = 0x16821351
};



inline const char8* enumToString(PciSubDevice10DE0322 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0322::NONE:               return "NONE";
        case PciSubDevice10DE0322::SUBDEVICE_104302FB: return "SUBDEVICE_104302FB";
        case PciSubDevice10DE0322::SUBDEVICE_10438180: return "SUBDEVICE_10438180";
        case PciSubDevice10DE0322::SUBDEVICE_107D2967: return "SUBDEVICE_107D2967";
        case PciSubDevice10DE0322::SUBDEVICE_14629110: return "SUBDEVICE_14629110";
        case PciSubDevice10DE0322::SUBDEVICE_14629171: return "SUBDEVICE_14629171";
        case PciSubDevice10DE0322::SUBDEVICE_14629360: return "SUBDEVICE_14629360";
        case PciSubDevice10DE0322::SUBDEVICE_16821351: return "SUBDEVICE_16821351";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0322 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0322 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0322::SUBDEVICE_104302FB: return "V9250 Magic";
        case PciSubDevice10DE0322::SUBDEVICE_10438180: return "V9520-X/TD/128M";
        case PciSubDevice10DE0322::SUBDEVICE_107D2967: return "WinFast A340T 128MB";
        case PciSubDevice10DE0322::SUBDEVICE_14629110: return "MS-8911 (FX5200-TD128)";
        case PciSubDevice10DE0322::SUBDEVICE_14629171: return "MS-8917 (FX5200-T128)";
        case PciSubDevice10DE0322::SUBDEVICE_14629360: return "MS-8936 (FX5200-T128)";
        case PciSubDevice10DE0322::SUBDEVICE_16821351: return "GeForce FX 5200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0322_H
