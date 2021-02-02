// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE03EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE03EC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE03EC: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250392 = 0x10250392,
    SUBDEVICE_1028020E = 0x1028020E,
    SUBDEVICE_104383A4 = 0x104383A4,
    SUBDEVICE_184903EC = 0x184903EC
};



inline const char8* enumToString(PciSubDevice10DE03EC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE03EC::NONE:               return "NONE";
        case PciSubDevice10DE03EC::SUBDEVICE_10250392: return "SUBDEVICE_10250392";
        case PciSubDevice10DE03EC::SUBDEVICE_1028020E: return "SUBDEVICE_1028020E";
        case PciSubDevice10DE03EC::SUBDEVICE_104383A4: return "SUBDEVICE_104383A4";
        case PciSubDevice10DE03EC::SUBDEVICE_184903EC: return "SUBDEVICE_184903EC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE03EC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE03EC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE03EC::SUBDEVICE_10250392: return "ET1350";
        case PciSubDevice10DE03EC::SUBDEVICE_1028020E: return "Inspiron 531";
        case PciSubDevice10DE03EC::SUBDEVICE_104383A4: return "M4N68T series motherboard";
        case PciSubDevice10DE03EC::SUBDEVICE_184903EC: return "939NF6G-VSTA Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE03EC_H
