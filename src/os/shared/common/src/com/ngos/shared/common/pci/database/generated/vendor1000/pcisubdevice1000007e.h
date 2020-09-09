// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000007E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000007E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000007E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000504 = 0x10000504,
    SUBDEVICE_10000507 = 0x10000507,
    SUBDEVICE_10000581 = 0x10000581,
    SUBDEVICE_1000100D = 0x1000100D,
    SUBDEVICE_1000100E = 0x1000100E,
    SUBDEVICE_1000107E = 0x1000107E,
    SUBDEVICE_10001310 = 0x10001310,
    SUBDEVICE_10001311 = 0x10001311,
    SUBDEVICE_10001314 = 0x10001314,
    SUBDEVICE_1000150C = 0x1000150C,
    SUBDEVICE_1000150F = 0x1000150F,
    SUBDEVICE_1000160B = 0x1000160B,
    SUBDEVICE_10001613 = 0x10001613,
    SUBDEVICE_108E050A = 0x108E050A,
    SUBDEVICE_108E0581 = 0x108E0581
};



inline const char8* enumToString(PciSubDevice1000007E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000007E::NONE:               return "NONE";
        case PciSubDevice1000007E::SUBDEVICE_10000504: return "SUBDEVICE_10000504";
        case PciSubDevice1000007E::SUBDEVICE_10000507: return "SUBDEVICE_10000507";
        case PciSubDevice1000007E::SUBDEVICE_10000581: return "SUBDEVICE_10000581";
        case PciSubDevice1000007E::SUBDEVICE_1000100D: return "SUBDEVICE_1000100D";
        case PciSubDevice1000007E::SUBDEVICE_1000100E: return "SUBDEVICE_1000100E";
        case PciSubDevice1000007E::SUBDEVICE_1000107E: return "SUBDEVICE_1000107E";
        case PciSubDevice1000007E::SUBDEVICE_10001310: return "SUBDEVICE_10001310";
        case PciSubDevice1000007E::SUBDEVICE_10001311: return "SUBDEVICE_10001311";
        case PciSubDevice1000007E::SUBDEVICE_10001314: return "SUBDEVICE_10001314";
        case PciSubDevice1000007E::SUBDEVICE_1000150C: return "SUBDEVICE_1000150C";
        case PciSubDevice1000007E::SUBDEVICE_1000150F: return "SUBDEVICE_1000150F";
        case PciSubDevice1000007E::SUBDEVICE_1000160B: return "SUBDEVICE_1000160B";
        case PciSubDevice1000007E::SUBDEVICE_10001613: return "SUBDEVICE_10001613";
        case PciSubDevice1000007E::SUBDEVICE_108E050A: return "SUBDEVICE_108E050A";
        case PciSubDevice1000007E::SUBDEVICE_108E0581: return "SUBDEVICE_108E0581";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000007E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000007E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000007E::SUBDEVICE_10000504: return "Nytro NWD-BLP4-800";
        case PciSubDevice1000007E::SUBDEVICE_10000507: return "Nytro NWD-BLP4-1600";
        case PciSubDevice1000007E::SUBDEVICE_10000581: return "Nytro NWD-BLP4-400";
        case PciSubDevice1000007E::SUBDEVICE_1000100D: return "Nytro NWD-BFH6-1200";
        case PciSubDevice1000007E::SUBDEVICE_1000100E: return "Nytro NWD-BFH8-1600";
        case PciSubDevice1000007E::SUBDEVICE_1000107E: return "Nytro NWD-BFH8-3200";
        case PciSubDevice1000007E::SUBDEVICE_10001310: return "Nytro XP6302-8B1536";
        case PciSubDevice1000007E::SUBDEVICE_10001311: return "Nytro XP6302-8B2048";
        case PciSubDevice1000007E::SUBDEVICE_10001314: return "Nytro XP6302-8B4096";
        case PciSubDevice1000007E::SUBDEVICE_1000150C: return "Nytro XP6210-4A2048";
        case PciSubDevice1000007E::SUBDEVICE_1000150F: return "Nytro XP6210-4B2048";
        case PciSubDevice1000007E::SUBDEVICE_1000160B: return "Nytro XP6209-4A1024";
        case PciSubDevice1000007E::SUBDEVICE_10001613: return "Nytro XP6209-4B2048";
        case PciSubDevice1000007E::SUBDEVICE_108E050A: return "Nytro ELP4x200_4d_n";
        case PciSubDevice1000007E::SUBDEVICE_108E0581: return "Nytro ELP4x100_4d_n";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000007E_H
