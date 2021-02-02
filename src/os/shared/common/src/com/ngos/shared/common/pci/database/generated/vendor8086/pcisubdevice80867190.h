// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867190_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867190_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867190: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110500 = 0x0E110500,
    SUBDEVICE_0E11B110 = 0x0E11B110,
    SUBDEVICE_1028008E = 0x1028008E,
    SUBDEVICE_1043803B = 0x1043803B,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_15AD1976 = 0x15AD1976,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051
};



inline const char8* enumToString(PciSubDevice80867190 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867190::NONE:               return "NONE";
        case PciSubDevice80867190::SUBDEVICE_0E110500: return "SUBDEVICE_0E110500";
        case PciSubDevice80867190::SUBDEVICE_0E11B110: return "SUBDEVICE_0E11B110";
        case PciSubDevice80867190::SUBDEVICE_1028008E: return "SUBDEVICE_1028008E";
        case PciSubDevice80867190::SUBDEVICE_1043803B: return "SUBDEVICE_1043803B";
        case PciSubDevice80867190::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice80867190::SUBDEVICE_15AD1976: return "SUBDEVICE_15AD1976";
        case PciSubDevice80867190::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice80867190::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867190 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867190 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867190::SUBDEVICE_0E110500: return "Armada 1750 Laptop System Chipset";
        case PciSubDevice80867190::SUBDEVICE_0E11B110: return "Armada M700/E500";
        case PciSubDevice80867190::SUBDEVICE_1028008E: return "PowerEdge 1300 mainboard";
        case PciSubDevice80867190::SUBDEVICE_1043803B: return "CUBX-L/E Mainboard";
        case PciSubDevice80867190::SUBDEVICE_11790001: return "Toshiba Tecra 8100 Laptop System Chipset";
        case PciSubDevice80867190::SUBDEVICE_15AD1976: return "Virtual Machine Chipset";
        case PciSubDevice80867190::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice80867190::SUBDEVICE_4C531051: return "CE7 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867190_H
