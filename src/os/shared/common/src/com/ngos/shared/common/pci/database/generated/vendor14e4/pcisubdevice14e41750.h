// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41750_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41750_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41750: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14E42100 = 0x14E42100,
    SUBDEVICE_14E45208 = 0x14E45208,
    SUBDEVICE_14E4D124 = 0x14E4D124,
    SUBDEVICE_14E4DF24 = 0x14E4DF24
};



inline const char8* enumToString(PciSubDevice14E41750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41750::NONE:               return "NONE";
        case PciSubDevice14E41750::SUBDEVICE_14E42100: return "SUBDEVICE_14E42100";
        case PciSubDevice14E41750::SUBDEVICE_14E45208: return "SUBDEVICE_14E45208";
        case PciSubDevice14E41750::SUBDEVICE_14E4D124: return "SUBDEVICE_14E4D124";
        case PciSubDevice14E41750::SUBDEVICE_14E4DF24: return "SUBDEVICE_14E4DF24";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41750::SUBDEVICE_14E42100: return "NetXtreme-E Dual-port 100G QSFP56 Ethernet PCIe4.0 x16 Adapter (BCM957508-P2100G)";
        case PciSubDevice14E41750::SUBDEVICE_14E45208: return "NetXtreme-E Dual-port 100G QSFP56 Ethernet OCP 3.0 Adapter (BCM957508-N2100G)";
        case PciSubDevice14E41750::SUBDEVICE_14E4D124: return "NetXtreme-E P2100D BCM57508 2x100G QSFP PCIE";
        case PciSubDevice14E41750::SUBDEVICE_14E4DF24: return "BCM57508 NetXtreme-E NGM2100D 2x100G KR Mezz Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41750_H
