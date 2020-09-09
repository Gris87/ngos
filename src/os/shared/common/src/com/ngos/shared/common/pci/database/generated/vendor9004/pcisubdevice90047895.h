// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90047895_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90047895_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90047895: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90047890 = 0x90047890,
    SUBDEVICE_90047891 = 0x90047891,
    SUBDEVICE_90047892 = 0x90047892,
    SUBDEVICE_90047894 = 0x90047894,
    SUBDEVICE_90047895 = 0x90047895,
    SUBDEVICE_90047896 = 0x90047896,
    SUBDEVICE_90047897 = 0x90047897
};



inline const char8* enumToString(PciSubDevice90047895 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90047895::NONE:               return "NONE";
        case PciSubDevice90047895::SUBDEVICE_90047890: return "SUBDEVICE_90047890";
        case PciSubDevice90047895::SUBDEVICE_90047891: return "SUBDEVICE_90047891";
        case PciSubDevice90047895::SUBDEVICE_90047892: return "SUBDEVICE_90047892";
        case PciSubDevice90047895::SUBDEVICE_90047894: return "SUBDEVICE_90047894";
        case PciSubDevice90047895::SUBDEVICE_90047895: return "SUBDEVICE_90047895";
        case PciSubDevice90047895::SUBDEVICE_90047896: return "SUBDEVICE_90047896";
        case PciSubDevice90047895::SUBDEVICE_90047897: return "SUBDEVICE_90047897";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90047895 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90047895 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90047895::SUBDEVICE_90047890: return "AHA-2940U/2940UW Dual AHA-394xAU/AUW/AUWD AIC-7895B";
        case PciSubDevice90047895::SUBDEVICE_90047891: return "AHA-2940U/2940UW Dual";
        case PciSubDevice90047895::SUBDEVICE_90047892: return "AHA-3940AU/AUW/AUWD/UWD";
        case PciSubDevice90047895::SUBDEVICE_90047894: return "AHA-3944AUWD";
        case PciSubDevice90047895::SUBDEVICE_90047895: return "AHA-2940U/2940UW Dual AHA-394xAU/AUW/AUWD AIC-7895B";
        case PciSubDevice90047895::SUBDEVICE_90047896: return "AHA-2940U/2940UW Dual AHA-394xAU/AUW/AUWD AIC-7895B";
        case PciSubDevice90047895::SUBDEVICE_90047897: return "AHA-2940U/2940UW Dual AHA-394xAU/AUW/AUWD AIC-7895B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90047895_H
