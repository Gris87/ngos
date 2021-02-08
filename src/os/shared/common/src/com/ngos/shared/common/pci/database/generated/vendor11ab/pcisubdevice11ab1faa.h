// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB1FAA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB1FAA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB1FAA: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13854E00 = 0x13854E00,
    SUBDEVICE_13856B00 = 0x13856B00,
    SUBDEVICE_17370040 = 0x17370040
};



inline const char8* enumToString(PciSubDevice11AB1FAA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB1FAA::NONE:               return "NONE";
        case PciSubDevice11AB1FAA::SUBDEVICE_13854E00: return "SUBDEVICE_13854E00";
        case PciSubDevice11AB1FAA::SUBDEVICE_13856B00: return "SUBDEVICE_13856B00";
        case PciSubDevice11AB1FAA::SUBDEVICE_17370040: return "SUBDEVICE_17370040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB1FAA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB1FAA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB1FAA::SUBDEVICE_13854E00: return "WG511v2 54 Mbps Wireless PC Card";
        case PciSubDevice11AB1FAA::SUBDEVICE_13856B00: return "WG311v3 802.11g Wireless PCI Adapter";
        case PciSubDevice11AB1FAA::SUBDEVICE_17370040: return "WPC54G v5 802.11g Wireless-G Notebook Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB1FAA_H
