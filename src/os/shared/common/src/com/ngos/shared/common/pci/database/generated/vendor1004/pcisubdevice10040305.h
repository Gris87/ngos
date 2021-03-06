// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040305_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040305_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10040305: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10040305 = 0x10040305,
    SUBDEVICE_122D1207 = 0x122D1207,
    SUBDEVICE_14835021 = 0x14835021
};



inline const char8* enumToString(PciSubDevice10040305 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040305::NONE:               return "NONE";
        case PciSubDevice10040305::SUBDEVICE_10040305: return "SUBDEVICE_10040305";
        case PciSubDevice10040305::SUBDEVICE_122D1207: return "SUBDEVICE_122D1207";
        case PciSubDevice10040305::SUBDEVICE_14835021: return "SUBDEVICE_14835021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10040305 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10040305 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040305::SUBDEVICE_10040305: return "QSound ThunderBird PCI Audio Gameport";
        case PciSubDevice10040305::SUBDEVICE_122D1207: return "DSP368 Audio Gameport";
        case PciSubDevice10040305::SUBDEVICE_14835021: return "XWave Thunder 3D Audio Gameport";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040305_H
