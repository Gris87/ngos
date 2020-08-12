// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AD_PCIDEVICE15AD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AD_PCIDEVICE15AD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15AD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0405 = 0x0405,
    DEVICE_0710 = 0x0710,
    DEVICE_0720 = 0x0720,
    DEVICE_0740 = 0x0740,
    DEVICE_0770 = 0x0770,
    DEVICE_0774 = 0x0774,
    DEVICE_0778 = 0x0778,
    DEVICE_0779 = 0x0779,
    DEVICE_0790 = 0x0790,
    DEVICE_07A0 = 0x07A0,
    DEVICE_07B0 = 0x07B0,
    DEVICE_07C0 = 0x07C0,
    DEVICE_07E0 = 0x07E0,
    DEVICE_0801 = 0x0801,
    DEVICE_0820 = 0x0820,
    DEVICE_1977 = 0x1977
};



inline const char8* enumToString(PciDevice15AD device15AD) // TEST: NO
{
    // COMMON_LT((" | device15AD = %u", device15AD)); // Commented to avoid bad looking logs



    switch (device15AD)
    {
        case PciDevice15AD::NONE:        return "NONE";
        case PciDevice15AD::DEVICE_0405: return "DEVICE_0405";
        case PciDevice15AD::DEVICE_0710: return "DEVICE_0710";
        case PciDevice15AD::DEVICE_0720: return "DEVICE_0720";
        case PciDevice15AD::DEVICE_0740: return "DEVICE_0740";
        case PciDevice15AD::DEVICE_0770: return "DEVICE_0770";
        case PciDevice15AD::DEVICE_0774: return "DEVICE_0774";
        case PciDevice15AD::DEVICE_0778: return "DEVICE_0778";
        case PciDevice15AD::DEVICE_0779: return "DEVICE_0779";
        case PciDevice15AD::DEVICE_0790: return "DEVICE_0790";
        case PciDevice15AD::DEVICE_07A0: return "DEVICE_07A0";
        case PciDevice15AD::DEVICE_07B0: return "DEVICE_07B0";
        case PciDevice15AD::DEVICE_07C0: return "DEVICE_07C0";
        case PciDevice15AD::DEVICE_07E0: return "DEVICE_07E0";
        case PciDevice15AD::DEVICE_0801: return "DEVICE_0801";
        case PciDevice15AD::DEVICE_0820: return "DEVICE_0820";
        case PciDevice15AD::DEVICE_1977: return "DEVICE_1977";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15AD device15AD) // TEST: NO
{
    // COMMON_LT((" | device15AD = %u", device15AD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15AD, enumToString(device15AD));

    return res;
}



inline const char8* enumToHumanString(PciDevice15AD device15AD) // TEST: NO
{
    // COMMON_LT((" | device15AD = %u", device15AD)); // Commented to avoid bad looking logs



    switch (device15AD)
    {
        case PciDevice15AD::DEVICE_0405: return "SVGA II Adapter";
        case PciDevice15AD::DEVICE_0710: return "SVGA Adapter";
        case PciDevice15AD::DEVICE_0720: return "VMXNET Ethernet Controller";
        case PciDevice15AD::DEVICE_0740: return "Virtual Machine Communication Interface";
        case PciDevice15AD::DEVICE_0770: return "USB2 EHCI Controller";
        case PciDevice15AD::DEVICE_0774: return "USB1.1 UHCI Controller";
        case PciDevice15AD::DEVICE_0778: return "USB3 xHCI 0.96 Controller";
        case PciDevice15AD::DEVICE_0779: return "USB3 xHCI 1.0 Controller";
        case PciDevice15AD::DEVICE_0790: return "PCI bridge";
        case PciDevice15AD::DEVICE_07A0: return "PCI Express Root Port";
        case PciDevice15AD::DEVICE_07B0: return "VMXNET3 Ethernet Controller";
        case PciDevice15AD::DEVICE_07C0: return "PVSCSI SCSI Controller";
        case PciDevice15AD::DEVICE_07E0: return "SATA AHCI controller";
        case PciDevice15AD::DEVICE_0801: return "Virtual Machine Interface";
        case PciDevice15AD::DEVICE_0820: return "Paravirtual RDMA controller";
        case PciDevice15AD::DEVICE_1977: return "HD Audio Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AD_PCIDEVICE15AD_H
