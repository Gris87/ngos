// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice9005028B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050200 = 0x90050200,
    SUBDEVICE_90050201 = 0x90050201,
    SUBDEVICE_90050300 = 0x90050300,
    SUBDEVICE_90050301 = 0x90050301,
    SUBDEVICE_90050302 = 0x90050302,
    SUBDEVICE_90050310 = 0x90050310,
    SUBDEVICE_90050311 = 0x90050311,
    SUBDEVICE_90050400 = 0x90050400,
    SUBDEVICE_90050401 = 0x90050401,
    SUBDEVICE_90050403 = 0x90050403
};



inline const char8* enumToString(PciSubDevice9005028B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005028B::NONE:               return "NONE";
        case PciSubDevice9005028B::SUBDEVICE_90050200: return "SUBDEVICE_90050200";
        case PciSubDevice9005028B::SUBDEVICE_90050201: return "SUBDEVICE_90050201";
        case PciSubDevice9005028B::SUBDEVICE_90050300: return "SUBDEVICE_90050300";
        case PciSubDevice9005028B::SUBDEVICE_90050301: return "SUBDEVICE_90050301";
        case PciSubDevice9005028B::SUBDEVICE_90050302: return "SUBDEVICE_90050302";
        case PciSubDevice9005028B::SUBDEVICE_90050310: return "SUBDEVICE_90050310";
        case PciSubDevice9005028B::SUBDEVICE_90050311: return "SUBDEVICE_90050311";
        case PciSubDevice9005028B::SUBDEVICE_90050400: return "SUBDEVICE_90050400";
        case PciSubDevice9005028B::SUBDEVICE_90050401: return "SUBDEVICE_90050401";
        case PciSubDevice9005028B::SUBDEVICE_90050403: return "SUBDEVICE_90050403";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice9005028B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice9005028B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005028B::SUBDEVICE_90050200: return "Series 6 Entry Level - ASR-6405E - 4 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050201: return "Series 6 Entry Level - ASR-6805E - 8 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050300: return "Series 6 - ASR-6405 - 4 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050301: return "Series 6 - ASR-6805 - 8 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050302: return "Series 6 - ASR-6445 - 4 internal and 4 external 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050310: return "Series 6 Connectors on Top - ASR-6405T - 4 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050311: return "Series 6 Connectors on Top - ASR-6805T - 8 internal 6G SAS";
        case PciSubDevice9005028B::SUBDEVICE_90050400: return "Series 6 - ASR-61205 - 12 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050401: return "Series 6 - ASR-61605 - 16 internal 6G SAS ports";
        case PciSubDevice9005028B::SUBDEVICE_90050403: return "Series 6 - ASR-62405 - 24 internal 6G SAS ports";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028B_H
