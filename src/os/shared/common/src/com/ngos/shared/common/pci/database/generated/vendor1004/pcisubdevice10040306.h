// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040306_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040306_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10040306: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10040306 = 0x10040306,
    SUBDEVICE_122D1208 = 0x122D1208,
    SUBDEVICE_14835022 = 0x14835022
};



inline const char8* enumToString(PciSubDevice10040306 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040306::NONE:               return "NONE";
        case PciSubDevice10040306::SUBDEVICE_10040306: return "SUBDEVICE_10040306";
        case PciSubDevice10040306::SUBDEVICE_122D1208: return "SUBDEVICE_122D1208";
        case PciSubDevice10040306::SUBDEVICE_14835022: return "SUBDEVICE_14835022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10040306 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10040306 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040306::SUBDEVICE_10040306: return "QSound ThunderBird PCI Audio Support Registers";
        case PciSubDevice10040306::SUBDEVICE_122D1208: return "DSP368 Audio Support Registers";
        case PciSubDevice10040306::SUBDEVICE_14835022: return "XWave Thunder 3D Audio Support Registers";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040306_H
