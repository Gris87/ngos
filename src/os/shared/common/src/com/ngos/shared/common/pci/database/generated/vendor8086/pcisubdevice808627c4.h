// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627C4: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025006C = 0x1025006C,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_17AA200E = 0x17AA200E
};



inline const char8* enumToString(PciSubDevice808627C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C4::NONE:               return "NONE";
        case PciSubDevice808627C4::SUBDEVICE_1025006C: return "SUBDEVICE_1025006C";
        case PciSubDevice808627C4::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice808627C4::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice808627C4::SUBDEVICE_17AA200E: return "SUBDEVICE_17AA200E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C4::SUBDEVICE_1025006C: return "9814 WKMI";
        case PciSubDevice808627C4::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice808627C4::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice808627C4::SUBDEVICE_17AA200E: return "ThinkPad T60";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C4_H
