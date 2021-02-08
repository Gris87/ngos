// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00F2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00F2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE00F2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15541194 = 0x15541194,
    SUBDEVICE_1682211C = 0x1682211C
};



inline const char8* enumToString(PciSubDevice10DE00F2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00F2::NONE:               return "NONE";
        case PciSubDevice10DE00F2::SUBDEVICE_15541194: return "SUBDEVICE_15541194";
        case PciSubDevice10DE00F2::SUBDEVICE_1682211C: return "SUBDEVICE_1682211C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE00F2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE00F2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00F2::SUBDEVICE_15541194: return "PixelView PV-N43AT (256KD)";
        case PciSubDevice10DE00F2::SUBDEVICE_1682211C: return "GeForce 6600 256MB DDR DUAL DVI TV";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00F2_H
