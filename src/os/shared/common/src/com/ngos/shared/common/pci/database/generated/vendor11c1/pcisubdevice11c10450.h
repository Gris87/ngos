// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10450_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10450_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10450: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103380A8 = 0x103380A8,
    SUBDEVICE_144F4005 = 0x144F4005,
    SUBDEVICE_14680450 = 0x14680450
};



inline const char8* enumToString(PciSubDevice11C10450 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10450::NONE:               return "NONE";
        case PciSubDevice11C10450::SUBDEVICE_103380A8: return "SUBDEVICE_103380A8";
        case PciSubDevice11C10450::SUBDEVICE_144F4005: return "SUBDEVICE_144F4005";
        case PciSubDevice11C10450::SUBDEVICE_14680450: return "SUBDEVICE_14680450";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10450 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10450 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10450::SUBDEVICE_103380A8: return "Versa Note Vxi";
        case PciSubDevice11C10450::SUBDEVICE_144F4005: return "Magnia SG20";
        case PciSubDevice11C10450::SUBDEVICE_14680450: return "Evo N600c";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10450_H
