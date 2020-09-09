// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864223_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864223_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864223: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10008086 = 0x10008086,
    SUBDEVICE_10018086 = 0x10018086,
    SUBDEVICE_10028086 = 0x10028086,
    SUBDEVICE_10038086 = 0x10038086,
    SUBDEVICE_103C1351 = 0x103C1351
};



inline const char8* enumToString(PciSubDevice80864223 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864223::NONE:               return "NONE";
        case PciSubDevice80864223::SUBDEVICE_10008086: return "SUBDEVICE_10008086";
        case PciSubDevice80864223::SUBDEVICE_10018086: return "SUBDEVICE_10018086";
        case PciSubDevice80864223::SUBDEVICE_10028086: return "SUBDEVICE_10028086";
        case PciSubDevice80864223::SUBDEVICE_10038086: return "SUBDEVICE_10038086";
        case PciSubDevice80864223::SUBDEVICE_103C1351: return "SUBDEVICE_103C1351";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864223 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864223 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864223::SUBDEVICE_10008086: return "mPCI 3B Americas/Europe ZZA";
        case PciSubDevice80864223::SUBDEVICE_10018086: return "mPCI 3B Europe ZZE";
        case PciSubDevice80864223::SUBDEVICE_10028086: return "mPCI 3B Japan ZZJ";
        case PciSubDevice80864223::SUBDEVICE_10038086: return "mPCI 3B High-Band ZZH";
        case PciSubDevice80864223::SUBDEVICE_103C1351: return "Compaq nc6220";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864223_H
