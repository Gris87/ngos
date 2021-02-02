// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861209_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861209_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861209: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_140B0610 = 0x140B0610,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051,
    SUBDEVICE_4C531070 = 0x4C531070
};



inline const char8* enumToString(PciSubDevice80861209 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861209::NONE:               return "NONE";
        case PciSubDevice80861209::SUBDEVICE_140B0610: return "SUBDEVICE_140B0610";
        case PciSubDevice80861209::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice80861209::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice80861209::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";
        case PciSubDevice80861209::SUBDEVICE_4C531070: return "SUBDEVICE_4C531070";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861209 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861209 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861209::SUBDEVICE_140B0610: return "PMC610 quad Ethernet board";
        case PciSubDevice80861209::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice80861209::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice80861209::SUBDEVICE_4C531051: return "CE7 mainboard";
        case PciSubDevice80861209::SUBDEVICE_4C531070: return "PC6 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861209_H
