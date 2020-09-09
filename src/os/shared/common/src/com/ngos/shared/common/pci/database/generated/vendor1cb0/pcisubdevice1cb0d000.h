// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB0D000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB0D000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1CB0D000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1CB02F10 = 0x1CB02F10,
    SUBDEVICE_1CB02F11 = 0x1CB02F11,
    SUBDEVICE_1CB02F12 = 0x1CB02F12,
    SUBDEVICE_1CB0AF10 = 0x1CB0AF10,
    SUBDEVICE_1CB0AF11 = 0x1CB0AF11,
    SUBDEVICE_1CB0AF12 = 0x1CB0AF12
};



inline const char8* enumToString(PciSubDevice1CB0D000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CB0D000::NONE:               return "NONE";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F10: return "SUBDEVICE_1CB02F10";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F11: return "SUBDEVICE_1CB02F11";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F12: return "SUBDEVICE_1CB02F12";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF10: return "SUBDEVICE_1CB0AF10";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF11: return "SUBDEVICE_1CB0AF11";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF12: return "SUBDEVICE_1CB0AF12";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1CB0D000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1CB0D000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F10: return "Venice-E Series U.2 SSD";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F11: return "Venice Series U.2 SSD";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F12: return "Venice-X Series U.2 SSD";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF10: return "Venice-E Series AIC SSD";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF11: return "Venice Series AIC SSD";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF12: return "Venice-X Series AIC SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB0D000_H
