// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41659_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41659_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41659: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101402C6 = 0x101402C6,
    SUBDEVICE_102801E6 = 0x102801E6,
    SUBDEVICE_1028023C = 0x1028023C,
    SUBDEVICE_103C170B = 0x103C170B,
    SUBDEVICE_103C7031 = 0x103C7031,
    SUBDEVICE_103C7032 = 0x103C7032,
    SUBDEVICE_17341061 = 0x17341061
};



inline const char8* enumToString(PciSubDevice14E41659 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41659::NONE:               return "NONE";
        case PciSubDevice14E41659::SUBDEVICE_101402C6: return "SUBDEVICE_101402C6";
        case PciSubDevice14E41659::SUBDEVICE_102801E6: return "SUBDEVICE_102801E6";
        case PciSubDevice14E41659::SUBDEVICE_1028023C: return "SUBDEVICE_1028023C";
        case PciSubDevice14E41659::SUBDEVICE_103C170B: return "SUBDEVICE_103C170B";
        case PciSubDevice14E41659::SUBDEVICE_103C7031: return "SUBDEVICE_103C7031";
        case PciSubDevice14E41659::SUBDEVICE_103C7032: return "SUBDEVICE_103C7032";
        case PciSubDevice14E41659::SUBDEVICE_17341061: return "SUBDEVICE_17341061";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41659 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41659 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41659::SUBDEVICE_101402C6: return "eServer xSeries server mainboard";
        case PciSubDevice14E41659::SUBDEVICE_102801E6: return "PowerEdge 860";
        case PciSubDevice14E41659::SUBDEVICE_1028023C: return "PowerEdge R200 Broadcom NetXtreme BCM5721";
        case PciSubDevice14E41659::SUBDEVICE_103C170B: return "NC320m PCI Express Dual Port Gigabit Server Adapter";
        case PciSubDevice14E41659::SUBDEVICE_103C7031: return "NC320T PCIe Gigabit Server Adapter";
        case PciSubDevice14E41659::SUBDEVICE_103C7032: return "NC320i PCIe Gigabit Server Adapter";
        case PciSubDevice14E41659::SUBDEVICE_17341061: return "PRIMERGY RX/TX S2 series onboard LAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41659_H
