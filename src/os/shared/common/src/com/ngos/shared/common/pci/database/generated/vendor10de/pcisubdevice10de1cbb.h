// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1CBB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1CBB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1CBB: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8429 = 0x103C8429,
    SUBDEVICE_103C842C = 0x103C842C,
    SUBDEVICE_103C842F = 0x103C842F,
    SUBDEVICE_103C8451 = 0x103C8451
};



inline const char8* enumToString(PciSubDevice10DE1CBB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1CBB::NONE:               return "NONE";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C8429: return "SUBDEVICE_103C8429";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C842C: return "SUBDEVICE_103C842C";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C842F: return "SUBDEVICE_103C842F";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C8451: return "SUBDEVICE_103C8451";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1CBB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1CBB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1CBB::SUBDEVICE_103C8429: return "P1000 [Zbook Studio G5 mobile workstation]";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C842C: return "P1000 [Zbook 15 G5 mobile workstation]";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C842F: return "P1000 [Zbook 17 G5 mobile workstation]";
        case PciSubDevice10DE1CBB::SUBDEVICE_103C8451: return "P1000 [Zbook Studio x360 G5 mobile workstation]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1CBB_H
