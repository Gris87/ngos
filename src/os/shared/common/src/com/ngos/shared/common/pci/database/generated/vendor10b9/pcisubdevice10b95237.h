// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95237_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95237_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B95237: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140540 = 0x10140540,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_103C0025 = 0x103C0025,
    SUBDEVICE_104D810F = 0x104D810F,
    SUBDEVICE_10B95237 = 0x10B95237,
    SUBDEVICE_18495237 = 0x18495237
};



inline const char8* enumToString(PciSubDevice10B95237 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95237::NONE:               return "NONE";
        case PciSubDevice10B95237::SUBDEVICE_10140540: return "SUBDEVICE_10140540";
        case PciSubDevice10B95237::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice10B95237::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";
        case PciSubDevice10B95237::SUBDEVICE_104D810F: return "SUBDEVICE_104D810F";
        case PciSubDevice10B95237::SUBDEVICE_10B95237: return "SUBDEVICE_10B95237";
        case PciSubDevice10B95237::SUBDEVICE_18495237: return "SUBDEVICE_18495237";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B95237 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B95237 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95237::SUBDEVICE_10140540: return "ThinkPad R40e";
        case PciSubDevice10B95237::SUBDEVICE_103C0024: return "Pavilion ze4400 builtin USB";
        case PciSubDevice10B95237::SUBDEVICE_103C0025: return "XE4500 Notebook";
        case PciSubDevice10B95237::SUBDEVICE_104D810F: return "VAIO PCG-U1 USB/OHCI Revision 1.0";
        case PciSubDevice10B95237::SUBDEVICE_10B95237: return "ASRock 939Dual-SATA2 Motherboard";
        case PciSubDevice10B95237::SUBDEVICE_18495237: return "ASRock 939Dual-SATA2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95237_H
