// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C102A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C102A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C102A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107E000E = 0x107E000E,
    SUBDEVICE_90049110 = 0x90049110,
    SUBDEVICE_90049111 = 0x90049111
};



inline const char8* enumToString(PciSubDevice103C102A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C102A::NONE:               return "NONE";
        case PciSubDevice103C102A::SUBDEVICE_107E000E: return "SUBDEVICE_107E000E";
        case PciSubDevice103C102A::SUBDEVICE_90049110: return "SUBDEVICE_90049110";
        case PciSubDevice103C102A::SUBDEVICE_90049111: return "SUBDEVICE_90049111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C102A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C102A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C102A::SUBDEVICE_107E000E: return "Interphase 5540/5541 Fibre Channel Adapter";
        case PciSubDevice103C102A::SUBDEVICE_90049110: return "1Gb/2Gb Family Fibre Channel Controller";
        case PciSubDevice103C102A::SUBDEVICE_90049111: return "1Gb/2Gb Family Fibre Channel Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C102A_H
