// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863591_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863591_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863591: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101402DD = 0x101402DD,
    SUBDEVICE_10280168 = 0x10280168,
    SUBDEVICE_10280169 = 0x10280169,
    SUBDEVICE_103C3208 = 0x103C3208,
    SUBDEVICE_4C5310D0 = 0x4C5310D0
};



inline const char8* enumToString(PciSubDevice80863591 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863591::NONE:               return "NONE";
        case PciSubDevice80863591::SUBDEVICE_101402DD: return "SUBDEVICE_101402DD";
        case PciSubDevice80863591::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice80863591::SUBDEVICE_10280169: return "SUBDEVICE_10280169";
        case PciSubDevice80863591::SUBDEVICE_103C3208: return "SUBDEVICE_103C3208";
        case PciSubDevice80863591::SUBDEVICE_4C5310D0: return "SUBDEVICE_4C5310D0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863591 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863591 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863591::SUBDEVICE_101402DD: return "eServer xSeries server mainboard";
        case PciSubDevice80863591::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice80863591::SUBDEVICE_10280169: return "Precision 470";
        case PciSubDevice80863591::SUBDEVICE_103C3208: return "ProLiant DL140 G2";
        case PciSubDevice80863591::SUBDEVICE_4C5310D0: return "Telum ASLP10 Processor AMC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863591_H
