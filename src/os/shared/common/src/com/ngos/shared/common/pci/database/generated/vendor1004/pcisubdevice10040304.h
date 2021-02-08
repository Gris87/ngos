// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040304_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040304_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10040304: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10040304 = 0x10040304,
    SUBDEVICE_122D1206 = 0x122D1206,
    SUBDEVICE_14835020 = 0x14835020
};



inline const char8* enumToString(PciSubDevice10040304 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040304::NONE:               return "NONE";
        case PciSubDevice10040304::SUBDEVICE_10040304: return "SUBDEVICE_10040304";
        case PciSubDevice10040304::SUBDEVICE_122D1206: return "SUBDEVICE_122D1206";
        case PciSubDevice10040304::SUBDEVICE_14835020: return "SUBDEVICE_14835020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10040304 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10040304 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040304::SUBDEVICE_10040304: return "QSound ThunderBird PCI Audio";
        case PciSubDevice10040304::SUBDEVICE_122D1206: return "DSP368 Audio";
        case PciSubDevice10040304::SUBDEVICE_14835020: return "XWave Thunder 3D Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040304_H
