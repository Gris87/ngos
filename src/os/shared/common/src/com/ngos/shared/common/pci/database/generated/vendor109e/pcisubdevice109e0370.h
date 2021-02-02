// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0370_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0370_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice109E0370: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_18511850 = 0x18511850,
    SUBDEVICE_18511851 = 0x18511851,
    SUBDEVICE_18521852 = 0x18521852
};



inline const char8* enumToString(PciSubDevice109E0370 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E0370::NONE:               return "NONE";
        case PciSubDevice109E0370::SUBDEVICE_18511850: return "SUBDEVICE_18511850";
        case PciSubDevice109E0370::SUBDEVICE_18511851: return "SUBDEVICE_18511851";
        case PciSubDevice109E0370::SUBDEVICE_18521852: return "SUBDEVICE_18521852";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice109E0370 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice109E0370 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E0370::SUBDEVICE_18511850: return "FlyVideo'98";
        case PciSubDevice109E0370::SUBDEVICE_18511851: return "FlyVideo'98 EZ - video";
        case PciSubDevice109E0370::SUBDEVICE_18521852: return "FlyVideo'98 (with FM Tuner)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0370_H
