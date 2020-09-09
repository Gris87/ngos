// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002554D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002554D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002554D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020322 = 0x10020322,
    SUBDEVICE_14582124 = 0x14582124
};



inline const char8* enumToString(PciSubDevice1002554D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002554D::NONE:               return "NONE";
        case PciSubDevice1002554D::SUBDEVICE_10020322: return "SUBDEVICE_10020322";
        case PciSubDevice1002554D::SUBDEVICE_14582124: return "SUBDEVICE_14582124";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002554D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002554D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002554D::SUBDEVICE_10020322: return "All-In-Wonder X800 XL";
        case PciSubDevice1002554D::SUBDEVICE_14582124: return "GV-R80L256V-B (AGP)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002554D_H
