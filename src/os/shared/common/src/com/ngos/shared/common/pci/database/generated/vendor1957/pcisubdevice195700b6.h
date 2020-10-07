// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE195700B6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE195700B6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice195700B6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1A561101 = 0x1A561101
};



inline const char8* enumToString(PciSubDevice195700B6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice195700B6::NONE:               return "NONE";
        case PciSubDevice195700B6::SUBDEVICE_1A561101: return "SUBDEVICE_1A561101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice195700B6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice195700B6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice195700B6::SUBDEVICE_1A561101: return "Bigfoot Killer Xeno Pro Gigabit Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE195700B6_H
