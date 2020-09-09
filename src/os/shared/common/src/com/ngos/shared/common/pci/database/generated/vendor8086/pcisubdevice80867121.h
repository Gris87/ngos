// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867121_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867121_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867121: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C531040 = 0x4C531040,
    SUBDEVICE_4C531060 = 0x4C531060,
    SUBDEVICE_80864341 = 0x80864341
};



inline const char8* enumToString(PciSubDevice80867121 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867121::NONE:               return "NONE";
        case PciSubDevice80867121::SUBDEVICE_4C531040: return "SUBDEVICE_4C531040";
        case PciSubDevice80867121::SUBDEVICE_4C531060: return "SUBDEVICE_4C531060";
        case PciSubDevice80867121::SUBDEVICE_80864341: return "SUBDEVICE_80864341";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867121 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867121 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867121::SUBDEVICE_4C531040: return "CL7 mainboard";
        case PciSubDevice80867121::SUBDEVICE_4C531060: return "PC7 mainboard";
        case PciSubDevice80867121::SUBDEVICE_80864341: return "Cayman (CA810) Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867121_H
