// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1054_PCIDEVICE1054_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1054_PCIDEVICE1054_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1054: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3009 = 0x3009,
    DEVICE_300A = 0x300A,
    DEVICE_300B = 0x300B,
    DEVICE_300F = 0x300F,
    DEVICE_3010 = 0x3010,
    DEVICE_3011 = 0x3011,
    DEVICE_3012 = 0x3012,
    DEVICE_3017 = 0x3017,
    DEVICE_301B = 0x301B,
    DEVICE_301D = 0x301D,
    DEVICE_3020 = 0x3020,
    DEVICE_302C = 0x302C,
    DEVICE_302D = 0x302D,
    DEVICE_3070 = 0x3070,
    DEVICE_3505 = 0x3505,
    DEVICE_350E = 0x350E
};



inline const char8* enumToString(PciDevice1054 device1054) // TEST: NO
{
    // COMMON_LT((" | device1054 = %u", device1054)); // Commented to avoid bad looking logs



    switch (device1054)
    {
        case PciDevice1054::NONE:        return "NONE";
        case PciDevice1054::DEVICE_3009: return "DEVICE_3009";
        case PciDevice1054::DEVICE_300A: return "DEVICE_300A";
        case PciDevice1054::DEVICE_300B: return "DEVICE_300B";
        case PciDevice1054::DEVICE_300F: return "DEVICE_300F";
        case PciDevice1054::DEVICE_3010: return "DEVICE_3010";
        case PciDevice1054::DEVICE_3011: return "DEVICE_3011";
        case PciDevice1054::DEVICE_3012: return "DEVICE_3012";
        case PciDevice1054::DEVICE_3017: return "DEVICE_3017";
        case PciDevice1054::DEVICE_301B: return "DEVICE_301B";
        case PciDevice1054::DEVICE_301D: return "DEVICE_301D";
        case PciDevice1054::DEVICE_3020: return "DEVICE_3020";
        case PciDevice1054::DEVICE_302C: return "DEVICE_302C";
        case PciDevice1054::DEVICE_302D: return "DEVICE_302D";
        case PciDevice1054::DEVICE_3070: return "DEVICE_3070";
        case PciDevice1054::DEVICE_3505: return "DEVICE_3505";
        case PciDevice1054::DEVICE_350E: return "DEVICE_350E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1054 device1054) // TEST: NO
{
    // COMMON_LT((" | device1054 = %u", device1054)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1054, enumToString(device1054));

    return res;
}



inline const char8* enumToHumanString(PciDevice1054 device1054) // TEST: NO
{
    // COMMON_LT((" | device1054 = %u", device1054)); // Commented to avoid bad looking logs



    switch (device1054)
    {
        case PciDevice1054::DEVICE_3009: return "2Gbps Fibre Channel to PCI HBA 3009";
        case PciDevice1054::DEVICE_300A: return "4Gbps Fibre Channel to PCI-X HBA 300a";
        case PciDevice1054::DEVICE_300B: return "4Gbps Fibre Channel to PCI-X HBA 300b";
        case PciDevice1054::DEVICE_300F: return "ColdFusion 3 Chipset Processor to I/O Controller";
        case PciDevice1054::DEVICE_3010: return "ColdFusion 3 Chipset Memory Controller Hub";
        case PciDevice1054::DEVICE_3011: return "ColdFusion 3e Chipset Processor to I/O Controller";
        case PciDevice1054::DEVICE_3012: return "ColdFusion 3e Chipset Memory Controller Hub";
        case PciDevice1054::DEVICE_3017: return "Unassigned Hitachi Shared FC Device 3017";
        case PciDevice1054::DEVICE_301B: return "Virtual VGA Device";
        case PciDevice1054::DEVICE_301D: return "PCIe-to-PCIe Bridge with Virtualization IO Assist Feature";
        case PciDevice1054::DEVICE_3020: return "FIVE-EX based Fibre Channel to PCIe HBA";
        case PciDevice1054::DEVICE_302C: return "M001 PCI Express Switch Upstream Port";
        case PciDevice1054::DEVICE_302D: return "M001 PCI Express Switch Downstream Port";
        case PciDevice1054::DEVICE_3070: return "Hitachi FIVE-FX Fibre Channel to PCIe HBA";
        case PciDevice1054::DEVICE_3505: return "SH7751 PCI Controller (PCIC)";
        case PciDevice1054::DEVICE_350E: return "SH7751R PCI Controller (PCIC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1054_PCIDEVICE1054_H
