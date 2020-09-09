// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95229_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95229_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B95229: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014050F = 0x1014050F,
    SUBDEVICE_1014053D = 0x1014053D,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_103C0025 = 0x103C0025,
    SUBDEVICE_10438053 = 0x10438053,
    SUBDEVICE_18495229 = 0x18495229
};



inline const char8* enumToString(PciSubDevice10B95229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95229::NONE:               return "NONE";
        case PciSubDevice10B95229::SUBDEVICE_1014050F: return "SUBDEVICE_1014050F";
        case PciSubDevice10B95229::SUBDEVICE_1014053D: return "SUBDEVICE_1014053D";
        case PciSubDevice10B95229::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice10B95229::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";
        case PciSubDevice10B95229::SUBDEVICE_10438053: return "SUBDEVICE_10438053";
        case PciSubDevice10B95229::SUBDEVICE_18495229: return "SUBDEVICE_18495229";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B95229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B95229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95229::SUBDEVICE_1014050F: return "ThinkPad R30";
        case PciSubDevice10B95229::SUBDEVICE_1014053D: return "ThinkPad R40e";
        case PciSubDevice10B95229::SUBDEVICE_103C0024: return "Pavilion ze4400 builtin IDE";
        case PciSubDevice10B95229::SUBDEVICE_103C0025: return "XE4500 Notebook";
        case PciSubDevice10B95229::SUBDEVICE_10438053: return "A7A266 Motherboard IDE";
        case PciSubDevice10B95229::SUBDEVICE_18495229: return "ASRock 939Dual-SATA2 Motherboard IDE (PATA)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95229_H
