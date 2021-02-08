// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267B0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267B0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267B0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280B00 = 0x10280B00,
    SUBDEVICE_103C6566 = 0x103C6566,
    SUBDEVICE_1043046A = 0x1043046A,
    SUBDEVICE_1043046C = 0x1043046C,
    SUBDEVICE_10430474 = 0x10430474,
    SUBDEVICE_10430476 = 0x10430476,
    SUBDEVICE_104304D7 = 0x104304D7,
    SUBDEVICE_104304DB = 0x104304DB,
    SUBDEVICE_104304DF = 0x104304DF,
    SUBDEVICE_104304E9 = 0x104304E9,
    SUBDEVICE_1458227C = 0x1458227C,
    SUBDEVICE_14582281 = 0x14582281,
    SUBDEVICE_1458228C = 0x1458228C,
    SUBDEVICE_1458228D = 0x1458228D,
    SUBDEVICE_14582290 = 0x14582290,
    SUBDEVICE_145822BC = 0x145822BC,
    SUBDEVICE_145822C1 = 0x145822C1,
    SUBDEVICE_14622015 = 0x14622015,
    SUBDEVICE_14623070 = 0x14623070,
    SUBDEVICE_14623071 = 0x14623071,
    SUBDEVICE_14623072 = 0x14623072,
    SUBDEVICE_14623080 = 0x14623080,
    SUBDEVICE_14623082 = 0x14623082,
    SUBDEVICE_148C2347 = 0x148C2347,
    SUBDEVICE_148C2357 = 0x148C2357,
    SUBDEVICE_16829290 = 0x16829290,
    SUBDEVICE_16829395 = 0x16829395,
    SUBDEVICE_174B0E34 = 0x174B0E34,
    SUBDEVICE_174BE282 = 0x174BE282,
    SUBDEVICE_174BE285 = 0x174BE285,
    SUBDEVICE_174BE324 = 0x174BE324,
    SUBDEVICE_17872020 = 0x17872020,
    SUBDEVICE_17872357 = 0x17872357
};



