// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000058_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000058_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000058: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003140 = 0x10003140,
    SUBDEVICE_1028021D = 0x1028021D,
    SUBDEVICE_10281F0E = 0x10281F0E,
    SUBDEVICE_10281F0F = 0x10281F0F,
    SUBDEVICE_10281F10 = 0x10281F10,
    SUBDEVICE_103C3229 = 0x103C3229
};



inline const char8* enumToString(PciSubDevice10000058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000058::NONE:               return "NONE";
        case PciSubDevice10000058::SUBDEVICE_10003140: return "SUBDEVICE_10003140";
        case PciSubDevice10000058::SUBDEVICE_1028021D: return "SUBDEVICE_1028021D";
        case PciSubDevice10000058::SUBDEVICE_10281F0E: return "SUBDEVICE_10281F0E";
        case PciSubDevice10000058::SUBDEVICE_10281F0F: return "SUBDEVICE_10281F0F";
        case PciSubDevice10000058::SUBDEVICE_10281F10: return "SUBDEVICE_10281F10";
        case PciSubDevice10000058::SUBDEVICE_103C3229: return "SUBDEVICE_103C3229";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000058::SUBDEVICE_10003140: return "SAS3081E-R 8-Port SAS/SATA Host Bus Adapter";
        case PciSubDevice10000058::SUBDEVICE_1028021D: return "SAS 6/iR Integrated Workstations RAID Controller";
        case PciSubDevice10000058::SUBDEVICE_10281F0E: return "SAS 6/iR Adapter RAID Controller";
        case PciSubDevice10000058::SUBDEVICE_10281F0F: return "SAS 6/iR Integrated Blades RAID Controller";
        case PciSubDevice10000058::SUBDEVICE_10281F10: return "SAS 6/iR Integrated RAID Controller";
        case PciSubDevice10000058::SUBDEVICE_103C3229: return "SC44Ge Host Bus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000058_H
