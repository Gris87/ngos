// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000017_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000017_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000017: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009440 = 0x10009440,
    SUBDEVICE_10009442 = 0x10009442,
    SUBDEVICE_1D490500 = 0x1D490500,
    SUBDEVICE_1D490502 = 0x1D490502,
    SUBDEVICE_80863528 = 0x80863528,
    SUBDEVICE_80863529 = 0x80863529,
    SUBDEVICE_80869441 = 0x80869441
};



inline const char8* enumToString(PciSubDevice10000017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000017::NONE:               return "NONE";
        case PciSubDevice10000017::SUBDEVICE_10009440: return "SUBDEVICE_10009440";
        case PciSubDevice10000017::SUBDEVICE_10009442: return "SUBDEVICE_10009442";
        case PciSubDevice10000017::SUBDEVICE_1D490500: return "SUBDEVICE_1D490500";
        case PciSubDevice10000017::SUBDEVICE_1D490502: return "SUBDEVICE_1D490502";
        case PciSubDevice10000017::SUBDEVICE_80863528: return "SUBDEVICE_80863528";
        case PciSubDevice10000017::SUBDEVICE_80863529: return "SUBDEVICE_80863529";
        case PciSubDevice10000017::SUBDEVICE_80869441: return "SUBDEVICE_80869441";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000017::SUBDEVICE_10009440: return "MegaRAID 9440-8i";
        case PciSubDevice10000017::SUBDEVICE_10009442: return "MegaRAID 9440-4i";
        case PciSubDevice10000017::SUBDEVICE_1D490500: return "ThinkSystem RAID 530-8i PCIe 12Gb Adapter";
        case PciSubDevice10000017::SUBDEVICE_1D490502: return "ThinkSystem RAID 530-8i Dense Adapter";
        case PciSubDevice10000017::SUBDEVICE_80863528: return "Integrated RAID RMSP3LD060";
        case PciSubDevice10000017::SUBDEVICE_80863529: return "Integrated RAID RMSP3LD060";
        case PciSubDevice10000017::SUBDEVICE_80869441: return "RAID Controller RSP3WD080E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000017_H
