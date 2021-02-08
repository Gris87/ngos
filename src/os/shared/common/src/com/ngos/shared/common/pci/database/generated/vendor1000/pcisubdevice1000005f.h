// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000005F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F44 = 0x10281F44,
    SUBDEVICE_10281F4B = 0x10281F4B,
    SUBDEVICE_10281F4C = 0x10281F4C,
    SUBDEVICE_10281F4D = 0x10281F4D,
    SUBDEVICE_1054306A = 0x1054306A,
    SUBDEVICE_17341211 = 0x17341211,
    SUBDEVICE_1D4904DB = 0x1D4904DB,
    SUBDEVICE_1D490504 = 0x1D490504
};



inline const char8* enumToString(PciSubDevice1000005F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000005F::NONE:               return "NONE";
        case PciSubDevice1000005F::SUBDEVICE_10281F44: return "SUBDEVICE_10281F44";
        case PciSubDevice1000005F::SUBDEVICE_10281F4B: return "SUBDEVICE_10281F4B";
        case PciSubDevice1000005F::SUBDEVICE_10281F4C: return "SUBDEVICE_10281F4C";
        case PciSubDevice1000005F::SUBDEVICE_10281F4D: return "SUBDEVICE_10281F4D";
        case PciSubDevice1000005F::SUBDEVICE_1054306A: return "SUBDEVICE_1054306A";
        case PciSubDevice1000005F::SUBDEVICE_17341211: return "SUBDEVICE_17341211";
        case PciSubDevice1000005F::SUBDEVICE_1D4904DB: return "SUBDEVICE_1D4904DB";
        case PciSubDevice1000005F::SUBDEVICE_1D490504: return "SUBDEVICE_1D490504";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000005F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000005F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000005F::SUBDEVICE_10281F44: return "PERC H330 Adapter";
        case PciSubDevice1000005F::SUBDEVICE_10281F4B: return "PERC H330 Mini";
        case PciSubDevice1000005F::SUBDEVICE_10281F4C: return "PERC H330 Mini (for blades)";
        case PciSubDevice1000005F::SUBDEVICE_10281F4D: return "PERC H330 Embedded (for monolithic)";
        case PciSubDevice1000005F::SUBDEVICE_1054306A: return "SAS 3004 iMR ROMB";
        case PciSubDevice1000005F::SUBDEVICE_17341211: return "PRAID CP400i [D3307-A12]";
        case PciSubDevice1000005F::SUBDEVICE_1D4904DB: return "ServeRAID M1210 SAS/SATA Controller";
        case PciSubDevice1000005F::SUBDEVICE_1D490504: return "ThinkSystem RAID 520-8i PCIe 12Gb Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005F_H
