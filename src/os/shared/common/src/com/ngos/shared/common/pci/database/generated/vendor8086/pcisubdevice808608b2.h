// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808608B2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80864220 = 0x80864220,
    SUBDEVICE_80864260 = 0x80864260,
    SUBDEVICE_80864262 = 0x80864262,
    SUBDEVICE_8086426A = 0x8086426A,
    SUBDEVICE_80864270 = 0x80864270,
    SUBDEVICE_80864272 = 0x80864272,
    SUBDEVICE_80864360 = 0x80864360,
    SUBDEVICE_80864370 = 0x80864370,
    SUBDEVICE_8086C220 = 0x8086C220,
    SUBDEVICE_8086C260 = 0x8086C260,
    SUBDEVICE_8086C262 = 0x8086C262,
    SUBDEVICE_8086C26A = 0x8086C26A,
    SUBDEVICE_8086C270 = 0x8086C270,
    SUBDEVICE_8086C272 = 0x8086C272,
    SUBDEVICE_8086C370 = 0x8086C370
};



inline const char8* enumToString(PciSubDevice808608B2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608B2::NONE:               return "NONE";
        case PciSubDevice808608B2::SUBDEVICE_80864220: return "SUBDEVICE_80864220";
        case PciSubDevice808608B2::SUBDEVICE_80864260: return "SUBDEVICE_80864260";
        case PciSubDevice808608B2::SUBDEVICE_80864262: return "SUBDEVICE_80864262";
        case PciSubDevice808608B2::SUBDEVICE_8086426A: return "SUBDEVICE_8086426A";
        case PciSubDevice808608B2::SUBDEVICE_80864270: return "SUBDEVICE_80864270";
        case PciSubDevice808608B2::SUBDEVICE_80864272: return "SUBDEVICE_80864272";
        case PciSubDevice808608B2::SUBDEVICE_80864360: return "SUBDEVICE_80864360";
        case PciSubDevice808608B2::SUBDEVICE_80864370: return "SUBDEVICE_80864370";
        case PciSubDevice808608B2::SUBDEVICE_8086C220: return "SUBDEVICE_8086C220";
        case PciSubDevice808608B2::SUBDEVICE_8086C260: return "SUBDEVICE_8086C260";
        case PciSubDevice808608B2::SUBDEVICE_8086C262: return "SUBDEVICE_8086C262";
        case PciSubDevice808608B2::SUBDEVICE_8086C26A: return "SUBDEVICE_8086C26A";
        case PciSubDevice808608B2::SUBDEVICE_8086C270: return "SUBDEVICE_8086C270";
        case PciSubDevice808608B2::SUBDEVICE_8086C272: return "SUBDEVICE_8086C272";
        case PciSubDevice808608B2::SUBDEVICE_8086C370: return "SUBDEVICE_8086C370";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808608B2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808608B2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608B2::SUBDEVICE_80864220: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_80864260: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_80864262: return "Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086426A: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_80864270: return "Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_80864272: return "Dual Band Wireless-AC 7260";
        case PciSubDevice808608B2::SUBDEVICE_80864360: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_80864370: return "Dual Band Wireless-AC 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C220: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C260: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C262: return "Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C26A: return "Dual Band Wireless-N 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C270: return "Dual Band Wireless-AC 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C272: return "Dual Band Wireless-AC 7260";
        case PciSubDevice808608B2::SUBDEVICE_8086C370: return "Dual Band Wireless-AC 7260";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B2_H
