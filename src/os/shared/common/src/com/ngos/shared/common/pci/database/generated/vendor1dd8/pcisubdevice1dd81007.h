// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCISUBDEVICE1DD81007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCISUBDEVICE1DD81007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1DD81007: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1DD84000 = 0x1DD84000,
    SUBDEVICE_1DD84001 = 0x1DD84001,
    SUBDEVICE_1DD84002 = 0x1DD84002,
    SUBDEVICE_1DD84007 = 0x1DD84007,
    SUBDEVICE_1DD84008 = 0x1DD84008,
    SUBDEVICE_1DD8400A = 0x1DD8400A,
    SUBDEVICE_1DD8400C = 0x1DD8400C,
    SUBDEVICE_1DD8400D = 0x1DD8400D,
    SUBDEVICE_1DD8400E = 0x1DD8400E
};



inline const char8* enumToString(PciSubDevice1DD81007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1DD81007::NONE:               return "NONE";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84000: return "SUBDEVICE_1DD84000";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84001: return "SUBDEVICE_1DD84001";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84002: return "SUBDEVICE_1DD84002";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84007: return "SUBDEVICE_1DD84007";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84008: return "SUBDEVICE_1DD84008";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400A: return "SUBDEVICE_1DD8400A";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400C: return "SUBDEVICE_1DD8400C";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400D: return "SUBDEVICE_1DD8400D";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400E: return "SUBDEVICE_1DD8400E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1DD81007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1DD81007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1DD81007::SUBDEVICE_1DD84000: return "Naples 100Gb 2-port QSFP28 x16 8GB";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84001: return "Naples 100Gb 2-port QSFP28 x16 4GB";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84002: return "Naples 25Gb 2-port SFP28 x8 4GB";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84007: return "DSP DSC-25 Ent 10/25G OCP3 Card";
        case PciSubDevice1DD81007::SUBDEVICE_1DD84008: return "DSP DSC-25 10/25G 2p SFP28 Card";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400A: return "DSC-100 40/100G 2-port 8G RAM 16G eMMC G1 Services Card";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400C: return "DSC-25 10/25G 2-port 4G RAM 8G eMMC G1 Services Card";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400D: return "DSP DSC-100 Ent 100Gb Card";
        case PciSubDevice1DD81007::SUBDEVICE_1DD8400E: return "DSC-25 10/25G 2-port 4G RAM 8G eMMC G1 Services Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DD8_PCISUBDEVICE1DD81007_H
