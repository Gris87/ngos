// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A4D30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A4D30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A4D30: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105A4D33 = 0x105A4D33,
    SUBDEVICE_105A4D39 = 0x105A4D39,
    SUBDEVICE_80865744 = 0x80865744
};



inline const char8* enumToString(PciSubDevice105A4D30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A4D30::NONE:               return "NONE";
        case PciSubDevice105A4D30::SUBDEVICE_105A4D33: return "SUBDEVICE_105A4D33";
        case PciSubDevice105A4D30::SUBDEVICE_105A4D39: return "SUBDEVICE_105A4D39";
        case PciSubDevice105A4D30::SUBDEVICE_80865744: return "SUBDEVICE_80865744";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A4D30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A4D30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A4D30::SUBDEVICE_105A4D33: return "Ultra100";
        case PciSubDevice105A4D30::SUBDEVICE_105A4D39: return "FastTrak100";
        case PciSubDevice105A4D30::SUBDEVICE_80865744: return "S845WD1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A4D30_H
