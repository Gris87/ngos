// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1029_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1029_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C1029: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107E000F = 0x107E000F,
    SUBDEVICE_90049210 = 0x90049210,
    SUBDEVICE_90049211 = 0x90049211
};



inline const char8* enumToString(PciSubDevice103C1029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C1029::NONE:               return "NONE";
        case PciSubDevice103C1029::SUBDEVICE_107E000F: return "SUBDEVICE_107E000F";
        case PciSubDevice103C1029::SUBDEVICE_90049210: return "SUBDEVICE_90049210";
        case PciSubDevice103C1029::SUBDEVICE_90049211: return "SUBDEVICE_90049211";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C1029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C1029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C1029::SUBDEVICE_107E000F: return "Interphase 5560 Fibre Channel Adapter";
        case PciSubDevice103C1029::SUBDEVICE_90049210: return "1Gb/2Gb Family Fibre Channel Controller";
        case PciSubDevice103C1029::SUBDEVICE_90049211: return "1Gb/2Gb Family Fibre Channel Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1029_H
