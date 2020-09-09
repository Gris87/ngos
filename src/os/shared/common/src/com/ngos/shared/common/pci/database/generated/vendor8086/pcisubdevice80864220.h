// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864220_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864220_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864220: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C12F6 = 0x103C12F6,
    SUBDEVICE_80862701 = 0x80862701,
    SUBDEVICE_80862712 = 0x80862712,
    SUBDEVICE_80862721 = 0x80862721,
    SUBDEVICE_80862722 = 0x80862722,
    SUBDEVICE_80862731 = 0x80862731
};



inline const char8* enumToString(PciSubDevice80864220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864220::NONE:               return "NONE";
        case PciSubDevice80864220::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice80864220::SUBDEVICE_103C12F6: return "SUBDEVICE_103C12F6";
        case PciSubDevice80864220::SUBDEVICE_80862701: return "SUBDEVICE_80862701";
        case PciSubDevice80864220::SUBDEVICE_80862712: return "SUBDEVICE_80862712";
        case PciSubDevice80864220::SUBDEVICE_80862721: return "SUBDEVICE_80862721";
        case PciSubDevice80864220::SUBDEVICE_80862722: return "SUBDEVICE_80862722";
        case PciSubDevice80864220::SUBDEVICE_80862731: return "SUBDEVICE_80862731";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864220::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice80864220::SUBDEVICE_103C12F6: return "nc6120/nc6220/nw8240/nx8220";
        case PciSubDevice80864220::SUBDEVICE_80862701: return "WM3B2200BG Mini-PCI Card";
        case PciSubDevice80864220::SUBDEVICE_80862712: return "IBM ThinkPad R50e";
        case PciSubDevice80864220::SUBDEVICE_80862721: return "Dell B130 laptop integrated WLAN";
        case PciSubDevice80864220::SUBDEVICE_80862722: return "Dell Latitude D600";
        case PciSubDevice80864220::SUBDEVICE_80862731: return "Samsung P35 integrated WLAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864220_H
