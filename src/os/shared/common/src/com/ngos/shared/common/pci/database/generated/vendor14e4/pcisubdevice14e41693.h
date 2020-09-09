// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41693_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41693_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41693: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_17AA20D5 = 0x17AA20D5
};



inline const char8* enumToString(PciSubDevice14E41693 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41693::NONE:               return "NONE";
        case PciSubDevice14E41693::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice14E41693::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice14E41693::SUBDEVICE_17AA20D5: return "SUBDEVICE_17AA20D5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41693 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41693 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41693::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice14E41693::SUBDEVICE_103C30C0: return "6710b";
        case PciSubDevice14E41693::SUBDEVICE_17AA20D5: return "ThinkPad R61";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41693_H
