// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50206_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50206_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50206: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D138 = 0x19E5D138,
    SUBDEVICE_19E5D13A = 0x19E5D13A,
    SUBDEVICE_19E5D145 = 0x19E5D145
};



inline const char8* enumToString(PciSubDevice19E50206 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50206::NONE:               return "NONE";
        case PciSubDevice19E50206::SUBDEVICE_19E5D138: return "SUBDEVICE_19E5D138";
        case PciSubDevice19E50206::SUBDEVICE_19E5D13A: return "SUBDEVICE_19E5D13A";
        case PciSubDevice19E50206::SUBDEVICE_19E5D145: return "SUBDEVICE_19E5D145";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50206 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50206 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50206::SUBDEVICE_19E5D138: return "Hi1822 SP582 (2*25GE)";
        case PciSubDevice19E50206::SUBDEVICE_19E5D13A: return "Hi1822 SC381 (2*25GE)";
        case PciSubDevice19E50206::SUBDEVICE_19E5D145: return "Hi1822 SP586 (2*25GE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50206_H
