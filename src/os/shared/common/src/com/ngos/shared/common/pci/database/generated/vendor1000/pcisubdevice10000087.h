// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000087_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000087_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000087: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003020 = 0x10003020,
    SUBDEVICE_10003030 = 0x10003030,
    SUBDEVICE_10003040 = 0x10003040,
    SUBDEVICE_10003050 = 0x10003050,
    SUBDEVICE_10003060 = 0x10003060,
    SUBDEVICE_10140472 = 0x10140472,
    SUBDEVICE_15900041 = 0x15900041,
    SUBDEVICE_15900042 = 0x15900042,
    SUBDEVICE_15900044 = 0x15900044,
    SUBDEVICE_1BD40009 = 0x1BD40009,
    SUBDEVICE_1BD4000A = 0x1BD4000A,
    SUBDEVICE_80863000 = 0x80863000,
    SUBDEVICE_80863060 = 0x80863060,
    SUBDEVICE_80863516 = 0x80863516,
    SUBDEVICE_80863517 = 0x80863517,
    SUBDEVICE_80863518 = 0x80863518,
    SUBDEVICE_80863519 = 0x80863519,
    SUBDEVICE_8086351A = 0x8086351A,
    SUBDEVICE_8086351B = 0x8086351B
};



inline const char8* enumToString(PciSubDevice10000087 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000087::NONE:               return "NONE";
        case PciSubDevice10000087::SUBDEVICE_10003020: return "SUBDEVICE_10003020";
        case PciSubDevice10000087::SUBDEVICE_10003030: return "SUBDEVICE_10003030";
        case PciSubDevice10000087::SUBDEVICE_10003040: return "SUBDEVICE_10003040";
        case PciSubDevice10000087::SUBDEVICE_10003050: return "SUBDEVICE_10003050";
        case PciSubDevice10000087::SUBDEVICE_10003060: return "SUBDEVICE_10003060";
        case PciSubDevice10000087::SUBDEVICE_10140472: return "SUBDEVICE_10140472";
        case PciSubDevice10000087::SUBDEVICE_15900041: return "SUBDEVICE_15900041";
        case PciSubDevice10000087::SUBDEVICE_15900042: return "SUBDEVICE_15900042";
        case PciSubDevice10000087::SUBDEVICE_15900044: return "SUBDEVICE_15900044";
        case PciSubDevice10000087::SUBDEVICE_1BD40009: return "SUBDEVICE_1BD40009";
        case PciSubDevice10000087::SUBDEVICE_1BD4000A: return "SUBDEVICE_1BD4000A";
        case PciSubDevice10000087::SUBDEVICE_80863000: return "SUBDEVICE_80863000";
        case PciSubDevice10000087::SUBDEVICE_80863060: return "SUBDEVICE_80863060";
        case PciSubDevice10000087::SUBDEVICE_80863516: return "SUBDEVICE_80863516";
        case PciSubDevice10000087::SUBDEVICE_80863517: return "SUBDEVICE_80863517";
        case PciSubDevice10000087::SUBDEVICE_80863518: return "SUBDEVICE_80863518";
        case PciSubDevice10000087::SUBDEVICE_80863519: return "SUBDEVICE_80863519";
        case PciSubDevice10000087::SUBDEVICE_8086351A: return "SUBDEVICE_8086351A";
        case PciSubDevice10000087::SUBDEVICE_8086351B: return "SUBDEVICE_8086351B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000087 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000087 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000087::SUBDEVICE_10003020: return "9207-8i SAS2.1 HBA";
        case PciSubDevice10000087::SUBDEVICE_10003030: return "SAS9207-4i4e";
        case PciSubDevice10000087::SUBDEVICE_10003040: return "9207-8e SAS2.1 HBA";
        case PciSubDevice10000087::SUBDEVICE_10003050: return "SAS9217-8i";
        case PciSubDevice10000087::SUBDEVICE_10003060: return "SAS9217-4i4e";
        case PciSubDevice10000087::SUBDEVICE_10140472: return "N2125 External Host Bus Adapter";
        case PciSubDevice10000087::SUBDEVICE_15900041: return "H220i";
        case PciSubDevice10000087::SUBDEVICE_15900042: return "H221 / 9207-8e";
        case PciSubDevice10000087::SUBDEVICE_15900044: return "H220i";
        case PciSubDevice10000087::SUBDEVICE_1BD40009: return "6G SAS2308IR";
        case PciSubDevice10000087::SUBDEVICE_1BD4000A: return "6G SAS2308IT";
        case PciSubDevice10000087::SUBDEVICE_80863000: return "RS25GB008 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_80863060: return "RS25FB044 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_80863516: return "RMS25JB080 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_80863517: return "RMS25JB040 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_80863518: return "RMS25KB080 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_80863519: return "RMS25KB040 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_8086351A: return "RMS25LB040 RAID Controller";
        case PciSubDevice10000087::SUBDEVICE_8086351B: return "RMS25LB080 RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000087_H
