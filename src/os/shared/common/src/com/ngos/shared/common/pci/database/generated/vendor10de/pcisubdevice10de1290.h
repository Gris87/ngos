// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1290_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1290_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1290: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2AFA = 0x103C2AFA,
    SUBDEVICE_103C2B04 = 0x103C2B04,
    SUBDEVICE_104313AD = 0x104313AD,
    SUBDEVICE_104313CD = 0x104313CD
};



inline const char8* enumToString(PciSubDevice10DE1290 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1290::NONE:               return "NONE";
        case PciSubDevice10DE1290::SUBDEVICE_103C2AFA: return "SUBDEVICE_103C2AFA";
        case PciSubDevice10DE1290::SUBDEVICE_103C2B04: return "SUBDEVICE_103C2B04";
        case PciSubDevice10DE1290::SUBDEVICE_104313AD: return "SUBDEVICE_104313AD";
        case PciSubDevice10DE1290::SUBDEVICE_104313CD: return "SUBDEVICE_104313CD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1290 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1290 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1290::SUBDEVICE_103C2AFA: return "GeForce GT 730A";
        case PciSubDevice10DE1290::SUBDEVICE_103C2B04: return "GeForce GT 730A";
        case PciSubDevice10DE1290::SUBDEVICE_104313AD: return "GeForce GT 730M";
        case PciSubDevice10DE1290::SUBDEVICE_104313CD: return "GeForce GT 730M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1290_H
