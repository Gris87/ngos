// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0020: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_03083407 = 0x03083407,
    SUBDEVICE_11863A67 = 0x11863A67,
    SUBDEVICE_11863A68 = 0x11863A68,
    SUBDEVICE_187E340E = 0x187E340E,
    SUBDEVICE_19762003 = 0x19762003
};



inline const char8* enumToString(PciSubDevice168C0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0020::NONE:               return "NONE";
        case PciSubDevice168C0020::SUBDEVICE_03083407: return "SUBDEVICE_03083407";
        case PciSubDevice168C0020::SUBDEVICE_11863A67: return "SUBDEVICE_11863A67";
        case PciSubDevice168C0020::SUBDEVICE_11863A68: return "SUBDEVICE_11863A68";
        case PciSubDevice168C0020::SUBDEVICE_187E340E: return "SUBDEVICE_187E340E";
        case PciSubDevice168C0020::SUBDEVICE_19762003: return "SUBDEVICE_19762003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0020::SUBDEVICE_03083407: return "M-102 802.11g Wireless Cardbus Adapter";
        case PciSubDevice168C0020::SUBDEVICE_11863A67: return "DWL-G650M Super G MIMO Wireless Notebook Adapter";
        case PciSubDevice168C0020::SUBDEVICE_11863A68: return "DWL-G520M Wireless 108G MIMO Desktop Adapter";
        case PciSubDevice168C0020::SUBDEVICE_187E340E: return "M-302 802.11g Wireless PCI Adapter";
        case PciSubDevice168C0020::SUBDEVICE_19762003: return "TEW-601PC 802.11g Wireless CardBus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0020_H
