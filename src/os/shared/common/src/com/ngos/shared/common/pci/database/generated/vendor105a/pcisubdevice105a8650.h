// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A8650_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A8650_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A8650: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105A4600 = 0x105A4600,
    SUBDEVICE_105A4601 = 0x105A4601,
    SUBDEVICE_105A4610 = 0x105A4610,
    SUBDEVICE_105A8600 = 0x105A8600,
    SUBDEVICE_105A8601 = 0x105A8601,
    SUBDEVICE_105A8602 = 0x105A8602,
    SUBDEVICE_105A8603 = 0x105A8603,
    SUBDEVICE_105A8604 = 0x105A8604,
    SUBDEVICE_105A8610 = 0x105A8610,
    SUBDEVICE_105AA600 = 0x105AA600,
    SUBDEVICE_105AB600 = 0x105AB600,
    SUBDEVICE_105AB601 = 0x105AB601,
    SUBDEVICE_105AB602 = 0x105AB602
};



inline const char8* enumToString(PciSubDevice105A8650 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A8650::NONE:               return "NONE";
        case PciSubDevice105A8650::SUBDEVICE_105A4600: return "SUBDEVICE_105A4600";
        case PciSubDevice105A8650::SUBDEVICE_105A4601: return "SUBDEVICE_105A4601";
        case PciSubDevice105A8650::SUBDEVICE_105A4610: return "SUBDEVICE_105A4610";
        case PciSubDevice105A8650::SUBDEVICE_105A8600: return "SUBDEVICE_105A8600";
        case PciSubDevice105A8650::SUBDEVICE_105A8601: return "SUBDEVICE_105A8601";
        case PciSubDevice105A8650::SUBDEVICE_105A8602: return "SUBDEVICE_105A8602";
        case PciSubDevice105A8650::SUBDEVICE_105A8603: return "SUBDEVICE_105A8603";
        case PciSubDevice105A8650::SUBDEVICE_105A8604: return "SUBDEVICE_105A8604";
        case PciSubDevice105A8650::SUBDEVICE_105A8610: return "SUBDEVICE_105A8610";
        case PciSubDevice105A8650::SUBDEVICE_105AA600: return "SUBDEVICE_105AA600";
        case PciSubDevice105A8650::SUBDEVICE_105AB600: return "SUBDEVICE_105AB600";
        case PciSubDevice105A8650::SUBDEVICE_105AB601: return "SUBDEVICE_105AB601";
        case PciSubDevice105A8650::SUBDEVICE_105AB602: return "SUBDEVICE_105AB602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A8650 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A8650 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A8650::SUBDEVICE_105A4600: return "SuperTrak EX4650A";
        case PciSubDevice105A8650::SUBDEVICE_105A4601: return "SuperTrak EX4650";
        case PciSubDevice105A8650::SUBDEVICE_105A4610: return "SuperTrak EX4650EL";
        case PciSubDevice105A8650::SUBDEVICE_105A8600: return "SuperTrak EX8650EL";
        case PciSubDevice105A8650::SUBDEVICE_105A8601: return "SuperTrak EX8650A";
        case PciSubDevice105A8650::SUBDEVICE_105A8602: return "SuperTrak EX8654";
        case PciSubDevice105A8650::SUBDEVICE_105A8603: return "SuperTrak EX8658";
        case PciSubDevice105A8650::SUBDEVICE_105A8604: return "SuperTrak EX8650";
        case PciSubDevice105A8650::SUBDEVICE_105A8610: return "SuperTrak EX8650M";
        case PciSubDevice105A8650::SUBDEVICE_105AA600: return "SuperTrak EX12650";
        case PciSubDevice105A8650::SUBDEVICE_105AB600: return "SuperTrak EX16650";
        case PciSubDevice105A8650::SUBDEVICE_105AB601: return "SuperTrak EX16654";
        case PciSubDevice105A8650::SUBDEVICE_105AB602: return "SuperTrak EX16658";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A8650_H
