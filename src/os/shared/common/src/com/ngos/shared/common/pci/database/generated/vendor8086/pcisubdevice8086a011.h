// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A011_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A011_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086A011: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104383AC = 0x104383AC,
    SUBDEVICE_144DC072 = 0x144DC072
};



inline const char8* enumToString(PciSubDevice8086A011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086A011::NONE:               return "NONE";
        case PciSubDevice8086A011::SUBDEVICE_104383AC: return "SUBDEVICE_104383AC";
        case PciSubDevice8086A011::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086A011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086A011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086A011::SUBDEVICE_104383AC: return "Eee PC 1015PX";
        case PciSubDevice8086A011::SUBDEVICE_144DC072: return "Notebook N150P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A011_H
