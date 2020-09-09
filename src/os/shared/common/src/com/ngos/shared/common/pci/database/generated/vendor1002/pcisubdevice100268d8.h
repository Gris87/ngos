// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268D8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268D8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268D8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102868E0 = 0x102868E0,
    SUBDEVICE_174B5690 = 0x174B5690,
    SUBDEVICE_174B5730 = 0x174B5730,
    SUBDEVICE_174BE151 = 0x174BE151,
    SUBDEVICE_17873000 = 0x17873000,
    SUBDEVICE_17AF3010 = 0x17AF3010,
    SUBDEVICE_17AF3011 = 0x17AF3011
};



inline const char8* enumToString(PciSubDevice100268D8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268D8::NONE:               return "NONE";
        case PciSubDevice100268D8::SUBDEVICE_102868E0: return "SUBDEVICE_102868E0";
        case PciSubDevice100268D8::SUBDEVICE_174B5690: return "SUBDEVICE_174B5690";
        case PciSubDevice100268D8::SUBDEVICE_174B5730: return "SUBDEVICE_174B5730";
        case PciSubDevice100268D8::SUBDEVICE_174BE151: return "SUBDEVICE_174BE151";
        case PciSubDevice100268D8::SUBDEVICE_17873000: return "SUBDEVICE_17873000";
        case PciSubDevice100268D8::SUBDEVICE_17AF3010: return "SUBDEVICE_17AF3010";
        case PciSubDevice100268D8::SUBDEVICE_17AF3011: return "SUBDEVICE_17AF3011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268D8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268D8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268D8::SUBDEVICE_102868E0: return "Radeon HD 5670";
        case PciSubDevice100268D8::SUBDEVICE_174B5690: return "Radeon HD 5690";
        case PciSubDevice100268D8::SUBDEVICE_174B5730: return "Radeon HD 5730";
        case PciSubDevice100268D8::SUBDEVICE_174BE151: return "Radeon HD 5670";
        case PciSubDevice100268D8::SUBDEVICE_17873000: return "Radeon HD 5730";
        case PciSubDevice100268D8::SUBDEVICE_17AF3010: return "Radeon HD 5730";
        case PciSubDevice100268D8::SUBDEVICE_17AF3011: return "Radeon HD 5690";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268D8_H
