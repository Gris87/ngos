// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E0F0007: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282078 = 0x10282078,
    SUBDEVICE_10282079 = 0x10282079,
    SUBDEVICE_1028207A = 0x1028207A,
    SUBDEVICE_1028207B = 0x1028207B,
    SUBDEVICE_1028207C = 0x1028207C,
    SUBDEVICE_1028207E = 0x1028207E,
    SUBDEVICE_1028207F = 0x1028207F,
    SUBDEVICE_10282080 = 0x10282080,
    SUBDEVICE_10282081 = 0x10282081,
    SUBDEVICE_10282084 = 0x10282084,
    SUBDEVICE_10282085 = 0x10282085,
    SUBDEVICE_10282086 = 0x10282086,
    SUBDEVICE_1028210A = 0x1028210A,
    SUBDEVICE_1028210B = 0x1028210B,
    SUBDEVICE_1028210C = 0x1028210C,
    SUBDEVICE_1028210D = 0x1028210D,
    SUBDEVICE_1028210E = 0x1028210E,
    SUBDEVICE_1028210F = 0x1028210F,
    SUBDEVICE_10282110 = 0x10282110
};



inline const char8* enumToString(PciSubDevice1E0F0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E0F0007::NONE:               return "NONE";
        case PciSubDevice1E0F0007::SUBDEVICE_10282078: return "SUBDEVICE_10282078";
        case PciSubDevice1E0F0007::SUBDEVICE_10282079: return "SUBDEVICE_10282079";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207A: return "SUBDEVICE_1028207A";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207B: return "SUBDEVICE_1028207B";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207C: return "SUBDEVICE_1028207C";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207E: return "SUBDEVICE_1028207E";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207F: return "SUBDEVICE_1028207F";
        case PciSubDevice1E0F0007::SUBDEVICE_10282080: return "SUBDEVICE_10282080";
        case PciSubDevice1E0F0007::SUBDEVICE_10282081: return "SUBDEVICE_10282081";
        case PciSubDevice1E0F0007::SUBDEVICE_10282084: return "SUBDEVICE_10282084";
        case PciSubDevice1E0F0007::SUBDEVICE_10282085: return "SUBDEVICE_10282085";
        case PciSubDevice1E0F0007::SUBDEVICE_10282086: return "SUBDEVICE_10282086";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210A: return "SUBDEVICE_1028210A";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210B: return "SUBDEVICE_1028210B";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210C: return "SUBDEVICE_1028210C";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210D: return "SUBDEVICE_1028210D";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210E: return "SUBDEVICE_1028210E";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210F: return "SUBDEVICE_1028210F";
        case PciSubDevice1E0F0007::SUBDEVICE_10282110: return "SUBDEVICE_10282110";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E0F0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E0F0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E0F0007::SUBDEVICE_10282078: return "DC NVMe CD6 RI 960GB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282079: return "DC NVMe CD6 RI 1.92TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207A: return "DC NVMe CD6 RI 3.84TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207B: return "DC NVMe CD6 RI 7.68TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207C: return "DC NVMe CD6 RI 15.36TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207E: return "Dell Ent NVMe CM6 RI 1.92TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028207F: return "Dell Ent NVMe CM6 RI 3.84TB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282080: return "Dell Ent NVMe CM6 RI 7.68TB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282081: return "Dell Ent NVMe CM6 RI 15.36TB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282084: return "Dell Ent NVMe CM6 MU 1.6TB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282085: return "Dell Ent NVMe CM6 MU 3.2TB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282086: return "Dell Ent NVMe CM6 MU 6.4TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210A: return "Dell Ent NVMe FIPS CM6 RI 1.92TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210B: return "Dell Ent NVMe FIPS CM6 RI 3.84TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210C: return "Dell Ent NVMe FIPS CM6 RI 7.68TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210D: return "Dell Ent NVMe FIPS CM6 RI15.36TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210E: return "Dell Ent NVMe FIPS CM6 MU 1.6TB";
        case PciSubDevice1E0F0007::SUBDEVICE_1028210F: return "Dell Ent NVMe FIPS CM6 MU 3.2TB";
        case PciSubDevice1E0F0007::SUBDEVICE_10282110: return "Dell Ent NVMe FIPS CM6 MU 6.4TB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCISUBDEVICE1E0F0007_H
