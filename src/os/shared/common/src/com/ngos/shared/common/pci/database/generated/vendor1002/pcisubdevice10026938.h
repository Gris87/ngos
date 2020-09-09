// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026938_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026938_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026938: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104304F5 = 0x104304F5,
    SUBDEVICE_104304F7 = 0x104304F7,
    SUBDEVICE_106B013A = 0x106B013A,
    SUBDEVICE_145822C8 = 0x145822C8,
    SUBDEVICE_148C2350 = 0x148C2350,
    SUBDEVICE_16829385 = 0x16829385,
    SUBDEVICE_174BE308 = 0x174BE308,
    SUBDEVICE_17AF2006 = 0x17AF2006
};



inline const char8* enumToString(PciSubDevice10026938 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026938::NONE:               return "NONE";
        case PciSubDevice10026938::SUBDEVICE_104304F5: return "SUBDEVICE_104304F5";
        case PciSubDevice10026938::SUBDEVICE_104304F7: return "SUBDEVICE_104304F7";
        case PciSubDevice10026938::SUBDEVICE_106B013A: return "SUBDEVICE_106B013A";
        case PciSubDevice10026938::SUBDEVICE_145822C8: return "SUBDEVICE_145822C8";
        case PciSubDevice10026938::SUBDEVICE_148C2350: return "SUBDEVICE_148C2350";
        case PciSubDevice10026938::SUBDEVICE_16829385: return "SUBDEVICE_16829385";
        case PciSubDevice10026938::SUBDEVICE_174BE308: return "SUBDEVICE_174BE308";
        case PciSubDevice10026938::SUBDEVICE_17AF2006: return "SUBDEVICE_17AF2006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026938 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026938 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026938::SUBDEVICE_104304F5: return "Radeon R9 380X";
        case PciSubDevice10026938::SUBDEVICE_104304F7: return "Radeon R9 380X";
        case PciSubDevice10026938::SUBDEVICE_106B013A: return "Radeon R9 M295X Mac Edition";
        case PciSubDevice10026938::SUBDEVICE_145822C8: return "Radeon R9 380X";
        case PciSubDevice10026938::SUBDEVICE_148C2350: return "Radeon R9 380X";
        case PciSubDevice10026938::SUBDEVICE_16829385: return "Radeon R9 380X";
        case PciSubDevice10026938::SUBDEVICE_174BE308: return "Radeon R9 380X Nitro 4G D5";
        case PciSubDevice10026938::SUBDEVICE_17AF2006: return "Radeon R9 380X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026938_H
