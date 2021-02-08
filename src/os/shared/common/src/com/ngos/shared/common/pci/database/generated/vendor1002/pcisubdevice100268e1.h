// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268E1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043041F = 0x1043041F,
    SUBDEVICE_10433000 = 0x10433000,
    SUBDEVICE_148C3000 = 0x148C3000,
    SUBDEVICE_148C3001 = 0x148C3001,
    SUBDEVICE_148C3002 = 0x148C3002,
    SUBDEVICE_148C3003 = 0x148C3003,
    SUBDEVICE_148C7350 = 0x148C7350,
    SUBDEVICE_148C8350 = 0x148C8350,
    SUBDEVICE_15455450 = 0x15455450,
    SUBDEVICE_15457350 = 0x15457350,
    SUBDEVICE_16823000 = 0x16823000,
    SUBDEVICE_16826000 = 0x16826000,
    SUBDEVICE_16827350 = 0x16827350,
    SUBDEVICE_174B3000 = 0x174B3000,
    SUBDEVICE_174B5470 = 0x174B5470,
    SUBDEVICE_174B6000 = 0x174B6000,
    SUBDEVICE_174B6230 = 0x174B6230,
    SUBDEVICE_174B6350 = 0x174B6350,
    SUBDEVICE_174B7350 = 0x174B7350,
    SUBDEVICE_17873000 = 0x17873000,
    SUBDEVICE_17AF3000 = 0x17AF3000,
    SUBDEVICE_17AF3001 = 0x17AF3001,
    SUBDEVICE_17AF3014 = 0x17AF3014,
    SUBDEVICE_17AF3015 = 0x17AF3015,
    SUBDEVICE_17AF8350 = 0x17AF8350
};



inline const char8* enumToString(PciSubDevice100268E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268E1::NONE:               return "NONE";
        case PciSubDevice100268E1::SUBDEVICE_1043041F: return "SUBDEVICE_1043041F";
        case PciSubDevice100268E1::SUBDEVICE_10433000: return "SUBDEVICE_10433000";
        case PciSubDevice100268E1::SUBDEVICE_148C3000: return "SUBDEVICE_148C3000";
        case PciSubDevice100268E1::SUBDEVICE_148C3001: return "SUBDEVICE_148C3001";
        case PciSubDevice100268E1::SUBDEVICE_148C3002: return "SUBDEVICE_148C3002";
        case PciSubDevice100268E1::SUBDEVICE_148C3003: return "SUBDEVICE_148C3003";
        case PciSubDevice100268E1::SUBDEVICE_148C7350: return "SUBDEVICE_148C7350";
        case PciSubDevice100268E1::SUBDEVICE_148C8350: return "SUBDEVICE_148C8350";
        case PciSubDevice100268E1::SUBDEVICE_15455450: return "SUBDEVICE_15455450";
        case PciSubDevice100268E1::SUBDEVICE_15457350: return "SUBDEVICE_15457350";
        case PciSubDevice100268E1::SUBDEVICE_16823000: return "SUBDEVICE_16823000";
        case PciSubDevice100268E1::SUBDEVICE_16826000: return "SUBDEVICE_16826000";
        case PciSubDevice100268E1::SUBDEVICE_16827350: return "SUBDEVICE_16827350";
        case PciSubDevice100268E1::SUBDEVICE_174B3000: return "SUBDEVICE_174B3000";
        case PciSubDevice100268E1::SUBDEVICE_174B5470: return "SUBDEVICE_174B5470";
        case PciSubDevice100268E1::SUBDEVICE_174B6000: return "SUBDEVICE_174B6000";
        case PciSubDevice100268E1::SUBDEVICE_174B6230: return "SUBDEVICE_174B6230";
        case PciSubDevice100268E1::SUBDEVICE_174B6350: return "SUBDEVICE_174B6350";
        case PciSubDevice100268E1::SUBDEVICE_174B7350: return "SUBDEVICE_174B7350";
        case PciSubDevice100268E1::SUBDEVICE_17873000: return "SUBDEVICE_17873000";
        case PciSubDevice100268E1::SUBDEVICE_17AF3000: return "SUBDEVICE_17AF3000";
        case PciSubDevice100268E1::SUBDEVICE_17AF3001: return "SUBDEVICE_17AF3001";
        case PciSubDevice100268E1::SUBDEVICE_17AF3014: return "SUBDEVICE_17AF3014";
        case PciSubDevice100268E1::SUBDEVICE_17AF3015: return "SUBDEVICE_17AF3015";
        case PciSubDevice100268E1::SUBDEVICE_17AF8350: return "SUBDEVICE_17AF8350";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268E1::SUBDEVICE_1043041F: return "Caicos [Radeon HD 7350]";
        case PciSubDevice100268E1::SUBDEVICE_10433000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_148C3000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_148C3001: return "Caicos [Radeon HD 6230]";
        case PciSubDevice100268E1::SUBDEVICE_148C3002: return "Caicos [Radeon HD 6250]";
        case PciSubDevice100268E1::SUBDEVICE_148C3003: return "Caicos [Radeon HD 6350]";
        case PciSubDevice100268E1::SUBDEVICE_148C7350: return "Caicos [Radeon HD 7350]";
        case PciSubDevice100268E1::SUBDEVICE_148C8350: return "Caicos [Radeon HD 8350]";
        case PciSubDevice100268E1::SUBDEVICE_15455450: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_15457350: return "Caicos [Radeon HD 7350]";
        case PciSubDevice100268E1::SUBDEVICE_16823000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_16826000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_16827350: return "Caicos [Radeon HD 7350]";
        case PciSubDevice100268E1::SUBDEVICE_174B3000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_174B5470: return "Caicos [Radeon HD 5470]";
        case PciSubDevice100268E1::SUBDEVICE_174B6000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_174B6230: return "Caicos [Radeon HD 6230]";
        case PciSubDevice100268E1::SUBDEVICE_174B6350: return "Caicos [Radeon HD 6350]";
        case PciSubDevice100268E1::SUBDEVICE_174B7350: return "Caicos [Radeon HD 7350]";
        case PciSubDevice100268E1::SUBDEVICE_17873000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_17AF3000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E1::SUBDEVICE_17AF3001: return "Caicos [Radeon HD 6230]";
        case PciSubDevice100268E1::SUBDEVICE_17AF3014: return "Caicos [Radeon HD 6350]";
        case PciSubDevice100268E1::SUBDEVICE_17AF3015: return "Caicos [Radeon HD 7350]";
        case PciSubDevice100268E1::SUBDEVICE_17AF8350: return "Caicos [Radeon HD 8350 OEM]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E1_H
