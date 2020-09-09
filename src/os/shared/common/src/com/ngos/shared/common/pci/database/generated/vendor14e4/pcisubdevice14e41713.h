// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41713_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41713_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41713: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_10280209 = 0x10280209,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_17AA3A23 = 0x17AA3A23
};



inline const char8* enumToString(PciSubDevice14E41713 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41713::NONE:               return "NONE";
        case PciSubDevice14E41713::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice14E41713::SUBDEVICE_10280209: return "SUBDEVICE_10280209";
        case PciSubDevice14E41713::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice14E41713::SUBDEVICE_17AA3A23: return "SUBDEVICE_17AA3A23";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41713 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41713 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41713::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice14E41713::SUBDEVICE_10280209: return "XPS M1330";
        case PciSubDevice14E41713::SUBDEVICE_103C30C0: return "Compaq 6710b";
        case PciSubDevice14E41713::SUBDEVICE_17AA3A23: return "IdeaPad S10e";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41713_H
