// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624D5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624D5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624D5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_100A147B = 0x100A147B,
    SUBDEVICE_10140287 = 0x10140287,
    SUBDEVICE_10280168 = 0x10280168,
    SUBDEVICE_10280169 = 0x10280169,
    SUBDEVICE_103C006A = 0x103C006A,
    SUBDEVICE_103C12BC = 0x103C12BC,
    SUBDEVICE_104380F3 = 0x104380F3,
    SUBDEVICE_1043810F = 0x1043810F,
    SUBDEVICE_1458A002 = 0x1458A002,
    SUBDEVICE_14620080 = 0x14620080,
    SUBDEVICE_14627280 = 0x14627280,
    SUBDEVICE_14627650 = 0x14627650,
    SUBDEVICE_8086A000 = 0x8086A000,
    SUBDEVICE_8086E000 = 0x8086E000,
    SUBDEVICE_8086E001 = 0x8086E001,
    SUBDEVICE_8086E002 = 0x8086E002
};



inline const char8* enumToString(PciSubDevice808624D5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624D5::NONE:               return "NONE";
        case PciSubDevice808624D5::SUBDEVICE_100A147B: return "SUBDEVICE_100A147B";
        case PciSubDevice808624D5::SUBDEVICE_10140287: return "SUBDEVICE_10140287";
        case PciSubDevice808624D5::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice808624D5::SUBDEVICE_10280169: return "SUBDEVICE_10280169";
        case PciSubDevice808624D5::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";
        case PciSubDevice808624D5::SUBDEVICE_103C12BC: return "SUBDEVICE_103C12BC";
        case PciSubDevice808624D5::SUBDEVICE_104380F3: return "SUBDEVICE_104380F3";
        case PciSubDevice808624D5::SUBDEVICE_1043810F: return "SUBDEVICE_1043810F";
        case PciSubDevice808624D5::SUBDEVICE_1458A002: return "SUBDEVICE_1458A002";
        case PciSubDevice808624D5::SUBDEVICE_14620080: return "SUBDEVICE_14620080";
        case PciSubDevice808624D5::SUBDEVICE_14627280: return "SUBDEVICE_14627280";
        case PciSubDevice808624D5::SUBDEVICE_14627650: return "SUBDEVICE_14627650";
        case PciSubDevice808624D5::SUBDEVICE_8086A000: return "SUBDEVICE_8086A000";
        case PciSubDevice808624D5::SUBDEVICE_8086E000: return "SUBDEVICE_8086E000";
        case PciSubDevice808624D5::SUBDEVICE_8086E001: return "SUBDEVICE_8086E001";
        case PciSubDevice808624D5::SUBDEVICE_8086E002: return "SUBDEVICE_8086E002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624D5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624D5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624D5::SUBDEVICE_100A147B: return "Abit IS7-E motherboard";
        case PciSubDevice808624D5::SUBDEVICE_10140287: return "ThinkCentre S50";
        case PciSubDevice808624D5::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice808624D5::SUBDEVICE_10280169: return "Precision 470";
        case PciSubDevice808624D5::SUBDEVICE_103C006A: return "NX9500";
        case PciSubDevice808624D5::SUBDEVICE_103C12BC: return "d330 uT";
        case PciSubDevice808624D5::SUBDEVICE_104380F3: return "P4P800 series motherboard";
        case PciSubDevice808624D5::SUBDEVICE_1043810F: return "P5P800-MX Mainboard";
        case PciSubDevice808624D5::SUBDEVICE_1458A002: return "GA-8IPE1000/8KNXP motherboard";
        case PciSubDevice808624D5::SUBDEVICE_14620080: return "865PE Neo2-V (MS-6788) Mainboard";
        case PciSubDevice808624D5::SUBDEVICE_14627280: return "865PE Neo2 (MS-6728)";
        case PciSubDevice808624D5::SUBDEVICE_14627650: return "Hetis 865GV-E (MS-7065)";
        case PciSubDevice808624D5::SUBDEVICE_8086A000: return "D865PERL mainboard";
        case PciSubDevice808624D5::SUBDEVICE_8086E000: return "D865PERL mainboard";
        case PciSubDevice808624D5::SUBDEVICE_8086E001: return "Desktop Board D865GBF";
        case PciSubDevice808624D5::SUBDEVICE_8086E002: return "SoundMax Integrated Digital Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624D5_H
