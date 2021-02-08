// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0615_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0615_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0615: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_38421150 = 0x38421150,
    SUBDEVICE_38421151 = 0x38421151,
    SUBDEVICE_38421155 = 0x38421155,
    SUBDEVICE_38421156 = 0x38421156
};



inline const char8* enumToString(PciSubDevice10DE0615 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0615::NONE:               return "NONE";
        case PciSubDevice10DE0615::SUBDEVICE_38421150: return "SUBDEVICE_38421150";
        case PciSubDevice10DE0615::SUBDEVICE_38421151: return "SUBDEVICE_38421151";
        case PciSubDevice10DE0615::SUBDEVICE_38421155: return "SUBDEVICE_38421155";
        case PciSubDevice10DE0615::SUBDEVICE_38421156: return "SUBDEVICE_38421156";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0615 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0615 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0615::SUBDEVICE_38421150: return "GeForce GTS 250 P/N 512-P3-1150-TR";
        case PciSubDevice10DE0615::SUBDEVICE_38421151: return "GeForce GTS 250 P/N 512-P3-1151-TR";
        case PciSubDevice10DE0615::SUBDEVICE_38421155: return "GeForce GTS 250 P/N 01G-P3-1155-TR";
        case PciSubDevice10DE0615::SUBDEVICE_38421156: return "GeForce GTS 250 P/N 01G-P3-1156-TR";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0615_H
