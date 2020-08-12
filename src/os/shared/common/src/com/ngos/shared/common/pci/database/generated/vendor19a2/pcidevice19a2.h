// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCIDEVICE19A2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCIDEVICE19A2_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19A2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0120 = 0x0120,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_0211 = 0x0211,
    DEVICE_0212 = 0x0212,
    DEVICE_0221 = 0x0221,
    DEVICE_0222 = 0x0222,
    DEVICE_0700 = 0x0700,
    DEVICE_0702 = 0x0702,
    DEVICE_0704 = 0x0704,
    DEVICE_0710 = 0x0710,
    DEVICE_0712 = 0x0712,
    DEVICE_0714 = 0x0714,
    DEVICE_0800 = 0x0800
};



inline const char8* enumToString(PciDevice19A2 device19A2) // TEST: NO
{
    // COMMON_LT((" | device19A2 = %u", device19A2)); // Commented to avoid bad looking logs



    switch (device19A2)
    {
        case PciDevice19A2::NONE:        return "NONE";
        case PciDevice19A2::DEVICE_0120: return "DEVICE_0120";
        case PciDevice19A2::DEVICE_0200: return "DEVICE_0200";
        case PciDevice19A2::DEVICE_0201: return "DEVICE_0201";
        case PciDevice19A2::DEVICE_0211: return "DEVICE_0211";
        case PciDevice19A2::DEVICE_0212: return "DEVICE_0212";
        case PciDevice19A2::DEVICE_0221: return "DEVICE_0221";
        case PciDevice19A2::DEVICE_0222: return "DEVICE_0222";
        case PciDevice19A2::DEVICE_0700: return "DEVICE_0700";
        case PciDevice19A2::DEVICE_0702: return "DEVICE_0702";
        case PciDevice19A2::DEVICE_0704: return "DEVICE_0704";
        case PciDevice19A2::DEVICE_0710: return "DEVICE_0710";
        case PciDevice19A2::DEVICE_0712: return "DEVICE_0712";
        case PciDevice19A2::DEVICE_0714: return "DEVICE_0714";
        case PciDevice19A2::DEVICE_0800: return "DEVICE_0800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19A2 device19A2) // TEST: NO
{
    // COMMON_LT((" | device19A2 = %u", device19A2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device19A2, enumToString(device19A2));

    return res;
}



inline const char8* enumToHumanString(PciDevice19A2 device19A2) // TEST: NO
{
    // COMMON_LT((" | device19A2 = %u", device19A2)); // Commented to avoid bad looking logs



    switch (device19A2)
    {
        case PciDevice19A2::DEVICE_0120: return "x1 PCIe Gen2 Bridge[Pilot4]";
        case PciDevice19A2::DEVICE_0200: return "BladeEngine 10Gb PCI-E iSCSI adapter";
        case PciDevice19A2::DEVICE_0201: return "BladeEngine 10Gb PCIe Network Adapter";
        case PciDevice19A2::DEVICE_0211: return "BladeEngine2 10Gb Gen2 PCIe Network Adapter";
        case PciDevice19A2::DEVICE_0212: return "BladeEngine2 10Gb Gen2 PCIe iSCSI Adapter";
        case PciDevice19A2::DEVICE_0221: return "BladeEngine3 10Gb Gen2 PCIe Network Adapter";
        case PciDevice19A2::DEVICE_0222: return "BladeEngine3 10Gb Gen2 PCIe iSCSI Adapter";
        case PciDevice19A2::DEVICE_0700: return "OneConnect OCe10100/OCe10102 Series 10 GbE";
        case PciDevice19A2::DEVICE_0702: return "OneConnect 10Gb iSCSI Initiator";
        case PciDevice19A2::DEVICE_0704: return "OneConnect OCe10100/OCe10102 Series 10 GbE CNA";
        case PciDevice19A2::DEVICE_0710: return "OneConnect 10Gb NIC (be3)";
        case PciDevice19A2::DEVICE_0712: return "OneConnect 10Gb iSCSI Initiator (be3)";
        case PciDevice19A2::DEVICE_0714: return "OneConnect 10Gb FCoE Initiator (be3)";
        case PciDevice19A2::DEVICE_0800: return "ServerView iRMC HTI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCIDEVICE19A2_H
