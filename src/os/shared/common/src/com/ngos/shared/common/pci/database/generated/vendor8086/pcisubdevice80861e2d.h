// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E2D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E2D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861E2D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043108D = 0x1043108D,
    SUBDEVICE_10431477 = 0x10431477,
    SUBDEVICE_10431517 = 0x10431517,
    SUBDEVICE_104384CA = 0x104384CA,
    SUBDEVICE_10CF16E8 = 0x10CF16E8,
    SUBDEVICE_144DC652 = 0x144DC652,
    SUBDEVICE_18491E2D = 0x18491E2D
};



inline const char8* enumToString(PciSubDevice80861E2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861E2D::NONE:               return "NONE";
        case PciSubDevice80861E2D::SUBDEVICE_1043108D: return "SUBDEVICE_1043108D";
        case PciSubDevice80861E2D::SUBDEVICE_10431477: return "SUBDEVICE_10431477";
        case PciSubDevice80861E2D::SUBDEVICE_10431517: return "SUBDEVICE_10431517";
        case PciSubDevice80861E2D::SUBDEVICE_104384CA: return "SUBDEVICE_104384CA";
        case PciSubDevice80861E2D::SUBDEVICE_10CF16E8: return "SUBDEVICE_10CF16E8";
        case PciSubDevice80861E2D::SUBDEVICE_144DC652: return "SUBDEVICE_144DC652";
        case PciSubDevice80861E2D::SUBDEVICE_18491E2D: return "SUBDEVICE_18491E2D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861E2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861E2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861E2D::SUBDEVICE_1043108D: return "VivoBook X202EV";
        case PciSubDevice80861E2D::SUBDEVICE_10431477: return "N56VZ";
        case PciSubDevice80861E2D::SUBDEVICE_10431517: return "Zenbook Prime UX31A";
        case PciSubDevice80861E2D::SUBDEVICE_104384CA: return "P8 series motherboard";
        case PciSubDevice80861E2D::SUBDEVICE_10CF16E8: return "LIFEBOOK E752";
        case PciSubDevice80861E2D::SUBDEVICE_144DC652: return "NP300E5C series laptop";
        case PciSubDevice80861E2D::SUBDEVICE_18491E2D: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E2D_H
