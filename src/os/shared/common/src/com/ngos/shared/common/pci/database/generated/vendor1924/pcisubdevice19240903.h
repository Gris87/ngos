// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240903_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240903_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240903: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101404CC = 0x101404CC,
    SUBDEVICE_19248002 = 0x19248002,
    SUBDEVICE_19248003 = 0x19248003,
    SUBDEVICE_19248006 = 0x19248006,
    SUBDEVICE_19248007 = 0x19248007,
    SUBDEVICE_19248009 = 0x19248009,
    SUBDEVICE_1924800A = 0x1924800A,
    SUBDEVICE_1924800C = 0x1924800C,
    SUBDEVICE_1924800D = 0x1924800D,
    SUBDEVICE_19248010 = 0x19248010,
    SUBDEVICE_19248015 = 0x19248015
};



inline const char8* enumToString(PciSubDevice19240903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240903::NONE:               return "NONE";
        case PciSubDevice19240903::SUBDEVICE_101404CC: return "SUBDEVICE_101404CC";
        case PciSubDevice19240903::SUBDEVICE_19248002: return "SUBDEVICE_19248002";
        case PciSubDevice19240903::SUBDEVICE_19248003: return "SUBDEVICE_19248003";
        case PciSubDevice19240903::SUBDEVICE_19248006: return "SUBDEVICE_19248006";
        case PciSubDevice19240903::SUBDEVICE_19248007: return "SUBDEVICE_19248007";
        case PciSubDevice19240903::SUBDEVICE_19248009: return "SUBDEVICE_19248009";
        case PciSubDevice19240903::SUBDEVICE_1924800A: return "SUBDEVICE_1924800A";
        case PciSubDevice19240903::SUBDEVICE_1924800C: return "SUBDEVICE_1924800C";
        case PciSubDevice19240903::SUBDEVICE_1924800D: return "SUBDEVICE_1924800D";
        case PciSubDevice19240903::SUBDEVICE_19248010: return "SUBDEVICE_19248010";
        case PciSubDevice19240903::SUBDEVICE_19248015: return "SUBDEVICE_19248015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240903::SUBDEVICE_101404CC: return "SFN7122F-R2 2x10GbE SFP+ Flareon Ultra";
        case PciSubDevice19240903::SUBDEVICE_19248002: return "SFN7122F-R1 SFP+ Server Adapter";
        case PciSubDevice19240903::SUBDEVICE_19248003: return "SFN7x41Q-R1 Flareon Ultra 7000 Series 10/40G Adapter";
        case PciSubDevice19240903::SUBDEVICE_19248006: return "SFN7022F-R1 SFP+ Server Adapter";
        case PciSubDevice19240903::SUBDEVICE_19248007: return "SFN7322F-R2 Precision Time SFP+ Server Adapter";
        case PciSubDevice19240903::SUBDEVICE_19248009: return "SFN7x22F-R2 Flareon Ultra 7000 Series 10G Adapter";
        case PciSubDevice19240903::SUBDEVICE_1924800A: return "SFN7x02F-R2 Flareon 7000 Series 10G Adapter";
        case PciSubDevice19240903::SUBDEVICE_1924800C: return "SFN7x22F-R3 Flareon Ultra 7000 Series 10G Adapter";
        case PciSubDevice19240903::SUBDEVICE_1924800D: return "SFN7x02F-R3 Flareon 7000 Series 10G Adapter";
        case PciSubDevice19240903::SUBDEVICE_19248010: return "SFA7942Q-R1 QSFP+ AOE Adapter";
        case PciSubDevice19240903::SUBDEVICE_19248015: return "SFA7942Q-A5-0-R1 QSFP+ AOE Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240903_H
