// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025144_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025144_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025144: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10020009 = 0x10020009,
    SUBDEVICE_1002000A = 0x1002000A,
    SUBDEVICE_1002001A = 0x1002001A,
    SUBDEVICE_10020029 = 0x10020029,
    SUBDEVICE_10020038 = 0x10020038,
    SUBDEVICE_10020039 = 0x10020039,
    SUBDEVICE_1002008A = 0x1002008A,
    SUBDEVICE_100200BA = 0x100200BA,
    SUBDEVICE_10020139 = 0x10020139,
    SUBDEVICE_1002028A = 0x1002028A,
    SUBDEVICE_100202AA = 0x100202AA,
    SUBDEVICE_1002053A = 0x1002053A
};



inline const char8* enumToString(PciSubDevice10025144 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025144::NONE:               return "NONE";
        case PciSubDevice10025144::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice10025144::SUBDEVICE_10020009: return "SUBDEVICE_10020009";
        case PciSubDevice10025144::SUBDEVICE_1002000A: return "SUBDEVICE_1002000A";
        case PciSubDevice10025144::SUBDEVICE_1002001A: return "SUBDEVICE_1002001A";
        case PciSubDevice10025144::SUBDEVICE_10020029: return "SUBDEVICE_10020029";
        case PciSubDevice10025144::SUBDEVICE_10020038: return "SUBDEVICE_10020038";
        case PciSubDevice10025144::SUBDEVICE_10020039: return "SUBDEVICE_10020039";
        case PciSubDevice10025144::SUBDEVICE_1002008A: return "SUBDEVICE_1002008A";
        case PciSubDevice10025144::SUBDEVICE_100200BA: return "SUBDEVICE_100200BA";
        case PciSubDevice10025144::SUBDEVICE_10020139: return "SUBDEVICE_10020139";
        case PciSubDevice10025144::SUBDEVICE_1002028A: return "SUBDEVICE_1002028A";
        case PciSubDevice10025144::SUBDEVICE_100202AA: return "SUBDEVICE_100202AA";
        case PciSubDevice10025144::SUBDEVICE_1002053A: return "SUBDEVICE_1002053A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025144 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025144 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025144::SUBDEVICE_10020008: return "Radeon 7000/Radeon VE";
        case PciSubDevice10025144::SUBDEVICE_10020009: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_1002000A: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_1002001A: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_10020029: return "Radeon AIW";
        case PciSubDevice10025144::SUBDEVICE_10020038: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_10020039: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_1002008A: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_100200BA: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_10020139: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_1002028A: return "Radeon 7000/Radeon";
        case PciSubDevice10025144::SUBDEVICE_100202AA: return "Radeon AIW";
        case PciSubDevice10025144::SUBDEVICE_1002053A: return "Radeon 7000/Radeon";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025144_H
