// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10950649_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10950649_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10950649: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11005D = 0x0E11005D,
    SUBDEVICE_0E11007E = 0x0E11007E,
    SUBDEVICE_101E0649 = 0x101E0649
};



inline const char8* enumToString(PciSubDevice10950649 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10950649::NONE:               return "NONE";
        case PciSubDevice10950649::SUBDEVICE_0E11005D: return "SUBDEVICE_0E11005D";
        case PciSubDevice10950649::SUBDEVICE_0E11007E: return "SUBDEVICE_0E11007E";
        case PciSubDevice10950649::SUBDEVICE_101E0649: return "SUBDEVICE_101E0649";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10950649 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10950649 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10950649::SUBDEVICE_0E11005D: return "Integrated Ultra ATA-100 Dual Channel Controller";
        case PciSubDevice10950649::SUBDEVICE_0E11007E: return "Integrated Ultra ATA-100 IDE RAID Controller";
        case PciSubDevice10950649::SUBDEVICE_101E0649: return "AMI MegaRAID IDE 100 Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10950649_H
