// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862668_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862668_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862668: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101405B7 = 0x101405B7,
    SUBDEVICE_103C2A09 = 0x103C2A09,
    SUBDEVICE_10431173 = 0x10431173,
    SUBDEVICE_1043814E = 0x1043814E,
    SUBDEVICE_14627028 = 0x14627028,
    SUBDEVICE_1AF41100 = 0x1AF41100
};



inline const char8* enumToString(PciSubDevice80862668 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862668::NONE:               return "NONE";
        case PciSubDevice80862668::SUBDEVICE_101405B7: return "SUBDEVICE_101405B7";
        case PciSubDevice80862668::SUBDEVICE_103C2A09: return "SUBDEVICE_103C2A09";
        case PciSubDevice80862668::SUBDEVICE_10431173: return "SUBDEVICE_10431173";
        case PciSubDevice80862668::SUBDEVICE_1043814E: return "SUBDEVICE_1043814E";
        case PciSubDevice80862668::SUBDEVICE_14627028: return "SUBDEVICE_14627028";
        case PciSubDevice80862668::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862668 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862668 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862668::SUBDEVICE_101405B7: return "ThinkPad Z60t";
        case PciSubDevice80862668::SUBDEVICE_103C2A09: return "PufferM-UL8E";
        case PciSubDevice80862668::SUBDEVICE_10431173: return "A6VC";
        case PciSubDevice80862668::SUBDEVICE_1043814E: return "P5GD1-VW Mainboard";
        case PciSubDevice80862668::SUBDEVICE_14627028: return "915P/G Neo2";
        case PciSubDevice80862668::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862668_H
