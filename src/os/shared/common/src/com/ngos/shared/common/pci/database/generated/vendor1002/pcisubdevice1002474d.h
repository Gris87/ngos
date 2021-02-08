// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002474D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002474D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002474D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020004 = 0x10020004,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10020080 = 0x10020080,
    SUBDEVICE_10020084 = 0x10020084,
    SUBDEVICE_1002474D = 0x1002474D,
    SUBDEVICE_1033806A = 0x1033806A
};



inline const char8* enumToString(PciSubDevice1002474D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002474D::NONE:               return "NONE";
        case PciSubDevice1002474D::SUBDEVICE_10020004: return "SUBDEVICE_10020004";
        case PciSubDevice1002474D::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice1002474D::SUBDEVICE_10020080: return "SUBDEVICE_10020080";
        case PciSubDevice1002474D::SUBDEVICE_10020084: return "SUBDEVICE_10020084";
        case PciSubDevice1002474D::SUBDEVICE_1002474D: return "SUBDEVICE_1002474D";
        case PciSubDevice1002474D::SUBDEVICE_1033806A: return "SUBDEVICE_1033806A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002474D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002474D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002474D::SUBDEVICE_10020004: return "Xpert 98 RXL AGP 2X";
        case PciSubDevice1002474D::SUBDEVICE_10020008: return "Xpert 98 RXL AGP 2X";
        case PciSubDevice1002474D::SUBDEVICE_10020080: return "Rage XL AGP 2X";
        case PciSubDevice1002474D::SUBDEVICE_10020084: return "Xpert 98 AGP 2X";
        case PciSubDevice1002474D::SUBDEVICE_1002474D: return "Rage XL AGP";
        case PciSubDevice1002474D::SUBDEVICE_1033806A: return "Rage XL AGP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002474D_H
