// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627B8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801E6 = 0x102801E6,
    SUBDEVICE_103C2A8C = 0x103C2A8C,
    SUBDEVICE_10438179 = 0x10438179,
    SUBDEVICE_107B5048 = 0x107B5048,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_8086544E = 0x8086544E
};



inline const char8* enumToString(PciSubDevice808627B8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627B8::NONE:               return "NONE";
        case PciSubDevice808627B8::SUBDEVICE_102801E6: return "SUBDEVICE_102801E6";
        case PciSubDevice808627B8::SUBDEVICE_103C2A8C: return "SUBDEVICE_103C2A8C";
        case PciSubDevice808627B8::SUBDEVICE_10438179: return "SUBDEVICE_10438179";
        case PciSubDevice808627B8::SUBDEVICE_107B5048: return "SUBDEVICE_107B5048";
        case PciSubDevice808627B8::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice808627B8::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice808627B8::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627B8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627B8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627B8::SUBDEVICE_102801E6: return "PowerEdge 860";
        case PciSubDevice808627B8::SUBDEVICE_103C2A8C: return "Compaq 500B Microtower";
        case PciSubDevice808627B8::SUBDEVICE_10438179: return "P5B-MX/WiFi-AP, P5KPL-VM Motherboard";
        case PciSubDevice808627B8::SUBDEVICE_107B5048: return "E4500";
        case PciSubDevice808627B8::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice808627B8::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice808627B8::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B8_H
