// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E51822_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E51822_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E51822: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D129 = 0x19E5D129,
    SUBDEVICE_19E5D136 = 0x19E5D136,
    SUBDEVICE_19E5D141 = 0x19E5D141,
    SUBDEVICE_19E5D146 = 0x19E5D146
};



inline const char8* enumToString(PciSubDevice19E51822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E51822::NONE:               return "NONE";
        case PciSubDevice19E51822::SUBDEVICE_19E5D129: return "SUBDEVICE_19E5D129";
        case PciSubDevice19E51822::SUBDEVICE_19E5D136: return "SUBDEVICE_19E5D136";
        case PciSubDevice19E51822::SUBDEVICE_19E5D141: return "SUBDEVICE_19E5D141";
        case PciSubDevice19E51822::SUBDEVICE_19E5D146: return "SUBDEVICE_19E5D146";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E51822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E51822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E51822::SUBDEVICE_19E5D129: return "Hi1822 SP570 (4*25GE)";
        case PciSubDevice19E51822::SUBDEVICE_19E5D136: return "Hi1822 SP580 (4*25GE)";
        case PciSubDevice19E51822::SUBDEVICE_19E5D141: return "Hi1822 SP583 (4*25GE)";
        case PciSubDevice19E51822::SUBDEVICE_19E5D146: return "Hi1822 SP585 (4*25GE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E51822_H
