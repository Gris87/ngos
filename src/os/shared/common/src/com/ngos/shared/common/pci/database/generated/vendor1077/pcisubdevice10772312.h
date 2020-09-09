// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772312_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772312_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772312: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C0131 = 0x103C0131,
    SUBDEVICE_103C12BA = 0x103C12BA
};



inline const char8* enumToString(PciSubDevice10772312 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772312::NONE:               return "NONE";
        case PciSubDevice10772312::SUBDEVICE_103C0131: return "SUBDEVICE_103C0131";
        case PciSubDevice10772312::SUBDEVICE_103C12BA: return "SUBDEVICE_103C12BA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772312 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772312 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772312::SUBDEVICE_103C0131: return "2Gb Fibre Channel - Single port [A7538A]";
        case PciSubDevice10772312::SUBDEVICE_103C12BA: return "2Gb Fibre Channel - Dual port [A6826A]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772312_H
