// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41654_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41654_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41654: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100E3 = 0x0E1100E3,
    SUBDEVICE_103C3100 = 0x103C3100,
    SUBDEVICE_103C3226 = 0x103C3226
};



inline const char8* enumToString(PciSubDevice14E41654 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41654::NONE:               return "NONE";
        case PciSubDevice14E41654::SUBDEVICE_0E1100E3: return "SUBDEVICE_0E1100E3";
        case PciSubDevice14E41654::SUBDEVICE_103C3100: return "SUBDEVICE_103C3100";
        case PciSubDevice14E41654::SUBDEVICE_103C3226: return "SUBDEVICE_103C3226";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41654 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41654 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41654::SUBDEVICE_0E1100E3: return "NC7761 Gigabit Server Adapter";
        case PciSubDevice14E41654::SUBDEVICE_103C3100: return "NC1020 ProLiant Gigabit Server Adapter 32 PCI";
        case PciSubDevice14E41654::SUBDEVICE_103C3226: return "NC150T 4-port Gigabit Combo Switch & Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41654_H