inline const char8* enumToString(PciSubDevice100267B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267B0::NONE:               return "NONE";
        case PciSubDevice100267B0::SUBDEVICE_10280B00: return "SUBDEVICE_10280B00";
        case PciSubDevice100267B0::SUBDEVICE_103C6566: return "SUBDEVICE_103C6566";
        case PciSubDevice100267B0::SUBDEVICE_1043046A: return "SUBDEVICE_1043046A";
        case PciSubDevice100267B0::SUBDEVICE_1043046C: return "SUBDEVICE_1043046C";
        case PciSubDevice100267B0::SUBDEVICE_10430474: return "SUBDEVICE_10430474";
        case PciSubDevice100267B0::SUBDEVICE_10430476: return "SUBDEVICE_10430476";
        case PciSubDevice100267B0::SUBDEVICE_104304D7: return "SUBDEVICE_104304D7";
        case PciSubDevice100267B0::SUBDEVICE_104304DB: return "SUBDEVICE_104304DB";
        case PciSubDevice100267B0::SUBDEVICE_104304DF: return "SUBDEVICE_104304DF";
        case PciSubDevice100267B0::SUBDEVICE_104304E9: return "SUBDEVICE_104304E9";
        case PciSubDevice100267B0::SUBDEVICE_1458227C: return "SUBDEVICE_1458227C";
        case PciSubDevice100267B0::SUBDEVICE_14582281: return "SUBDEVICE_14582281";
        case PciSubDevice100267B0::SUBDEVICE_1458228C: return "SUBDEVICE_1458228C";
        case PciSubDevice100267B0::SUBDEVICE_1458228D: return "SUBDEVICE_1458228D";
        case PciSubDevice100267B0::SUBDEVICE_14582290: return "SUBDEVICE_14582290";
        case PciSubDevice100267B0::SUBDEVICE_145822BC: return "SUBDEVICE_145822BC";
        case PciSubDevice100267B0::SUBDEVICE_145822C1: return "SUBDEVICE_145822C1";
        case PciSubDevice100267B0::SUBDEVICE_14622015: return "SUBDEVICE_14622015";
        case PciSubDevice100267B0::SUBDEVICE_14623070: return "SUBDEVICE_14623070";
        case PciSubDevice100267B0::SUBDEVICE_14623071: return "SUBDEVICE_14623071";
        case PciSubDevice100267B0::SUBDEVICE_14623072: return "SUBDEVICE_14623072";
        case PciSubDevice100267B0::SUBDEVICE_14623080: return "SUBDEVICE_14623080";
        case PciSubDevice100267B0::SUBDEVICE_14623082: return "SUBDEVICE_14623082";
        case PciSubDevice100267B0::SUBDEVICE_148C2347: return "SUBDEVICE_148C2347";
        case PciSubDevice100267B0::SUBDEVICE_148C2357: return "SUBDEVICE_148C2357";
        case PciSubDevice100267B0::SUBDEVICE_16829290: return "SUBDEVICE_16829290";
        case PciSubDevice100267B0::SUBDEVICE_16829395: return "SUBDEVICE_16829395";
        case PciSubDevice100267B0::SUBDEVICE_174B0E34: return "SUBDEVICE_174B0E34";
        case PciSubDevice100267B0::SUBDEVICE_174BE282: return "SUBDEVICE_174BE282";
        case PciSubDevice100267B0::SUBDEVICE_174BE285: return "SUBDEVICE_174BE285";
        case PciSubDevice100267B0::SUBDEVICE_174BE324: return "SUBDEVICE_174BE324";
        case PciSubDevice100267B0::SUBDEVICE_17872020: return "SUBDEVICE_17872020";
        case PciSubDevice100267B0::SUBDEVICE_17872357: return "SUBDEVICE_17872357";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267B0::SUBDEVICE_10280B00: return "Grenada XT [Radeon R9 390X]";
        case PciSubDevice100267B0::SUBDEVICE_103C6566: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_1043046A: return "R9 290X DirectCU II";
        case PciSubDevice100267B0::SUBDEVICE_1043046C: return "R9 290X DirectCU II OC";
        case PciSubDevice100267B0::SUBDEVICE_10430474: return "Matrix R9 290X Platinum";
        case PciSubDevice100267B0::SUBDEVICE_10430476: return "ARES III";
        case PciSubDevice100267B0::SUBDEVICE_104304D7: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_104304DB: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_104304DF: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_104304E9: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_1458227C: return "R9 290X WindForce 3X OC";
        case PciSubDevice100267B0::SUBDEVICE_14582281: return "R9 290X WindForce 3X OC";
        case PciSubDevice100267B0::SUBDEVICE_1458228C: return "R9 290X WindForce 3X";
        case PciSubDevice100267B0::SUBDEVICE_1458228D: return "R9 290X WindForce 3X OC";
        case PciSubDevice100267B0::SUBDEVICE_14582290: return "R9 290X WindForce 3X";
        case PciSubDevice100267B0::SUBDEVICE_145822BC: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_145822C1: return "Grenada PRO [Radeon R9 390]";
        case PciSubDevice100267B0::SUBDEVICE_14622015: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_14623070: return "R9 290X Lightning";
        case PciSubDevice100267B0::SUBDEVICE_14623071: return "R9 290X Lightning";
        case PciSubDevice100267B0::SUBDEVICE_14623072: return "R9 290X Lightning LE";
        case PciSubDevice100267B0::SUBDEVICE_14623080: return "R9 290X Gaming";
        case PciSubDevice100267B0::SUBDEVICE_14623082: return "R9 290X Gaming OC";
        case PciSubDevice100267B0::SUBDEVICE_148C2347: return "Devil 13 Dual Core R9 290X";
        case PciSubDevice100267B0::SUBDEVICE_148C2357: return "Grenada XT [Radeon R9 390X]";
        case PciSubDevice100267B0::SUBDEVICE_16829290: return "Double Dissipation R9 290X";
        case PciSubDevice100267B0::SUBDEVICE_16829395: return "Grenada XT [Radeon R9 390X]";
        case PciSubDevice100267B0::SUBDEVICE_174B0E34: return "Radeon R9 390X";
        case PciSubDevice100267B0::SUBDEVICE_174BE282: return "Vapor-X R9 290X Tri-X OC";
        case PciSubDevice100267B0::SUBDEVICE_174BE285: return "R9 290X Tri-X OC";
        case PciSubDevice100267B0::SUBDEVICE_174BE324: return "Grenada XT2 [Radeon R9 390X]";
        case PciSubDevice100267B0::SUBDEVICE_17872020: return "R9 290X IceQ X^2 Turbo";
        case PciSubDevice100267B0::SUBDEVICE_17872357: return "Grenada XT [Radeon R9 390X]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267B0_H
