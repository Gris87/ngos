// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCISUBDEVICE1E3B0600_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCISUBDEVICE1E3B0600_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E3B0600: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1E3B0030 = 0x1E3B0030,
    SUBDEVICE_1E3B0031 = 0x1E3B0031,
    SUBDEVICE_1E3B0032 = 0x1E3B0032,
    SUBDEVICE_1E3B0033 = 0x1E3B0033,
    SUBDEVICE_1E3B0034 = 0x1E3B0034,
    SUBDEVICE_1E3B0035 = 0x1E3B0035,
    SUBDEVICE_1E3B0036 = 0x1E3B0036,
    SUBDEVICE_1E3B0037 = 0x1E3B0037,
    SUBDEVICE_1E3B003E = 0x1E3B003E,
    SUBDEVICE_1E3B003F = 0x1E3B003F,
    SUBDEVICE_1E3B0050 = 0x1E3B0050,
    SUBDEVICE_1E3B0051 = 0x1E3B0051,
    SUBDEVICE_1E3B0052 = 0x1E3B0052,
    SUBDEVICE_1E3B0053 = 0x1E3B0053,
    SUBDEVICE_1E3B0054 = 0x1E3B0054,
    SUBDEVICE_1E3B0055 = 0x1E3B0055,
    SUBDEVICE_1E3B0056 = 0x1E3B0056,
    SUBDEVICE_1E3B0059 = 0x1E3B0059,
    SUBDEVICE_1E3B0060 = 0x1E3B0060,
    SUBDEVICE_1E3B0061 = 0x1E3B0061,
    SUBDEVICE_1E3B0063 = 0x1E3B0063,
    SUBDEVICE_1E3B0064 = 0x1E3B0064,
    SUBDEVICE_1E3B00F0 = 0x1E3B00F0,
    SUBDEVICE_1E3B00F1 = 0x1E3B00F1,
    SUBDEVICE_1E3B00F2 = 0x1E3B00F2,
    SUBDEVICE_1E3B00F3 = 0x1E3B00F3,
    SUBDEVICE_1E3B00F5 = 0x1E3B00F5,
    SUBDEVICE_1E3B00F6 = 0x1E3B00F6
};



inline const char8* enumToString(PciSubDevice1E3B0600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E3B0600::NONE:               return "NONE";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0030: return "SUBDEVICE_1E3B0030";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0031: return "SUBDEVICE_1E3B0031";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0032: return "SUBDEVICE_1E3B0032";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0033: return "SUBDEVICE_1E3B0033";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0034: return "SUBDEVICE_1E3B0034";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0035: return "SUBDEVICE_1E3B0035";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0036: return "SUBDEVICE_1E3B0036";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0037: return "SUBDEVICE_1E3B0037";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B003E: return "SUBDEVICE_1E3B003E";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B003F: return "SUBDEVICE_1E3B003F";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0050: return "SUBDEVICE_1E3B0050";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0051: return "SUBDEVICE_1E3B0051";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0052: return "SUBDEVICE_1E3B0052";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0053: return "SUBDEVICE_1E3B0053";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0054: return "SUBDEVICE_1E3B0054";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0055: return "SUBDEVICE_1E3B0055";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0056: return "SUBDEVICE_1E3B0056";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0059: return "SUBDEVICE_1E3B0059";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0060: return "SUBDEVICE_1E3B0060";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0061: return "SUBDEVICE_1E3B0061";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0063: return "SUBDEVICE_1E3B0063";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0064: return "SUBDEVICE_1E3B0064";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F0: return "SUBDEVICE_1E3B00F0";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F1: return "SUBDEVICE_1E3B00F1";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F2: return "SUBDEVICE_1E3B00F2";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F3: return "SUBDEVICE_1E3B00F3";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F5: return "SUBDEVICE_1E3B00F5";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F6: return "SUBDEVICE_1E3B00F6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E3B0600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E3B0600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0030: return "Enterprise NVMe SSD U.2 3.84TB (J5100)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0031: return "Enterprise NVMe SSD U.2 7.68TB (J5100)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0032: return "Enterprise NVMe SSD U.2 15.36TB (J5100)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0033: return "Enterprise NVMe SSD U.2 3.20TB (J5300)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0034: return "Enterprise NVMe SSD U.2 6.40TB (J5300)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0035: return "Enterprise NVMe SSD U.2 12.80TB (J5300)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0036: return "Enterprise NVMe SSD AIC 7.68TB (J5110)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0037: return "Enterprise NVMe SSD AIC 6.40TB (J5310)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B003E: return "Enterprise NVMe SSD AIC 3.84TB (J5110)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B003F: return "Enterprise NVMe SSD AIC 3.20TB (J5310)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0050: return "Enterprise NVMe SSD U.2 3.84TB (R5100)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0051: return "Enterprise NVMe SSD U.2 7.68TB (R5100)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0052: return "Enterprise NVMe SSD U.2 15.36TB (R5100)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0053: return "Enterprise NVMe SSD U.2 3.20TB (R5300)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0054: return "Enterprise NVMe SSD U.2 6.40TB (R5300)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0055: return "Enterprise NVMe SSD U.2 12.80TB (R5300)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0056: return "Enterprise NVMe SSD U.2 3.84TB (R5101)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0059: return "Enterprise NVMe SSD U.2 3.20TB (R5301)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0060: return "Enterprise NVMe SSD U.2 3.84TB (R5100D)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0061: return "Enterprise NVMe SSD U.2 7.68TB (R5100D)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0063: return "Enterprise NVMe SSD U.2 3.20TB (R5300D)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B0064: return "Enterprise NVMe SSD U.2 6.40TB (R5300D)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F0: return "Enterprise NVMe SSD U.2 0.40TB (X2900)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F1: return "Enterprise NVMe SSD U.2 0.80TB (X2900)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F2: return "Enterprise NVMe SSD U.2 1.60TB (X2900)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F3: return "Enterprise NVMe SSD U.2 3.20TB (X2900)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F5: return "Enterprise NVMe SSD U.2 0.40TB (X2900P)";
        case PciSubDevice1E3B0600::SUBDEVICE_1E3B00F6: return "Enterprise NVMe SSD U.2 0.80TB (X2900P)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCISUBDEVICE1E3B0600_H
