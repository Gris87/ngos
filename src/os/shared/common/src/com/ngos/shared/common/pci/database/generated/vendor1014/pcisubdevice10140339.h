// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140339_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140339_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10140339: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014030A = 0x1014030A,
    SUBDEVICE_1014033A = 0x1014033A,
    SUBDEVICE_1014035C = 0x1014035C,
    SUBDEVICE_10140360 = 0x10140360
};



inline const char8* enumToString(PciSubDevice10140339 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140339::NONE:               return "NONE";
        case PciSubDevice10140339::SUBDEVICE_1014030A: return "SUBDEVICE_1014030A";
        case PciSubDevice10140339::SUBDEVICE_1014033A: return "SUBDEVICE_1014033A";
        case PciSubDevice10140339::SUBDEVICE_1014035C: return "SUBDEVICE_1014035C";
        case PciSubDevice10140339::SUBDEVICE_10140360: return "SUBDEVICE_10140360";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10140339 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10140339 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140339::SUBDEVICE_1014030A: return "PCIe 3Gb SAS RAID Adapter (574E)";
        case PciSubDevice10140339::SUBDEVICE_1014033A: return "PCIe 3Gb SAS Adapter (57B3)";
        case PciSubDevice10140339::SUBDEVICE_1014035C: return "PCIe x8 Internal 3Gb SAS adapter (57CC)";
        case PciSubDevice10140339::SUBDEVICE_10140360: return "PCI-E Auxiliary Cache Adapter (57B7)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140339_H
