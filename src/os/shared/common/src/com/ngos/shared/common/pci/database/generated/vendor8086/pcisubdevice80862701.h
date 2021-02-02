// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862701_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862701_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862701: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282000 = 0x10282000,
    SUBDEVICE_10282001 = 0x10282001,
    SUBDEVICE_10282002 = 0x10282002,
    SUBDEVICE_1028200A = 0x1028200A,
    SUBDEVICE_80863904 = 0x80863904,
    SUBDEVICE_80863905 = 0x80863905
};



inline const char8* enumToString(PciSubDevice80862701 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862701::NONE:               return "NONE";
        case PciSubDevice80862701::SUBDEVICE_10282000: return "SUBDEVICE_10282000";
        case PciSubDevice80862701::SUBDEVICE_10282001: return "SUBDEVICE_10282001";
        case PciSubDevice80862701::SUBDEVICE_10282002: return "SUBDEVICE_10282002";
        case PciSubDevice80862701::SUBDEVICE_1028200A: return "SUBDEVICE_1028200A";
        case PciSubDevice80862701::SUBDEVICE_80863904: return "SUBDEVICE_80863904";
        case PciSubDevice80862701::SUBDEVICE_80863905: return "SUBDEVICE_80863905";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862701 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862701 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862701::SUBDEVICE_10282000: return "Express Flash NVMe [Optane] 375GB 2.5\" U.2 (P4800X)";
        case PciSubDevice80862701::SUBDEVICE_10282001: return "Express Flash NVMe [Optane] 750GB 2.5\" U.2 (P4800X)";
        case PciSubDevice80862701::SUBDEVICE_10282002: return "Express Flash NVMe [Optane] 750GB AIC (P4800X)";
        case PciSubDevice80862701::SUBDEVICE_1028200A: return "Express Flash NVMe [Optane] 375GB AIC (P4800X)";
        case PciSubDevice80862701::SUBDEVICE_80863904: return "NVMe Datacenter SSD [Optane] x4 AIC (P4800X)";
        case PciSubDevice80862701::SUBDEVICE_80863905: return "NVMe Datacenter SSD [Optane] 15mm 2.5\" U.2 (P4800X)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862701_H
