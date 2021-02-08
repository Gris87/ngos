// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A4D38_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A4D38_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A4D38: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105A4D30 = 0x105A4D30,
    SUBDEVICE_105A4D33 = 0x105A4D33,
    SUBDEVICE_105A4D39 = 0x105A4D39
};



inline const char8* enumToString(PciSubDevice105A4D38 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A4D38::NONE:               return "NONE";
        case PciSubDevice105A4D38::SUBDEVICE_105A4D30: return "SUBDEVICE_105A4D30";
        case PciSubDevice105A4D38::SUBDEVICE_105A4D33: return "SUBDEVICE_105A4D33";
        case PciSubDevice105A4D38::SUBDEVICE_105A4D39: return "SUBDEVICE_105A4D39";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A4D38 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A4D38 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A4D38::SUBDEVICE_105A4D30: return "Ultra Device on SuperTrak";
        case PciSubDevice105A4D38::SUBDEVICE_105A4D33: return "Ultra66";
        case PciSubDevice105A4D38::SUBDEVICE_105A4D39: return "FastTrak66";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A4D38_H
