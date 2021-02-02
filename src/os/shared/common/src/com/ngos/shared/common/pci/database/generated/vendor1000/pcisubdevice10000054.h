// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000054_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000054_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000054: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F04 = 0x10281F04,
    SUBDEVICE_10281F05 = 0x10281F05,
    SUBDEVICE_10281F06 = 0x10281F06,
    SUBDEVICE_10281F07 = 0x10281F07,
    SUBDEVICE_10281F08 = 0x10281F08,
    SUBDEVICE_10281F09 = 0x10281F09,
    SUBDEVICE_15AD1976 = 0x15AD1976
};



inline const char8* enumToString(PciSubDevice10000054 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000054::NONE:               return "NONE";
        case PciSubDevice10000054::SUBDEVICE_10281F04: return "SUBDEVICE_10281F04";
        case PciSubDevice10000054::SUBDEVICE_10281F05: return "SUBDEVICE_10281F05";
        case PciSubDevice10000054::SUBDEVICE_10281F06: return "SUBDEVICE_10281F06";
        case PciSubDevice10000054::SUBDEVICE_10281F07: return "SUBDEVICE_10281F07";
        case PciSubDevice10000054::SUBDEVICE_10281F08: return "SUBDEVICE_10281F08";
        case PciSubDevice10000054::SUBDEVICE_10281F09: return "SUBDEVICE_10281F09";
        case PciSubDevice10000054::SUBDEVICE_15AD1976: return "SUBDEVICE_15AD1976";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000054 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000054 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000054::SUBDEVICE_10281F04: return "SAS 5/E Adapter Controller";
        case PciSubDevice10000054::SUBDEVICE_10281F05: return "SAS 5/i Adapter Controller";
        case PciSubDevice10000054::SUBDEVICE_10281F06: return "SAS 5/i Integrated Controller";
        case PciSubDevice10000054::SUBDEVICE_10281F07: return "SAS 5/iR Integrated RAID Controller";
        case PciSubDevice10000054::SUBDEVICE_10281F08: return "SAS 5/iR Integrated RAID Controller";
        case PciSubDevice10000054::SUBDEVICE_10281F09: return "SAS 5/iR Adapter RAID Controller";
        case PciSubDevice10000054::SUBDEVICE_15AD1976: return "SAS Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000054_H
