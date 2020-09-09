// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCISUBDEVICE110A4069_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCISUBDEVICE110A4069_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice110A4069: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_110A4069 = 0x110A4069,
    SUBDEVICE_110AC069 = 0x110AC069
};



inline const char8* enumToString(PciSubDevice110A4069 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice110A4069::NONE:               return "NONE";
        case PciSubDevice110A4069::SUBDEVICE_110A4069: return "SUBDEVICE_110A4069";
        case PciSubDevice110A4069::SUBDEVICE_110AC069: return "SUBDEVICE_110AC069";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice110A4069 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice110A4069 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice110A4069::SUBDEVICE_110A4069: return "SIMATIC NET CP 5623";
        case PciSubDevice110A4069::SUBDEVICE_110AC069: return "SIMATIC NET CP 5624";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCISUBDEVICE110A4069_H
