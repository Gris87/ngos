// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94027_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94027_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC94027: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11540368 = 0x11540368,
    SUBDEVICE_14328104 = 0x14328104,
    SUBDEVICE_15464027 = 0x15464027,
    SUBDEVICE_1BAA3310 = 0x1BAA3310,
    SUBDEVICE_1FC93015 = 0x1FC93015,
    SUBDEVICE_4C521001 = 0x4C521001
};



inline const char8* enumToString(PciSubDevice1FC94027 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94027::NONE:               return "NONE";
        case PciSubDevice1FC94027::SUBDEVICE_11540368: return "SUBDEVICE_11540368";
        case PciSubDevice1FC94027::SUBDEVICE_14328104: return "SUBDEVICE_14328104";
        case PciSubDevice1FC94027::SUBDEVICE_15464027: return "SUBDEVICE_15464027";
        case PciSubDevice1FC94027::SUBDEVICE_1BAA3310: return "SUBDEVICE_1BAA3310";
        case PciSubDevice1FC94027::SUBDEVICE_1FC93015: return "SUBDEVICE_1FC93015";
        case PciSubDevice1FC94027::SUBDEVICE_4C521001: return "SUBDEVICE_4C521001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC94027 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC94027 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94027::SUBDEVICE_11540368: return "LGY-PCIE-MG";
        case PciSubDevice1FC94027::SUBDEVICE_14328104: return "10 Gigabit Ethernet PCI Express Adapter";
        case PciSubDevice1FC94027::SUBDEVICE_15464027: return "GE10-PCIE4XG202P 10Gbase-T/NBASE-T Ethernet Adapter";
        case PciSubDevice1FC94027::SUBDEVICE_1BAA3310: return "PCIe Expansion Card";
        case PciSubDevice1FC94027::SUBDEVICE_1FC93015: return "Ethernet Adapter";
        case PciSubDevice1FC94027::SUBDEVICE_4C521001: return "LREC6860BT 10 Gigabit Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94027_H
