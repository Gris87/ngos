// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862770_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862770_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862770: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801AD = 0x102801AD,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_1043817A = 0x1043817A,
    SUBDEVICE_107B5048 = 0x107B5048,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_18492770 = 0x18492770,
    SUBDEVICE_8086544E = 0x8086544E
};



inline const char8* enumToString(PciSubDevice80862770 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862770::NONE:               return "NONE";
        case PciSubDevice80862770::SUBDEVICE_102801AD: return "SUBDEVICE_102801AD";
        case PciSubDevice80862770::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice80862770::SUBDEVICE_1043817A: return "SUBDEVICE_1043817A";
        case PciSubDevice80862770::SUBDEVICE_107B5048: return "SUBDEVICE_107B5048";
        case PciSubDevice80862770::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice80862770::SUBDEVICE_18492770: return "SUBDEVICE_18492770";
        case PciSubDevice80862770::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862770 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862770 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862770::SUBDEVICE_102801AD: return "OptiPlex GX620";
        case PciSubDevice80862770::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice80862770::SUBDEVICE_1043817A: return "P5LD2-VM Mainboard";
        case PciSubDevice80862770::SUBDEVICE_107B5048: return "E4500";
        case PciSubDevice80862770::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice80862770::SUBDEVICE_18492770: return "ConRoe1333-D667";
        case PciSubDevice80862770::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862770_H
