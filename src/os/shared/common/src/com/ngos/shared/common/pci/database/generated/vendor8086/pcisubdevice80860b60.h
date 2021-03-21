// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860B60_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860B60_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860B60: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282060 = 0x10282060,
    SUBDEVICE_10282061 = 0x10282061,
    SUBDEVICE_10282062 = 0x10282062,
    SUBDEVICE_10282064 = 0x10282064,
    SUBDEVICE_10282065 = 0x10282065,
    SUBDEVICE_10282066 = 0x10282066,
    SUBDEVICE_1028209E = 0x1028209E,
    SUBDEVICE_1028209F = 0x1028209F,
    SUBDEVICE_10282100 = 0x10282100,
    SUBDEVICE_10282102 = 0x10282102,
    SUBDEVICE_10282103 = 0x10282103,
    SUBDEVICE_10282104 = 0x10282104,
    SUBDEVICE_80868008 = 0x80868008,
    SUBDEVICE_80868D08 = 0x80868D08,
    SUBDEVICE_80868D1D = 0x80868D1D
};



inline const char8* enumToString(PciSubDevice80860B60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860B60::NONE:               return "NONE";
        case PciSubDevice80860B60::SUBDEVICE_10282060: return "SUBDEVICE_10282060";
        case PciSubDevice80860B60::SUBDEVICE_10282061: return "SUBDEVICE_10282061";
        case PciSubDevice80860B60::SUBDEVICE_10282062: return "SUBDEVICE_10282062";
        case PciSubDevice80860B60::SUBDEVICE_10282064: return "SUBDEVICE_10282064";
        case PciSubDevice80860B60::SUBDEVICE_10282065: return "SUBDEVICE_10282065";
        case PciSubDevice80860B60::SUBDEVICE_10282066: return "SUBDEVICE_10282066";
        case PciSubDevice80860B60::SUBDEVICE_1028209E: return "SUBDEVICE_1028209E";
        case PciSubDevice80860B60::SUBDEVICE_1028209F: return "SUBDEVICE_1028209F";
        case PciSubDevice80860B60::SUBDEVICE_10282100: return "SUBDEVICE_10282100";
        case PciSubDevice80860B60::SUBDEVICE_10282102: return "SUBDEVICE_10282102";
        case PciSubDevice80860B60::SUBDEVICE_10282103: return "SUBDEVICE_10282103";
        case PciSubDevice80860B60::SUBDEVICE_10282104: return "SUBDEVICE_10282104";
        case PciSubDevice80860B60::SUBDEVICE_80868008: return "SUBDEVICE_80868008";
        case PciSubDevice80860B60::SUBDEVICE_80868D08: return "SUBDEVICE_80868D08";
        case PciSubDevice80860B60::SUBDEVICE_80868D1D: return "SUBDEVICE_80868D1D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860B60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860B60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860B60::SUBDEVICE_10282060: return "NVMe SED MU U.2 1.6TB (P5600)";
        case PciSubDevice80860B60::SUBDEVICE_10282061: return "NVMe SED MU U.2 3.2TB (P5600)";
        case PciSubDevice80860B60::SUBDEVICE_10282062: return "NVMe SED MU U.2 6.4TB (P5600)";
        case PciSubDevice80860B60::SUBDEVICE_10282064: return "NVMe SED RI U.2 1.92TB (P5500)";
        case PciSubDevice80860B60::SUBDEVICE_10282065: return "NVMe SED RI U.2 3.84TB (P5500)";
        case PciSubDevice80860B60::SUBDEVICE_10282066: return "NVMe SED RI U.2 7.68TB (P5500)";
        case PciSubDevice80860B60::SUBDEVICE_1028209E: return "NVMe MU U.2 1.6TB (P5600)";
        case PciSubDevice80860B60::SUBDEVICE_1028209F: return "NVMe MU U.2 3.2TB (P5600)";
        case PciSubDevice80860B60::SUBDEVICE_10282100: return "NVMe MU U.2 6.4TB (P5600)";
        case PciSubDevice80860B60::SUBDEVICE_10282102: return "NVMe RI U.2 1.92TB (P5500)";
        case PciSubDevice80860B60::SUBDEVICE_10282103: return "NVMe RI U.2 3.84TB (P5500)";
        case PciSubDevice80860B60::SUBDEVICE_10282104: return "NVMe RI U.2 7.68TB (P5500)";
        case PciSubDevice80860B60::SUBDEVICE_80868008: return "NVMe Datacenter SSD [3DNAND] SE 2.5\" U.2 (P5510)";
        case PciSubDevice80860B60::SUBDEVICE_80868D08: return "NVMe Datacenter SSD [3DNAND] VE 2.5\" U.2 (P5316)";
        case PciSubDevice80860B60::SUBDEVICE_80868D1D: return "NVMe Datacenter SSD [3DNAND] VE E1.L 9.5/18mm (P5316)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860B60_H
