// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10442_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10442_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10442: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11C10440 = 0x11C10440,
    SUBDEVICE_11C10442 = 0x11C10442,
    SUBDEVICE_13E00412 = 0x13E00412,
    SUBDEVICE_13E00442 = 0x13E00442,
    SUBDEVICE_13FC2471 = 0x13FC2471,
    SUBDEVICE_144D2104 = 0x144D2104,
    SUBDEVICE_144F1104 = 0x144F1104,
    SUBDEVICE_149F0440 = 0x149F0440,
    SUBDEVICE_16680440 = 0x16680440
};



inline const char8* enumToString(PciSubDevice11C10442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10442::NONE:               return "NONE";
        case PciSubDevice11C10442::SUBDEVICE_11C10440: return "SUBDEVICE_11C10440";
        case PciSubDevice11C10442::SUBDEVICE_11C10442: return "SUBDEVICE_11C10442";
        case PciSubDevice11C10442::SUBDEVICE_13E00412: return "SUBDEVICE_13E00412";
        case PciSubDevice11C10442::SUBDEVICE_13E00442: return "SUBDEVICE_13E00442";
        case PciSubDevice11C10442::SUBDEVICE_13FC2471: return "SUBDEVICE_13FC2471";
        case PciSubDevice11C10442::SUBDEVICE_144D2104: return "SUBDEVICE_144D2104";
        case PciSubDevice11C10442::SUBDEVICE_144F1104: return "SUBDEVICE_144F1104";
        case PciSubDevice11C10442::SUBDEVICE_149F0440: return "SUBDEVICE_149F0440";
        case PciSubDevice11C10442::SUBDEVICE_16680440: return "SUBDEVICE_16680440";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10442::SUBDEVICE_11C10440: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_11C10442: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_13E00412: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_13E00442: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_13FC2471: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_144D2104: return "LT56PT Modem";
        case PciSubDevice11C10442::SUBDEVICE_144F1104: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_149F0440: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";
        case PciSubDevice11C10442::SUBDEVICE_16680440: return "LT WinModem 56k Data+Fax+Voice+VoiceView+Dsvd";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10442_H
