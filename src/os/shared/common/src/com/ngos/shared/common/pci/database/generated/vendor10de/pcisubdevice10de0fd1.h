// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FD1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FD1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0FD1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10431597 = 0x10431597,
    SUBDEVICE_104315A7 = 0x104315A7,
    SUBDEVICE_10432103 = 0x10432103,
    SUBDEVICE_10432105 = 0x10432105,
    SUBDEVICE_10432141 = 0x10432141
};



inline const char8* enumToString(PciSubDevice10DE0FD1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0FD1::NONE:               return "NONE";
        case PciSubDevice10DE0FD1::SUBDEVICE_10431597: return "SUBDEVICE_10431597";
        case PciSubDevice10DE0FD1::SUBDEVICE_104315A7: return "SUBDEVICE_104315A7";
        case PciSubDevice10DE0FD1::SUBDEVICE_10432103: return "SUBDEVICE_10432103";
        case PciSubDevice10DE0FD1::SUBDEVICE_10432105: return "SUBDEVICE_10432105";
        case PciSubDevice10DE0FD1::SUBDEVICE_10432141: return "SUBDEVICE_10432141";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0FD1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0FD1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0FD1::SUBDEVICE_10431597: return "GeForce GT 650M";
        case PciSubDevice10DE0FD1::SUBDEVICE_104315A7: return "GeForce GT 650M";
        case PciSubDevice10DE0FD1::SUBDEVICE_10432103: return "N56VZ";
        case PciSubDevice10DE0FD1::SUBDEVICE_10432105: return "GeForce GT 650M";
        case PciSubDevice10DE0FD1::SUBDEVICE_10432141: return "GeForce GT 650M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FD1_H
