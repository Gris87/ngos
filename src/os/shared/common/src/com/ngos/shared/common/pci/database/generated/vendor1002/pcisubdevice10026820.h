// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026820_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026820_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026820: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1851 = 0x103C1851,
    SUBDEVICE_17AA3643 = 0x17AA3643,
    SUBDEVICE_17AA3801 = 0x17AA3801,
    SUBDEVICE_17AA3824 = 0x17AA3824,
    SUBDEVICE_1DA2E26A = 0x1DA2E26A
};



inline const char8* enumToString(PciSubDevice10026820 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026820::NONE:               return "NONE";
        case PciSubDevice10026820::SUBDEVICE_103C1851: return "SUBDEVICE_103C1851";
        case PciSubDevice10026820::SUBDEVICE_17AA3643: return "SUBDEVICE_17AA3643";
        case PciSubDevice10026820::SUBDEVICE_17AA3801: return "SUBDEVICE_17AA3801";
        case PciSubDevice10026820::SUBDEVICE_17AA3824: return "SUBDEVICE_17AA3824";
        case PciSubDevice10026820::SUBDEVICE_1DA2E26A: return "SUBDEVICE_1DA2E26A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026820 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026820 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026820::SUBDEVICE_103C1851: return "Radeon HD 7750M";
        case PciSubDevice10026820::SUBDEVICE_17AA3643: return "Radeon R9 A375";
        case PciSubDevice10026820::SUBDEVICE_17AA3801: return "Radeon R9 M275";
        case PciSubDevice10026820::SUBDEVICE_17AA3824: return "Radeon R9 M375";
        case PciSubDevice10026820::SUBDEVICE_1DA2E26A: return "Radeon R7 250";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026820_H
