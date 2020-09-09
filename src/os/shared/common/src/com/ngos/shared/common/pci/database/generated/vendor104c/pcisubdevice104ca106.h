// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CA106_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CA106_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CA106: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_175C5000 = 0x175C5000,
    SUBDEVICE_175C6400 = 0x175C6400,
    SUBDEVICE_175C8700 = 0x175C8700
};



inline const char8* enumToString(PciSubDevice104CA106 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CA106::NONE:               return "NONE";
        case PciSubDevice104CA106::SUBDEVICE_175C5000: return "SUBDEVICE_175C5000";
        case PciSubDevice104CA106::SUBDEVICE_175C6400: return "SUBDEVICE_175C6400";
        case PciSubDevice104CA106::SUBDEVICE_175C8700: return "SUBDEVICE_175C8700";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CA106 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CA106 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CA106::SUBDEVICE_175C5000: return "ASI50xx Audio Adapter";
        case PciSubDevice104CA106::SUBDEVICE_175C6400: return "ASI6400 Cobranet series";
        case PciSubDevice104CA106::SUBDEVICE_175C8700: return "ASI87xx Radio Tuner card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CA106_H
