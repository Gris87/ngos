// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10227801_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10227801_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10227801: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C168B = 0x103C168B,
    SUBDEVICE_103C194E = 0x103C194E,
    SUBDEVICE_17AA3988 = 0x17AA3988,
    SUBDEVICE_18497801 = 0x18497801
};



inline const char8* enumToString(PciSubDevice10227801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10227801::NONE:               return "NONE";
        case PciSubDevice10227801::SUBDEVICE_103C168B: return "SUBDEVICE_103C168B";
        case PciSubDevice10227801::SUBDEVICE_103C194E: return "SUBDEVICE_103C194E";
        case PciSubDevice10227801::SUBDEVICE_17AA3988: return "SUBDEVICE_17AA3988";
        case PciSubDevice10227801::SUBDEVICE_18497801: return "SUBDEVICE_18497801";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10227801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10227801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10227801::SUBDEVICE_103C168B: return "ProBook 4535s Notebook";
        case PciSubDevice10227801::SUBDEVICE_103C194E: return "ProBook 455 G1 Notebook";
        case PciSubDevice10227801::SUBDEVICE_17AA3988: return "Z50-75";
        case PciSubDevice10227801::SUBDEVICE_18497801: return "QC5000-ITX/PH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10227801_H
