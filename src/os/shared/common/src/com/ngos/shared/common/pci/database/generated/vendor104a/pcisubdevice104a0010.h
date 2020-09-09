// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCISUBDEVICE104A0010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCISUBDEVICE104A0010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104A0010: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104A4018 = 0x104A4018,
    SUBDEVICE_16810010 = 0x16810010,
    SUBDEVICE_16810028 = 0x16810028,
    SUBDEVICE_1681C010 = 0x1681C010,
    SUBDEVICE_1681C069 = 0x1681C069
};



inline const char8* enumToString(PciSubDevice104A0010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104A0010::NONE:               return "NONE";
        case PciSubDevice104A0010::SUBDEVICE_104A4018: return "SUBDEVICE_104A4018";
        case PciSubDevice104A0010::SUBDEVICE_16810010: return "SUBDEVICE_16810010";
        case PciSubDevice104A0010::SUBDEVICE_16810028: return "SUBDEVICE_16810028";
        case PciSubDevice104A0010::SUBDEVICE_1681C010: return "SUBDEVICE_1681C010";
        case PciSubDevice104A0010::SUBDEVICE_1681C069: return "SUBDEVICE_1681C069";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104A0010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104A0010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104A0010::SUBDEVICE_104A4018: return "ST PowerVR Kyro (64MB AGP TVO)";
        case PciSubDevice104A0010::SUBDEVICE_16810010: return "PowerVR Kyro II [3D Prophet 4500]";
        case PciSubDevice104A0010::SUBDEVICE_16810028: return "3D Prophet 4000XT";
        case PciSubDevice104A0010::SUBDEVICE_1681C010: return "3D Prophet 4500 TV-Out";
        case PciSubDevice104A0010::SUBDEVICE_1681C069: return "3D Prophet 4000XT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCISUBDEVICE104A0010_H
