// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1031_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C1031: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1040 = 0x103C1040,
    SUBDEVICE_103C1041 = 0x103C1041,
    SUBDEVICE_103C1042 = 0x103C1042
};



inline const char8* enumToString(PciSubDevice103C1031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C1031::NONE:               return "NONE";
        case PciSubDevice103C1031::SUBDEVICE_103C1040: return "SUBDEVICE_103C1040";
        case PciSubDevice103C1031::SUBDEVICE_103C1041: return "SUBDEVICE_103C1041";
        case PciSubDevice103C1031::SUBDEVICE_103C1042: return "SUBDEVICE_103C1042";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C1031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C1031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C1031::SUBDEVICE_103C1040: return "J2973A DeskDirect 10BaseT NIC";
        case PciSubDevice103C1031::SUBDEVICE_103C1041: return "J2585B DeskDirect 10/100VG NIC";
        case PciSubDevice103C1031::SUBDEVICE_103C1042: return "J2970A DeskDirect 10BaseT/2 NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1031_H
