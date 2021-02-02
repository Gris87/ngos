// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0171_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0171_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0171: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B00002 = 0x10B00002,
    SUBDEVICE_10DE0008 = 0x10DE0008,
    SUBDEVICE_14628661 = 0x14628661,
    SUBDEVICE_14628730 = 0x14628730,
    SUBDEVICE_14628743 = 0x14628743,
    SUBDEVICE_14628852 = 0x14628852,
    SUBDEVICE_147B8F00 = 0x147B8F00
};



inline const char8* enumToString(PciSubDevice10DE0171 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0171::NONE:               return "NONE";
        case PciSubDevice10DE0171::SUBDEVICE_10B00002: return "SUBDEVICE_10B00002";
        case PciSubDevice10DE0171::SUBDEVICE_10DE0008: return "SUBDEVICE_10DE0008";
        case PciSubDevice10DE0171::SUBDEVICE_14628661: return "SUBDEVICE_14628661";
        case PciSubDevice10DE0171::SUBDEVICE_14628730: return "SUBDEVICE_14628730";
        case PciSubDevice10DE0171::SUBDEVICE_14628743: return "SUBDEVICE_14628743";
        case PciSubDevice10DE0171::SUBDEVICE_14628852: return "SUBDEVICE_14628852";
        case PciSubDevice10DE0171::SUBDEVICE_147B8F00: return "SUBDEVICE_147B8F00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0171 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0171 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0171::SUBDEVICE_10B00002: return "Gainward Pro/600 TV";
        case PciSubDevice10DE0171::SUBDEVICE_10DE0008: return "Apple OEM GeForce4 MX 440";
        case PciSubDevice10DE0171::SUBDEVICE_14628661: return "G4MX440-VTP";
        case PciSubDevice10DE0171::SUBDEVICE_14628730: return "MX440SES-T (MS-8873)";
        case PciSubDevice10DE0171::SUBDEVICE_14628743: return "MS-8874";
        case PciSubDevice10DE0171::SUBDEVICE_14628852: return "GeForce4 MX440 PCI";
        case PciSubDevice10DE0171::SUBDEVICE_147B8F00: return "Abit Siluro GeForce4MX440";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0171_H
