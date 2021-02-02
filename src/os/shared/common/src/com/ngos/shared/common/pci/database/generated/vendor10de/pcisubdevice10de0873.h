// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0873_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0873_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0873: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104319B4 = 0x104319B4,
    SUBDEVICE_10431C12 = 0x10431C12,
    SUBDEVICE_10431C52 = 0x10431C52
};



inline const char8* enumToString(PciSubDevice10DE0873 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0873::NONE:               return "NONE";
        case PciSubDevice10DE0873::SUBDEVICE_104319B4: return "SUBDEVICE_104319B4";
        case PciSubDevice10DE0873::SUBDEVICE_10431C12: return "SUBDEVICE_10431C12";
        case PciSubDevice10DE0873::SUBDEVICE_10431C52: return "SUBDEVICE_10431C52";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0873 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0873 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0873::SUBDEVICE_104319B4: return "GeForce G102M";
        case PciSubDevice10DE0873::SUBDEVICE_10431C12: return "GeForce G102M";
        case PciSubDevice10DE0873::SUBDEVICE_10431C52: return "GeForce G205M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0873_H
