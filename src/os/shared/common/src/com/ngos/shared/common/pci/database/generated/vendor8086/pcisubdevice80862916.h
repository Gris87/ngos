// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862916_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862916_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862916: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_10438277 = 0x10438277,
    SUBDEVICE_14627345 = 0x14627345,
    SUBDEVICE_80865044 = 0x80865044
};



inline const char8* enumToString(PciSubDevice80862916 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862916::NONE:               return "NONE";
        case PciSubDevice80862916::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice80862916::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice80862916::SUBDEVICE_10438277: return "SUBDEVICE_10438277";
        case PciSubDevice80862916::SUBDEVICE_14627345: return "SUBDEVICE_14627345";
        case PciSubDevice80862916::SUBDEVICE_80865044: return "SUBDEVICE_80865044";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862916 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862916 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862916::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice80862916::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice80862916::SUBDEVICE_10438277: return "P5K PRO Motherboard";
        case PciSubDevice80862916::SUBDEVICE_14627345: return "MS-7345 Motherboard";
        case PciSubDevice80862916::SUBDEVICE_80865044: return "Desktop Board DP35DP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862916_H
