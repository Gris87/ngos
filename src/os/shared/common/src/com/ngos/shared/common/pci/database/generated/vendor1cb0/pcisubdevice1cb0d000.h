// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB0D000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB0D000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1CB0D000: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1CB02010 = 0x1CB02010,
    SUBDEVICE_1CB02011 = 0x1CB02011,
    SUBDEVICE_1CB02012 = 0x1CB02012,
    SUBDEVICE_1CB02F10 = 0x1CB02F10,
    SUBDEVICE_1CB02F11 = 0x1CB02F11,
    SUBDEVICE_1CB02F12 = 0x1CB02F12,
    SUBDEVICE_1CB0A010 = 0x1CB0A010,
    SUBDEVICE_1CB0A012 = 0x1CB0A012,
    SUBDEVICE_1CB0AF10 = 0x1CB0AF10,
    SUBDEVICE_1CB0AF12 = 0x1CB0AF12
};



inline const char8* enumToString(PciSubDevice1CB0D000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CB0D000::NONE:               return "NONE";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02010: return "SUBDEVICE_1CB02010";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02011: return "SUBDEVICE_1CB02011";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02012: return "SUBDEVICE_1CB02012";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F10: return "SUBDEVICE_1CB02F10";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F11: return "SUBDEVICE_1CB02F11";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F12: return "SUBDEVICE_1CB02F12";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0A010: return "SUBDEVICE_1CB0A010";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0A012: return "SUBDEVICE_1CB0A012";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF10: return "SUBDEVICE_1CB0AF10";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF12: return "SUBDEVICE_1CB0AF12";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1CB0D000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1CB0D000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02010: return "Venice-E Series OCS U.2";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02011: return "Venice Series OCS U.2";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02012: return "Venice-X Series OCS U.2";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F10: return "Venice-E Series NVMe U.2";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F11: return "Venice Series NVMe U.2";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB02F12: return "Venice-X Series NVMe U.2";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0A010: return "Venice-E Series OCS AIC";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0A012: return "Venice-X Series OCS AIC";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF10: return "Venice-E Series NVMe AIC";
        case PciSubDevice1CB0D000::SUBDEVICE_1CB0AF12: return "Venice-X Series NVMe AIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB0D000_H
