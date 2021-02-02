// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860600_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860600_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860600: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860136 = 0x80860136,
    SUBDEVICE_808601AF = 0x808601AF,
    SUBDEVICE_808601C1 = 0x808601C1,
    SUBDEVICE_808601F7 = 0x808601F7
};



inline const char8* enumToString(PciSubDevice80860600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860600::NONE:               return "NONE";
        case PciSubDevice80860600::SUBDEVICE_80860136: return "SUBDEVICE_80860136";
        case PciSubDevice80860600::SUBDEVICE_808601AF: return "SUBDEVICE_808601AF";
        case PciSubDevice80860600::SUBDEVICE_808601C1: return "SUBDEVICE_808601C1";
        case PciSubDevice80860600::SUBDEVICE_808601F7: return "SUBDEVICE_808601F7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860600::SUBDEVICE_80860136: return "SRCU31L";
        case PciSubDevice80860600::SUBDEVICE_808601AF: return "SRCZCR";
        case PciSubDevice80860600::SUBDEVICE_808601C1: return "ICP Vortex GDT8546RZ";
        case PciSubDevice80860600::SUBDEVICE_808601F7: return "SCRbad_uint32";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860600_H
