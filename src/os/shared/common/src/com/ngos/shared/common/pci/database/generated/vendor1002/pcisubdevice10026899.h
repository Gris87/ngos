// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026899_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026899_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026899: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430330 = 0x10430330,
    SUBDEVICE_174B237B = 0x174B237B,
    SUBDEVICE_174B6850 = 0x174B6850
};



inline const char8* enumToString(PciSubDevice10026899 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026899::NONE:               return "NONE";
        case PciSubDevice10026899::SUBDEVICE_10430330: return "SUBDEVICE_10430330";
        case PciSubDevice10026899::SUBDEVICE_174B237B: return "SUBDEVICE_174B237B";
        case PciSubDevice10026899::SUBDEVICE_174B6850: return "SUBDEVICE_174B6850";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026899 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026899 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026899::SUBDEVICE_10430330: return "Radeon HD 5850";
        case PciSubDevice10026899::SUBDEVICE_174B237B: return "Radeon HD 5850 X2";
        case PciSubDevice10026899::SUBDEVICE_174B6850: return "Radeon HD 6850 1440SP Edition";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026899_H
