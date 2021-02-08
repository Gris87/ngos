// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0244_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0244_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0244: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C30B5 = 0x103C30B5,
    SUBDEVICE_103C30B7 = 0x103C30B7,
    SUBDEVICE_10DE0244 = 0x10DE0244
};



inline const char8* enumToString(PciSubDevice10DE0244 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0244::NONE:               return "NONE";
        case PciSubDevice10DE0244::SUBDEVICE_103C30B5: return "SUBDEVICE_103C30B5";
        case PciSubDevice10DE0244::SUBDEVICE_103C30B7: return "SUBDEVICE_103C30B7";
        case PciSubDevice10DE0244::SUBDEVICE_10DE0244: return "SUBDEVICE_10DE0244";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0244 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0244 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0244::SUBDEVICE_103C30B5: return "Presario V3242AU";
        case PciSubDevice10DE0244::SUBDEVICE_103C30B7: return "Presario V6133CL";
        case PciSubDevice10DE0244::SUBDEVICE_10DE0244: return "GeForce Go 6150";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0244_H
