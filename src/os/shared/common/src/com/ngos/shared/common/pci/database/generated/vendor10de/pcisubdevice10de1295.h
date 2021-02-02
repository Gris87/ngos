// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1295_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1295_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1295: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2B0D = 0x103C2B0D,
    SUBDEVICE_103C2B0F = 0x103C2B0F,
    SUBDEVICE_103C2B11 = 0x103C2B11,
    SUBDEVICE_103C2B20 = 0x103C2B20,
    SUBDEVICE_103C2B21 = 0x103C2B21,
    SUBDEVICE_103C2B22 = 0x103C2B22,
    SUBDEVICE_17AA367A = 0x17AA367A,
    SUBDEVICE_17AA367C = 0x17AA367C
};



inline const char8* enumToString(PciSubDevice10DE1295 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1295::NONE:               return "NONE";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B0D: return "SUBDEVICE_103C2B0D";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B0F: return "SUBDEVICE_103C2B0F";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B11: return "SUBDEVICE_103C2B11";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B20: return "SUBDEVICE_103C2B20";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B21: return "SUBDEVICE_103C2B21";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B22: return "SUBDEVICE_103C2B22";
        case PciSubDevice10DE1295::SUBDEVICE_17AA367A: return "SUBDEVICE_17AA367A";
        case PciSubDevice10DE1295::SUBDEVICE_17AA367C: return "SUBDEVICE_17AA367C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1295 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1295 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1295::SUBDEVICE_103C2B0D: return "GeForce 710A";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B0F: return "GeForce 710A";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B11: return "GeForce 710A";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B20: return "GeForce 810A";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B21: return "GeForce 810A";
        case PciSubDevice10DE1295::SUBDEVICE_103C2B22: return "GeForce 810A";
        case PciSubDevice10DE1295::SUBDEVICE_17AA367A: return "GeForce 805A";
        case PciSubDevice10DE1295::SUBDEVICE_17AA367C: return "GeForce 710A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1295_H
