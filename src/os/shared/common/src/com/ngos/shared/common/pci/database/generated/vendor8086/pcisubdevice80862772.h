// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862772_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862772_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862772: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_18492772 = 0x18492772,
    SUBDEVICE_8086544E = 0x8086544E,
    SUBDEVICE_8086D605 = 0x8086D605
};



inline const char8* enumToString(PciSubDevice80862772 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862772::NONE:               return "NONE";
        case PciSubDevice80862772::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice80862772::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice80862772::SUBDEVICE_18492772: return "SUBDEVICE_18492772";
        case PciSubDevice80862772::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";
        case PciSubDevice80862772::SUBDEVICE_8086D605: return "SUBDEVICE_8086D605";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862772 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862772 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862772::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice80862772::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice80862772::SUBDEVICE_18492772: return "ConRoe1333-D667";
        case PciSubDevice80862772::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";
        case PciSubDevice80862772::SUBDEVICE_8086D605: return "Desktop Board D945GCCR";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862772_H
