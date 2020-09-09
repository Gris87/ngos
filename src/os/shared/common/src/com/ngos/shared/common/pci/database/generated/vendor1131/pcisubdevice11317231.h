// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317231_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317231_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11317231: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_5ACE8000 = 0x5ACE8000,
    SUBDEVICE_5ACE8001 = 0x5ACE8001,
    SUBDEVICE_5ACE8050 = 0x5ACE8050,
    SUBDEVICE_5ACE8051 = 0x5ACE8051,
    SUBDEVICE_5ACE8100 = 0x5ACE8100,
    SUBDEVICE_5ACE8101 = 0x5ACE8101,
    SUBDEVICE_5ACE8150 = 0x5ACE8150,
    SUBDEVICE_5ACE8151 = 0x5ACE8151,
    SUBDEVICE_5ACE8201 = 0x5ACE8201
};



inline const char8* enumToString(PciSubDevice11317231 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317231::NONE:               return "NONE";
        case PciSubDevice11317231::SUBDEVICE_5ACE8000: return "SUBDEVICE_5ACE8000";
        case PciSubDevice11317231::SUBDEVICE_5ACE8001: return "SUBDEVICE_5ACE8001";
        case PciSubDevice11317231::SUBDEVICE_5ACE8050: return "SUBDEVICE_5ACE8050";
        case PciSubDevice11317231::SUBDEVICE_5ACE8051: return "SUBDEVICE_5ACE8051";
        case PciSubDevice11317231::SUBDEVICE_5ACE8100: return "SUBDEVICE_5ACE8100";
        case PciSubDevice11317231::SUBDEVICE_5ACE8101: return "SUBDEVICE_5ACE8101";
        case PciSubDevice11317231::SUBDEVICE_5ACE8150: return "SUBDEVICE_5ACE8150";
        case PciSubDevice11317231::SUBDEVICE_5ACE8151: return "SUBDEVICE_5ACE8151";
        case PciSubDevice11317231::SUBDEVICE_5ACE8201: return "SUBDEVICE_5ACE8201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11317231 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11317231 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317231::SUBDEVICE_5ACE8000: return "Behold TV H8";
        case PciSubDevice11317231::SUBDEVICE_5ACE8001: return "Behold TV H8";
        case PciSubDevice11317231::SUBDEVICE_5ACE8050: return "Behold TV H85";
        case PciSubDevice11317231::SUBDEVICE_5ACE8051: return "Behold TV H85";
        case PciSubDevice11317231::SUBDEVICE_5ACE8100: return "Behold TV A8";
        case PciSubDevice11317231::SUBDEVICE_5ACE8101: return "Behold TV A8";
        case PciSubDevice11317231::SUBDEVICE_5ACE8150: return "Behold TV A85";
        case PciSubDevice11317231::SUBDEVICE_5ACE8151: return "Behold TV A85";
        case PciSubDevice11317231::SUBDEVICE_5ACE8201: return "Behold TV T8";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317231_H
