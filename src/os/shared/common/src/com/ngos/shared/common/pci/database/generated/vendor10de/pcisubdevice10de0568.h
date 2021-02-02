// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0568_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0568_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0568: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2A9E = 0x103C2A9E,
    SUBDEVICE_104382E8 = 0x104382E8,
    SUBDEVICE_14627508 = 0x14627508,
    SUBDEVICE_18490568 = 0x18490568
};



inline const char8* enumToString(PciSubDevice10DE0568 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0568::NONE:               return "NONE";
        case PciSubDevice10DE0568::SUBDEVICE_103C2A9E: return "SUBDEVICE_103C2A9E";
        case PciSubDevice10DE0568::SUBDEVICE_104382E8: return "SUBDEVICE_104382E8";
        case PciSubDevice10DE0568::SUBDEVICE_14627508: return "SUBDEVICE_14627508";
        case PciSubDevice10DE0568::SUBDEVICE_18490568: return "SUBDEVICE_18490568";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0568 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0568 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0568::SUBDEVICE_103C2A9E: return "Pavilion p6310f";
        case PciSubDevice10DE0568::SUBDEVICE_104382E8: return "M3N72-D";
        case PciSubDevice10DE0568::SUBDEVICE_14627508: return "K9N2GM-FIH";
        case PciSubDevice10DE0568::SUBDEVICE_18490568: return "K10N78FullHD-hSLI R3.0 Memory Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0568_H
