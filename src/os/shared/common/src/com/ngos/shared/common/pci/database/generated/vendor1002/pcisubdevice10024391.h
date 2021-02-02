// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024391_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024391_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024391: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1609 = 0x103C1609,
    SUBDEVICE_103C1611 = 0x103C1611,
    SUBDEVICE_104382EF = 0x104382EF,
    SUBDEVICE_10438443 = 0x10438443,
    SUBDEVICE_104384DD = 0x104384DD,
    SUBDEVICE_105B0E13 = 0x105B0E13,
    SUBDEVICE_1458B002 = 0x1458B002,
    SUBDEVICE_174B1001 = 0x174B1001
};



inline const char8* enumToString(PciSubDevice10024391 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024391::NONE:               return "NONE";
        case PciSubDevice10024391::SUBDEVICE_103C1609: return "SUBDEVICE_103C1609";
        case PciSubDevice10024391::SUBDEVICE_103C1611: return "SUBDEVICE_103C1611";
        case PciSubDevice10024391::SUBDEVICE_104382EF: return "SUBDEVICE_104382EF";
        case PciSubDevice10024391::SUBDEVICE_10438443: return "SUBDEVICE_10438443";
        case PciSubDevice10024391::SUBDEVICE_104384DD: return "SUBDEVICE_104384DD";
        case PciSubDevice10024391::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";
        case PciSubDevice10024391::SUBDEVICE_1458B002: return "SUBDEVICE_1458B002";
        case PciSubDevice10024391::SUBDEVICE_174B1001: return "SUBDEVICE_174B1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024391 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024391 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024391::SUBDEVICE_103C1609: return "ProLiant MicroServer N36L";
        case PciSubDevice10024391::SUBDEVICE_103C1611: return "Pavilion DM1Z-3000";
        case PciSubDevice10024391::SUBDEVICE_104382EF: return "M3A78-EH Motherboard";
        case PciSubDevice10024391::SUBDEVICE_10438443: return "M5A88-V EVO";
        case PciSubDevice10024391::SUBDEVICE_104384DD: return "M5A99X EVO (R1.0) SB950";
        case PciSubDevice10024391::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";
        case PciSubDevice10024391::SUBDEVICE_1458B002: return "GA-880GMA-USB3";
        case PciSubDevice10024391::SUBDEVICE_174B1001: return "PURE Fusion Mini";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024391_H
