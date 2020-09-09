// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1044A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1044A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C1044A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF1072 = 0x10CF1072,
    SUBDEVICE_13E00012 = 0x13E00012,
    SUBDEVICE_13E00042 = 0x13E00042,
    SUBDEVICE_144F1005 = 0x144F1005
};



inline const char8* enumToString(PciSubDevice11C1044A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C1044A::NONE:               return "NONE";
        case PciSubDevice11C1044A::SUBDEVICE_10CF1072: return "SUBDEVICE_10CF1072";
        case PciSubDevice11C1044A::SUBDEVICE_13E00012: return "SUBDEVICE_13E00012";
        case PciSubDevice11C1044A::SUBDEVICE_13E00042: return "SUBDEVICE_13E00042";
        case PciSubDevice11C1044A::SUBDEVICE_144F1005: return "SUBDEVICE_144F1005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C1044A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C1044A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C1044A::SUBDEVICE_10CF1072: return "LB Global LT Modem";
        case PciSubDevice11C1044A::SUBDEVICE_13E00012: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C1044A::SUBDEVICE_13E00042: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C1044A::SUBDEVICE_144F1005: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1044A_H
