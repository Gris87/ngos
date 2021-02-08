// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808608B4: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860270 = 0x80860270,
    SUBDEVICE_80860272 = 0x80860272,
    SUBDEVICE_80860370 = 0x80860370,
    SUBDEVICE_80868260 = 0x80868260,
    SUBDEVICE_80868270 = 0x80868270,
    SUBDEVICE_80868272 = 0x80868272,
    SUBDEVICE_80868370 = 0x80868370
};



inline const char8* enumToString(PciSubDevice808608B4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608B4::NONE:               return "NONE";
        case PciSubDevice808608B4::SUBDEVICE_80860270: return "SUBDEVICE_80860270";
        case PciSubDevice808608B4::SUBDEVICE_80860272: return "SUBDEVICE_80860272";
        case PciSubDevice808608B4::SUBDEVICE_80860370: return "SUBDEVICE_80860370";
        case PciSubDevice808608B4::SUBDEVICE_80868260: return "SUBDEVICE_80868260";
        case PciSubDevice808608B4::SUBDEVICE_80868270: return "SUBDEVICE_80868270";
        case PciSubDevice808608B4::SUBDEVICE_80868272: return "SUBDEVICE_80868272";
        case PciSubDevice808608B4::SUBDEVICE_80868370: return "SUBDEVICE_80868370";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808608B4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808608B4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608B4::SUBDEVICE_80860270: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B4::SUBDEVICE_80860272: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B4::SUBDEVICE_80860370: return "Dual Band Wireless-AC 3160";
        case PciSubDevice808608B4::SUBDEVICE_80868260: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B4::SUBDEVICE_80868270: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B4::SUBDEVICE_80868272: return "Dual Band Wireless AC 3160";
        case PciSubDevice808608B4::SUBDEVICE_80868370: return "Dual Band Wireless AC 3160";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608B4_H
