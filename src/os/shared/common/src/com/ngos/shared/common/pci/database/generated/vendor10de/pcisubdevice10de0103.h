// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0103_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0103_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0103: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10480C40 = 0x10480C40,
    SUBDEVICE_10480C44 = 0x10480C44,
    SUBDEVICE_10480C45 = 0x10480C45,
    SUBDEVICE_10480C4A = 0x10480C4A,
    SUBDEVICE_10480C4B = 0x10480C4B,
    SUBDEVICE_10A99002 = 0x10A99002
};



inline const char8* enumToString(PciSubDevice10DE0103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0103::NONE:               return "NONE";
        case PciSubDevice10DE0103::SUBDEVICE_10480C40: return "SUBDEVICE_10480C40";
        case PciSubDevice10DE0103::SUBDEVICE_10480C44: return "SUBDEVICE_10480C44";
        case PciSubDevice10DE0103::SUBDEVICE_10480C45: return "SUBDEVICE_10480C45";
        case PciSubDevice10DE0103::SUBDEVICE_10480C4A: return "SUBDEVICE_10480C4A";
        case PciSubDevice10DE0103::SUBDEVICE_10480C4B: return "SUBDEVICE_10480C4B";
        case PciSubDevice10DE0103::SUBDEVICE_10A99002: return "SUBDEVICE_10A99002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0103::SUBDEVICE_10480C40: return "GLoria II-64";
        case PciSubDevice10DE0103::SUBDEVICE_10480C44: return "GLoria II";
        case PciSubDevice10DE0103::SUBDEVICE_10480C45: return "GLoria II";
        case PciSubDevice10DE0103::SUBDEVICE_10480C4A: return "GLoria II-64 Pro";
        case PciSubDevice10DE0103::SUBDEVICE_10480C4B: return "GLoria II-64 Pro DVII";
        case PciSubDevice10DE0103::SUBDEVICE_10A99002: return "VPro VR3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0103_H
