// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026740_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026740_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026740: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1019238C = 0x1019238C,
    SUBDEVICE_1019238E = 0x1019238E,
    SUBDEVICE_10192391 = 0x10192391,
    SUBDEVICE_10192392 = 0x10192392,
    SUBDEVICE_102804A3 = 0x102804A3,
    SUBDEVICE_1028053E = 0x1028053E,
    SUBDEVICE_103C1630 = 0x103C1630,
    SUBDEVICE_103C1631 = 0x103C1631,
    SUBDEVICE_103C164B = 0x103C164B,
    SUBDEVICE_103C164E = 0x103C164E,
    SUBDEVICE_103C1657 = 0x103C1657,
    SUBDEVICE_103C1658 = 0x103C1658,
    SUBDEVICE_103C165A = 0x103C165A,
    SUBDEVICE_103C165B = 0x103C165B,
    SUBDEVICE_103C1688 = 0x103C1688,
    SUBDEVICE_103C1689 = 0x103C1689,
    SUBDEVICE_103C168A = 0x103C168A,
    SUBDEVICE_103C185E = 0x103C185E,
    SUBDEVICE_103C3388 = 0x103C3388,
    SUBDEVICE_103C3389 = 0x103C3389,
    SUBDEVICE_103C3582 = 0x103C3582,
    SUBDEVICE_103C366C = 0x103C366C,
    SUBDEVICE_10431D02 = 0x10431D02,
    SUBDEVICE_10431D12 = 0x10431D12,
    SUBDEVICE_104D9084 = 0x104D9084,
    SUBDEVICE_104D9085 = 0x104D9085,
    SUBDEVICE_144DB074 = 0x144DB074,
    SUBDEVICE_144DB077 = 0x144DB077,
    SUBDEVICE_144DB084 = 0x144DB084,
    SUBDEVICE_144DB088 = 0x144DB088,
    SUBDEVICE_17AA3982 = 0x17AA3982
};



inline const char8* enumToString(PciSubDevice10026740 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026740::NONE:               return "NONE";
        case PciSubDevice10026740::SUBDEVICE_1019238C: return "SUBDEVICE_1019238C";
        case PciSubDevice10026740::SUBDEVICE_1019238E: return "SUBDEVICE_1019238E";
        case PciSubDevice10026740::SUBDEVICE_10192391: return "SUBDEVICE_10192391";
        case PciSubDevice10026740::SUBDEVICE_10192392: return "SUBDEVICE_10192392";
        case PciSubDevice10026740::SUBDEVICE_102804A3: return "SUBDEVICE_102804A3";
        case PciSubDevice10026740::SUBDEVICE_1028053E: return "SUBDEVICE_1028053E";
        case PciSubDevice10026740::SUBDEVICE_103C1630: return "SUBDEVICE_103C1630";
        case PciSubDevice10026740::SUBDEVICE_103C1631: return "SUBDEVICE_103C1631";
        case PciSubDevice10026740::SUBDEVICE_103C164B: return "SUBDEVICE_103C164B";
        case PciSubDevice10026740::SUBDEVICE_103C164E: return "SUBDEVICE_103C164E";
        case PciSubDevice10026740::SUBDEVICE_103C1657: return "SUBDEVICE_103C1657";
        case PciSubDevice10026740::SUBDEVICE_103C1658: return "SUBDEVICE_103C1658";
        case PciSubDevice10026740::SUBDEVICE_103C165A: return "SUBDEVICE_103C165A";
        case PciSubDevice10026740::SUBDEVICE_103C165B: return "SUBDEVICE_103C165B";
        case PciSubDevice10026740::SUBDEVICE_103C1688: return "SUBDEVICE_103C1688";
        case PciSubDevice10026740::SUBDEVICE_103C1689: return "SUBDEVICE_103C1689";
        case PciSubDevice10026740::SUBDEVICE_103C168A: return "SUBDEVICE_103C168A";
        case PciSubDevice10026740::SUBDEVICE_103C185E: return "SUBDEVICE_103C185E";
        case PciSubDevice10026740::SUBDEVICE_103C3388: return "SUBDEVICE_103C3388";
        case PciSubDevice10026740::SUBDEVICE_103C3389: return "SUBDEVICE_103C3389";
        case PciSubDevice10026740::SUBDEVICE_103C3582: return "SUBDEVICE_103C3582";
        case PciSubDevice10026740::SUBDEVICE_103C366C: return "SUBDEVICE_103C366C";
        case PciSubDevice10026740::SUBDEVICE_10431D02: return "SUBDEVICE_10431D02";
        case PciSubDevice10026740::SUBDEVICE_10431D12: return "SUBDEVICE_10431D12";
        case PciSubDevice10026740::SUBDEVICE_104D9084: return "SUBDEVICE_104D9084";
        case PciSubDevice10026740::SUBDEVICE_104D9085: return "SUBDEVICE_104D9085";
        case PciSubDevice10026740::SUBDEVICE_144DB074: return "SUBDEVICE_144DB074";
        case PciSubDevice10026740::SUBDEVICE_144DB077: return "SUBDEVICE_144DB077";
        case PciSubDevice10026740::SUBDEVICE_144DB084: return "SUBDEVICE_144DB084";
        case PciSubDevice10026740::SUBDEVICE_144DB088: return "SUBDEVICE_144DB088";
        case PciSubDevice10026740::SUBDEVICE_17AA3982: return "SUBDEVICE_17AA3982";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026740 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026740 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026740::SUBDEVICE_1019238C: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_1019238E: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_10192391: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_10192392: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_102804A3: return "Precision M4600";
        case PciSubDevice10026740::SUBDEVICE_1028053E: return "FirePro M5950";
        case PciSubDevice10026740::SUBDEVICE_103C1630: return "FirePro M5950";
        case PciSubDevice10026740::SUBDEVICE_103C1631: return "FirePro M5950";
        case PciSubDevice10026740::SUBDEVICE_103C164B: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_103C164E: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_103C1657: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C1658: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C165A: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C165B: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C1688: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C1689: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C168A: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C185E: return "Radeon HD 7690M XT";
        case PciSubDevice10026740::SUBDEVICE_103C3388: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C3389: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C3582: return "Radeon HD 6770M";
        case PciSubDevice10026740::SUBDEVICE_103C366C: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_10431D02: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_10431D12: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_104D9084: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_104D9085: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_144DB074: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_144DB077: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_144DB084: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_144DB088: return "Radeon HD 6730M";
        case PciSubDevice10026740::SUBDEVICE_17AA3982: return "Radeon HD 6730M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026740_H
