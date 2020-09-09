// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000010: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E114040 = 0x0E114040,
    SUBDEVICE_0E114048 = 0x0E114048,
    SUBDEVICE_10001000 = 0x10001000
};



inline const char8* enumToString(PciSubDevice10000010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000010::NONE:               return "NONE";
        case PciSubDevice10000010::SUBDEVICE_0E114040: return "SUBDEVICE_0E114040";
        case PciSubDevice10000010::SUBDEVICE_0E114048: return "SUBDEVICE_0E114048";
        case PciSubDevice10000010::SUBDEVICE_10001000: return "SUBDEVICE_10001000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000010::SUBDEVICE_0E114040: return "Integrated Smart Array Controller";
        case PciSubDevice10000010::SUBDEVICE_0E114048: return "RAID LC2 Controller";
        case PciSubDevice10000010::SUBDEVICE_10001000: return "53C1510 PCI to Dual Channel Wide Ultra2 SCSI Controller (Intelligent mode)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000010_H
