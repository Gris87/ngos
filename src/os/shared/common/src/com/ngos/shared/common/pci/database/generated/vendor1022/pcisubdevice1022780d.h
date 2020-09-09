// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022780D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022780D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1022780D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C194E = 0x103C194E,
    SUBDEVICE_103C1985 = 0x103C1985,
    SUBDEVICE_10438444 = 0x10438444,
    SUBDEVICE_17AA3988 = 0x17AA3988,
    SUBDEVICE_18498892 = 0x18498892
};



inline const char8* enumToString(PciSubDevice1022780D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1022780D::NONE:               return "NONE";
        case PciSubDevice1022780D::SUBDEVICE_103C194E: return "SUBDEVICE_103C194E";
        case PciSubDevice1022780D::SUBDEVICE_103C1985: return "SUBDEVICE_103C1985";
        case PciSubDevice1022780D::SUBDEVICE_10438444: return "SUBDEVICE_10438444";
        case PciSubDevice1022780D::SUBDEVICE_17AA3988: return "SUBDEVICE_17AA3988";
        case PciSubDevice1022780D::SUBDEVICE_18498892: return "SUBDEVICE_18498892";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1022780D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1022780D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1022780D::SUBDEVICE_103C194E: return "ProBook 455 G1 Notebook";
        case PciSubDevice1022780D::SUBDEVICE_103C1985: return "Pavilion 17-e163sg Notebook PC";
        case PciSubDevice1022780D::SUBDEVICE_10438444: return "F2A85-M Series";
        case PciSubDevice1022780D::SUBDEVICE_17AA3988: return "Z50-75";
        case PciSubDevice1022780D::SUBDEVICE_18498892: return "QC5000-ITX/PH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022780D_H
