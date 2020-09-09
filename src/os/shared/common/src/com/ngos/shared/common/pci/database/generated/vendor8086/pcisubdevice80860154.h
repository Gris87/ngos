// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860154_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860154_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860154: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250806 = 0x10250806,
    SUBDEVICE_10250813 = 0x10250813,
    SUBDEVICE_103C17F6 = 0x103C17F6,
    SUBDEVICE_1043108D = 0x1043108D,
    SUBDEVICE_10431477 = 0x10431477,
    SUBDEVICE_10431517 = 0x10431517,
    SUBDEVICE_10CF16BF = 0x10CF16BF
};



inline const char8* enumToString(PciSubDevice80860154 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860154::NONE:               return "NONE";
        case PciSubDevice80860154::SUBDEVICE_10250806: return "SUBDEVICE_10250806";
        case PciSubDevice80860154::SUBDEVICE_10250813: return "SUBDEVICE_10250813";
        case PciSubDevice80860154::SUBDEVICE_103C17F6: return "SUBDEVICE_103C17F6";
        case PciSubDevice80860154::SUBDEVICE_1043108D: return "SUBDEVICE_1043108D";
        case PciSubDevice80860154::SUBDEVICE_10431477: return "SUBDEVICE_10431477";
        case PciSubDevice80860154::SUBDEVICE_10431517: return "SUBDEVICE_10431517";
        case PciSubDevice80860154::SUBDEVICE_10CF16BF: return "SUBDEVICE_10CF16BF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860154 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860154 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860154::SUBDEVICE_10250806: return "Aspire E1-470G";
        case PciSubDevice80860154::SUBDEVICE_10250813: return "Aspire R7-571";
        case PciSubDevice80860154::SUBDEVICE_103C17F6: return "ProBook 4540s";
        case PciSubDevice80860154::SUBDEVICE_1043108D: return "VivoBook X202EV";
        case PciSubDevice80860154::SUBDEVICE_10431477: return "N56VZ";
        case PciSubDevice80860154::SUBDEVICE_10431517: return "Zenbook Prime UX31A";
        case PciSubDevice80860154::SUBDEVICE_10CF16BF: return "LIFEBOOK E752";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860154_H
