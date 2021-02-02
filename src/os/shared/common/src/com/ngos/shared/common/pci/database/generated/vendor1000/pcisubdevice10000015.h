// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000015_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000015_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000015: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009441 = 0x10009441,
    SUBDEVICE_10281F3C = 0x10281F3C,
    SUBDEVICE_10281F3D = 0x10281F3D,
    SUBDEVICE_1D490503 = 0x1D490503
};



inline const char8* enumToString(PciSubDevice10000015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000015::NONE:               return "NONE";
        case PciSubDevice10000015::SUBDEVICE_10009441: return "SUBDEVICE_10009441";
        case PciSubDevice10000015::SUBDEVICE_10281F3C: return "SUBDEVICE_10281F3C";
        case PciSubDevice10000015::SUBDEVICE_10281F3D: return "SUBDEVICE_10281F3D";
        case PciSubDevice10000015::SUBDEVICE_1D490503: return "SUBDEVICE_1D490503";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000015::SUBDEVICE_10009441: return "MegaRAID 9440-16i";
        case PciSubDevice10000015::SUBDEVICE_10281F3C: return "PERC H345 Adapter";
        case PciSubDevice10000015::SUBDEVICE_10281F3D: return "PERC H345 Front";
        case PciSubDevice10000015::SUBDEVICE_1D490503: return "ThinkSystem RAID 530-16i PCIe 12Gb Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000015_H
