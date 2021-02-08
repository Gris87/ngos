// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860102_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860102_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860102: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804AA = 0x102804AA,
    SUBDEVICE_10430102 = 0x10430102
};



inline const char8* enumToString(PciSubDevice80860102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860102::NONE:               return "NONE";
        case PciSubDevice80860102::SUBDEVICE_102804AA: return "SUBDEVICE_102804AA";
        case PciSubDevice80860102::SUBDEVICE_10430102: return "SUBDEVICE_10430102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860102::SUBDEVICE_102804AA: return "XPS 8300";
        case PciSubDevice80860102::SUBDEVICE_10430102: return "P8H67 Series Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860102_H
