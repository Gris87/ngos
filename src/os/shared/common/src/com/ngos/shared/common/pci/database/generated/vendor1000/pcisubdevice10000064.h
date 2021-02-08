// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000064_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000064_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000064: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003030 = 0x10003030,
    SUBDEVICE_100030C0 = 0x100030C0,
    SUBDEVICE_100030D0 = 0x100030D0
};



inline const char8* enumToString(PciSubDevice10000064 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000064::NONE:               return "NONE";
        case PciSubDevice10000064::SUBDEVICE_10003030: return "SUBDEVICE_10003030";
        case PciSubDevice10000064::SUBDEVICE_100030C0: return "SUBDEVICE_100030C0";
        case PciSubDevice10000064::SUBDEVICE_100030D0: return "SUBDEVICE_100030D0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000064 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000064 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000064::SUBDEVICE_10003030: return "9200-16e 6Gb/s SAS/SATA PCIe x8 External HBA";
        case PciSubDevice10000064::SUBDEVICE_100030C0: return "SAS 9201-16i";
        case PciSubDevice10000064::SUBDEVICE_100030D0: return "9201-16e 6Gb/s SAS/SATA PCIe x8 External HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000064_H
