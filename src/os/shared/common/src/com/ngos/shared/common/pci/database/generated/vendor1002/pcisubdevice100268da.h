// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268DA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268DA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268DA: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14628071 = 0x14628071,
    SUBDEVICE_148C3000 = 0x148C3000,
    SUBDEVICE_148C3001 = 0x148C3001,
    SUBDEVICE_15457570 = 0x15457570,
    SUBDEVICE_174B3000 = 0x174B3000,
    SUBDEVICE_174B5570 = 0x174B5570,
    SUBDEVICE_174B5630 = 0x174B5630,
    SUBDEVICE_174B6490 = 0x174B6490,
    SUBDEVICE_17873000 = 0x17873000,
    SUBDEVICE_17AF3000 = 0x17AF3000,
    SUBDEVICE_17AF3010 = 0x17AF3010
};



inline const char8* enumToString(PciSubDevice100268DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268DA::NONE:               return "NONE";
        case PciSubDevice100268DA::SUBDEVICE_14628071: return "SUBDEVICE_14628071";
        case PciSubDevice100268DA::SUBDEVICE_148C3000: return "SUBDEVICE_148C3000";
        case PciSubDevice100268DA::SUBDEVICE_148C3001: return "SUBDEVICE_148C3001";
        case PciSubDevice100268DA::SUBDEVICE_15457570: return "SUBDEVICE_15457570";
        case PciSubDevice100268DA::SUBDEVICE_174B3000: return "SUBDEVICE_174B3000";
        case PciSubDevice100268DA::SUBDEVICE_174B5570: return "SUBDEVICE_174B5570";
        case PciSubDevice100268DA::SUBDEVICE_174B5630: return "SUBDEVICE_174B5630";
        case PciSubDevice100268DA::SUBDEVICE_174B6490: return "SUBDEVICE_174B6490";
        case PciSubDevice100268DA::SUBDEVICE_17873000: return "SUBDEVICE_17873000";
        case PciSubDevice100268DA::SUBDEVICE_17AF3000: return "SUBDEVICE_17AF3000";
        case PciSubDevice100268DA::SUBDEVICE_17AF3010: return "SUBDEVICE_17AF3010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268DA::SUBDEVICE_14628071: return "VR5550-MD1G (Radeon HD 5550)";
        case PciSubDevice100268DA::SUBDEVICE_148C3000: return "Radeon HD 6390";
        case PciSubDevice100268DA::SUBDEVICE_148C3001: return "Radeon HD 6490";
        case PciSubDevice100268DA::SUBDEVICE_15457570: return "Radeon HD 7570";
        case PciSubDevice100268DA::SUBDEVICE_174B3000: return "Radeon HD 6390";
        case PciSubDevice100268DA::SUBDEVICE_174B5570: return "Radeon HD 5570";
        case PciSubDevice100268DA::SUBDEVICE_174B5630: return "Radeon HD 5630";
        case PciSubDevice100268DA::SUBDEVICE_174B6490: return "Radeon HD 6490";
        case PciSubDevice100268DA::SUBDEVICE_17873000: return "Radeon HD 5630";
        case PciSubDevice100268DA::SUBDEVICE_17AF3000: return "Radeon HD 6390";
        case PciSubDevice100268DA::SUBDEVICE_17AF3010: return "Radeon HD 5630";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268DA_H
