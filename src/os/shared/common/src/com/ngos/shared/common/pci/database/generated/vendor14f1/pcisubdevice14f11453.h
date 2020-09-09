// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11453_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11453_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F11453: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13E00240 = 0x13E00240,
    SUBDEVICE_13E00250 = 0x13E00250,
    SUBDEVICE_144F1502 = 0x144F1502,
    SUBDEVICE_144F1503 = 0x144F1503
};



inline const char8* enumToString(PciSubDevice14F11453 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11453::NONE:               return "NONE";
        case PciSubDevice14F11453::SUBDEVICE_13E00240: return "SUBDEVICE_13E00240";
        case PciSubDevice14F11453::SUBDEVICE_13E00250: return "SUBDEVICE_13E00250";
        case PciSubDevice14F11453::SUBDEVICE_144F1502: return "SUBDEVICE_144F1502";
        case PciSubDevice14F11453::SUBDEVICE_144F1503: return "SUBDEVICE_144F1503";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F11453 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F11453 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11453::SUBDEVICE_13E00240: return "IBM";
        case PciSubDevice14F11453::SUBDEVICE_13E00250: return "IBM";
        case PciSubDevice14F11453::SUBDEVICE_144F1502: return "IBM P95-DF (1)";
        case PciSubDevice14F11453::SUBDEVICE_144F1503: return "IBM P95-DF (2)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11453_H
