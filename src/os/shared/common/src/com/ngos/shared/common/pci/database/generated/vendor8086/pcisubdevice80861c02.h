// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C02_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C02_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861C02: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804AA = 0x102804AA,
    SUBDEVICE_1043844D = 0x1043844D,
    SUBDEVICE_8086200D = 0x8086200D,
    SUBDEVICE_80867270 = 0x80867270
};



inline const char8* enumToString(PciSubDevice80861C02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C02::NONE:               return "NONE";
        case PciSubDevice80861C02::SUBDEVICE_102804AA: return "SUBDEVICE_102804AA";
        case PciSubDevice80861C02::SUBDEVICE_1043844D: return "SUBDEVICE_1043844D";
        case PciSubDevice80861C02::SUBDEVICE_8086200D: return "SUBDEVICE_8086200D";
        case PciSubDevice80861C02::SUBDEVICE_80867270: return "SUBDEVICE_80867270";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861C02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861C02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C02::SUBDEVICE_102804AA: return "XPS 8300";
        case PciSubDevice80861C02::SUBDEVICE_1043844D: return "P8 series motherboard";
        case PciSubDevice80861C02::SUBDEVICE_8086200D: return "DH61CR motherboard";
        case PciSubDevice80861C02::SUBDEVICE_80867270: return "Server Board S1200BT Family";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C02_H
