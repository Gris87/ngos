// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024397_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024397_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024397: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_103C1609 = 0x103C1609,
    SUBDEVICE_103C1611 = 0x103C1611,
    SUBDEVICE_104382EF = 0x104382EF,
    SUBDEVICE_10438443 = 0x10438443,
    SUBDEVICE_105B0E13 = 0x105B0E13,
    SUBDEVICE_14585004 = 0x14585004,
    SUBDEVICE_15D9A811 = 0x15D9A811,
    SUBDEVICE_174B1001 = 0x174B1001
};



inline const char8* enumToString(PciSubDevice10024397 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024397::NONE:               return "NONE";
        case PciSubDevice10024397::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice10024397::SUBDEVICE_103C1609: return "SUBDEVICE_103C1609";
        case PciSubDevice10024397::SUBDEVICE_103C1611: return "SUBDEVICE_103C1611";
        case PciSubDevice10024397::SUBDEVICE_104382EF: return "SUBDEVICE_104382EF";
        case PciSubDevice10024397::SUBDEVICE_10438443: return "SUBDEVICE_10438443";
        case PciSubDevice10024397::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";
        case PciSubDevice10024397::SUBDEVICE_14585004: return "SUBDEVICE_14585004";
        case PciSubDevice10024397::SUBDEVICE_15D9A811: return "SUBDEVICE_15D9A811";
        case PciSubDevice10024397::SUBDEVICE_174B1001: return "SUBDEVICE_174B1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024397 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024397 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024397::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice10024397::SUBDEVICE_103C1609: return "ProLiant MicroServer N36L";
        case PciSubDevice10024397::SUBDEVICE_103C1611: return "Pavilion DM1Z-3000";
        case PciSubDevice10024397::SUBDEVICE_104382EF: return "M3A78-EH Motherboard";
        case PciSubDevice10024397::SUBDEVICE_10438443: return "M5A88-V EVO";
        case PciSubDevice10024397::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";
        case PciSubDevice10024397::SUBDEVICE_14585004: return "GA-880GMA-USB3";
        case PciSubDevice10024397::SUBDEVICE_15D9A811: return "H8DGU";
        case PciSubDevice10024397::SUBDEVICE_174B1001: return "PURE Fusion Mini";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024397_H
