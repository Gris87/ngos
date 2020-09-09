// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808608B3: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860060 = 0x80860060,
    SUBDEVICE_80860062 = 0x80860062,
    SUBDEVICE_80860070 = 0x80860070,
    SUBDEVICE_80860072 = 0x80860072,
    SUBDEVICE_80860170 = 0x80860170,
    SUBDEVICE_80860172 = 0x80860172,
    SUBDEVICE_80860260 = 0x80860260,
    SUBDEVICE_80860470 = 0x80860470,
    SUBDEVICE_80860472 = 0x80860472,
    SUBDEVICE_80861070 = 0x80861070,
    SUBDEVICE_80861170 = 0x80861170,
    SUBDEVICE_80868060 = 0x80868060,
    SUBDEVICE_80868062 = 0x80868062,
    SUBDEVICE_80868070 = 0x80868070,
    SUBDEVICE_80868072 = 0x80868072,
    SUBDEVICE_80868170 = 0x80868170,
    SUBDEVICE_80868172 = 0x80868172,
    SUBDEVICE_80868470 = 0x80868470,
    SUBDEVICE_80868570 = 0x80868570
};



inline const char8* enumToString(PciSubDevice808608B3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608B3::NONE:               return "NONE";
        case PciSubDevice808608B3::SUBDEVICE_80860060: return "SUBDEVICE_80860060";
        case PciSubDevice808608B3::SUBDEVICE_80860062: return "SUBDEVICE_80860062";
        case PciSubDevice808608B3::SUBDEVICE_80860070: return "SUBDEVICE_80860070";
        case PciSubDevice808608B3::SUBDEVICE_80860072: return "SUBDEVICE_80860072";
        case PciSubDevice808608B3::SUBDEVICE_80860170: return "SUBDEVICE_80860170";
        case PciSubDevice808608B3::SUBDEVICE_80860172: return "SUBDEVICE_80860172";
        case PciSubDevice808608B3::SUBDEVICE_80860260: return "SUBDEVICE_80860260";
        case PciSubDevice808608B3::SUBDEVICE_80860470: return "SUBDEVICE_80860470";
        case PciSubDevice808608B3::SUBDEVICE_80860472: return "SUBDEVICE_80860472";
        case PciSubDevice808608B3::SUBDEVICE_80861070: return "SUBDEVICE_80861070";
        case PciSubDevice808608B3::SUBDEVICE_80861170: return "SUBDEVICE_80861170";
        case PciSubDevice808608B3::SUBDEVICE_80868060: return "SUBDEVICE_80868060";
        case PciSubDevice808608B3::SUBDEVICE_80868062: return "SUBDEVICE_80868062";
        case PciSubDevice808608B3::SUBDEVICE_80868070: return "SUBDEVICE_80868070";
        case PciSubDevice808608B3::SUBDEVICE_80868072: return "SUBDEVICE_80868072";
        case PciSubDevice808608B3::SUBDEVICE_80868170: return "SUBDEVICE_80868170";
        case PciSubDevice808608B3::SUBDEVICE_80868172: return "SUBDEVICE_80868172";
        case PciSubDevice808608B3::SUBDEVICE_80868470: return "SUBDEVICE_80868470";
        case PciSubDevice808608B3::SUBDEVICE_80868570: return "SUBDEVICE_80868570";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808608B3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808608B3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608B3::SUBDEVICE_80860060: return "Dual Band Wireless-N 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860062: return "Wireless-N 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860070: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860072: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860170: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860172: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860260: return "Dual Band Wireless-N 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860470: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80860472: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80861070: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80861170: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80868060: return "Dual Band Wireless N-3160";
        case PciSubDevice808608B3::SUBDEVICE_80868062: return "Wireless N-3160";
        case PciSubDevice808608B3::SUBDEVICE_80868070: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80868072: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80868170: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80868172: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80868470: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B3::SUBDEVICE_80868570: return "Dual Band Wireless AC 3160";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B3_H
