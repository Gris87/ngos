// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862725_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862725_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862725: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860020 = 0x80860020,
    SUBDEVICE_80860024 = 0x80860024,
    SUBDEVICE_80860090 = 0x80860090,
    SUBDEVICE_808600B0 = 0x808600B0,
    SUBDEVICE_80860310 = 0x80860310,
    SUBDEVICE_80860510 = 0x80860510,
    SUBDEVICE_80860A10 = 0x80860A10,
    SUBDEVICE_80862020 = 0x80862020,
    SUBDEVICE_80864020 = 0x80864020,
    SUBDEVICE_80866020 = 0x80866020,
    SUBDEVICE_80866024 = 0x80866024,
    SUBDEVICE_8086E020 = 0x8086E020,
    SUBDEVICE_8086E024 = 0x8086E024
};



inline const char8* enumToString(PciSubDevice80862725 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862725::NONE:               return "NONE";
        case PciSubDevice80862725::SUBDEVICE_80860020: return "SUBDEVICE_80860020";
        case PciSubDevice80862725::SUBDEVICE_80860024: return "SUBDEVICE_80860024";
        case PciSubDevice80862725::SUBDEVICE_80860090: return "SUBDEVICE_80860090";
        case PciSubDevice80862725::SUBDEVICE_808600B0: return "SUBDEVICE_808600B0";
        case PciSubDevice80862725::SUBDEVICE_80860310: return "SUBDEVICE_80860310";
        case PciSubDevice80862725::SUBDEVICE_80860510: return "SUBDEVICE_80860510";
        case PciSubDevice80862725::SUBDEVICE_80860A10: return "SUBDEVICE_80860A10";
        case PciSubDevice80862725::SUBDEVICE_80862020: return "SUBDEVICE_80862020";
        case PciSubDevice80862725::SUBDEVICE_80864020: return "SUBDEVICE_80864020";
        case PciSubDevice80862725::SUBDEVICE_80866020: return "SUBDEVICE_80866020";
        case PciSubDevice80862725::SUBDEVICE_80866024: return "SUBDEVICE_80866024";
        case PciSubDevice80862725::SUBDEVICE_8086E020: return "SUBDEVICE_8086E020";
        case PciSubDevice80862725::SUBDEVICE_8086E024: return "SUBDEVICE_8086E024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862725 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862725 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862725::SUBDEVICE_80860020: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80860024: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80860090: return "Wi-Fi 6 AX211 160MHz";
        case PciSubDevice80862725::SUBDEVICE_808600B0: return "Wi-Fi 6 AX411 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80860310: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80860510: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80860A10: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80862020: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80864020: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80866020: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_80866024: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_8086E020: return "Wi-Fi 6 AX210 160MHz";
        case PciSubDevice80862725::SUBDEVICE_8086E024: return "Wi-Fi 6 AX210 160MHz";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862725_H
