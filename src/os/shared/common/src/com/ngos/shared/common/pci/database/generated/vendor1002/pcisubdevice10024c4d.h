// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C4D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C4D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C4D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B111 = 0x0E11B111,
    SUBDEVICE_0E11B160 = 0x0E11B160,
    SUBDEVICE_10020084 = 0x10020084,
    SUBDEVICE_10140154 = 0x10140154,
    SUBDEVICE_102800AA = 0x102800AA,
    SUBDEVICE_102800BB = 0x102800BB,
    SUBDEVICE_1179FF00 = 0x1179FF00,
    SUBDEVICE_13BD1019 = 0x13BD1019
};



inline const char8* enumToString(PciSubDevice10024C4D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C4D::NONE:               return "NONE";
        case PciSubDevice10024C4D::SUBDEVICE_0E11B111: return "SUBDEVICE_0E11B111";
        case PciSubDevice10024C4D::SUBDEVICE_0E11B160: return "SUBDEVICE_0E11B160";
        case PciSubDevice10024C4D::SUBDEVICE_10020084: return "SUBDEVICE_10020084";
        case PciSubDevice10024C4D::SUBDEVICE_10140154: return "SUBDEVICE_10140154";
        case PciSubDevice10024C4D::SUBDEVICE_102800AA: return "SUBDEVICE_102800AA";
        case PciSubDevice10024C4D::SUBDEVICE_102800BB: return "SUBDEVICE_102800BB";
        case PciSubDevice10024C4D::SUBDEVICE_1179FF00: return "SUBDEVICE_1179FF00";
        case PciSubDevice10024C4D::SUBDEVICE_13BD1019: return "SUBDEVICE_13BD1019";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C4D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C4D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C4D::SUBDEVICE_0E11B111: return "Armada M700";
        case PciSubDevice10024C4D::SUBDEVICE_0E11B160: return "Armada E500";
        case PciSubDevice10024C4D::SUBDEVICE_10020084: return "Xpert 98 AGP 2X (Mobility)";
        case PciSubDevice10024C4D::SUBDEVICE_10140154: return "ThinkPad A20m/A21m";
        case PciSubDevice10024C4D::SUBDEVICE_102800AA: return "Latitude CPt";
        case PciSubDevice10024C4D::SUBDEVICE_102800BB: return "Latitude CPx";
        case PciSubDevice10024C4D::SUBDEVICE_1179FF00: return "Satellite 1715XCDS laptop";
        case PciSubDevice10024C4D::SUBDEVICE_13BD1019: return "PC-AR10";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C4D_H
