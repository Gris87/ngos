// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022780E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022780E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1022780E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C194E = 0x103C194E,
    SUBDEVICE_103C1985 = 0x103C1985,
    SUBDEVICE_10438623 = 0x10438623,
    SUBDEVICE_17AA3988 = 0x17AA3988,
    SUBDEVICE_1849780E = 0x1849780E
};



inline const char8* enumToString(PciSubDevice1022780E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1022780E::NONE:               return "NONE";
        case PciSubDevice1022780E::SUBDEVICE_103C194E: return "SUBDEVICE_103C194E";
        case PciSubDevice1022780E::SUBDEVICE_103C1985: return "SUBDEVICE_103C1985";
        case PciSubDevice1022780E::SUBDEVICE_10438623: return "SUBDEVICE_10438623";
        case PciSubDevice1022780E::SUBDEVICE_17AA3988: return "SUBDEVICE_17AA3988";
        case PciSubDevice1022780E::SUBDEVICE_1849780E: return "SUBDEVICE_1849780E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1022780E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1022780E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1022780E::SUBDEVICE_103C194E: return "ProBook 455 G1 Notebook";
        case PciSubDevice1022780E::SUBDEVICE_103C1985: return "Pavilion 17-e163sg Notebook PC";
        case PciSubDevice1022780E::SUBDEVICE_10438623: return "AM1I-A Motherboard";
        case PciSubDevice1022780E::SUBDEVICE_17AA3988: return "Z50-75";
        case PciSubDevice1022780E::SUBDEVICE_1849780E: return "QC5000-ITX/PH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022780E_H
