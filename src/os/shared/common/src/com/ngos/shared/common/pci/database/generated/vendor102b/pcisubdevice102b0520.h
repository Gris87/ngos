// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0520_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0520_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B0520: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102BDBC2 = 0x102BDBC2,
    SUBDEVICE_102BDBC8 = 0x102BDBC8,
    SUBDEVICE_102BDBE2 = 0x102BDBE2,
    SUBDEVICE_102BDBE8 = 0x102BDBE8,
    SUBDEVICE_102BFF03 = 0x102BFF03,
    SUBDEVICE_102BFF04 = 0x102BFF04
};



inline const char8* enumToString(PciSubDevice102B0520 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0520::NONE:               return "NONE";
        case PciSubDevice102B0520::SUBDEVICE_102BDBC2: return "SUBDEVICE_102BDBC2";
        case PciSubDevice102B0520::SUBDEVICE_102BDBC8: return "SUBDEVICE_102BDBC8";
        case PciSubDevice102B0520::SUBDEVICE_102BDBE2: return "SUBDEVICE_102BDBE2";
        case PciSubDevice102B0520::SUBDEVICE_102BDBE8: return "SUBDEVICE_102BDBE8";
        case PciSubDevice102B0520::SUBDEVICE_102BFF03: return "SUBDEVICE_102BFF03";
        case PciSubDevice102B0520::SUBDEVICE_102BFF04: return "SUBDEVICE_102BFF04";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B0520 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B0520 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0520::SUBDEVICE_102BDBC2: return "G200 Multi-Monitor";
        case PciSubDevice102B0520::SUBDEVICE_102BDBC8: return "G200 Multi-Monitor";
        case PciSubDevice102B0520::SUBDEVICE_102BDBE2: return "G200 Multi-Monitor";
        case PciSubDevice102B0520::SUBDEVICE_102BDBE8: return "G200 Multi-Monitor";
        case PciSubDevice102B0520::SUBDEVICE_102BFF03: return "Millennium G200 SD";
        case PciSubDevice102B0520::SUBDEVICE_102BFF04: return "Marvel G200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0520_H
