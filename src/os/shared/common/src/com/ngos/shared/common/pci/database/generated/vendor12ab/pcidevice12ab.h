// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AB_PCIDEVICE12AB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AB_PCIDEVICE12AB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12AB: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_2300 = 0x2300,
    DEVICE_3000 = 0x3000,
    DEVICE_4789 = 0x4789,
    DEVICE_FFF3 = 0xFFF3,
    DEVICE_FFFF = 0xFFFF
};



inline const char8* enumToString(PciDevice12AB device12AB) // TEST: NO
{
    // COMMON_LT((" | device12AB = %u", device12AB)); // Commented to avoid bad looking logs



    switch (device12AB)
    {
        case PciDevice12AB::DEVICE_0000: return "DEVICE_0000";
        case PciDevice12AB::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12AB::DEVICE_0003: return "DEVICE_0003";
        case PciDevice12AB::DEVICE_2300: return "DEVICE_2300";
        case PciDevice12AB::DEVICE_3000: return "DEVICE_3000";
        case PciDevice12AB::DEVICE_4789: return "DEVICE_4789";
        case PciDevice12AB::DEVICE_FFF3: return "DEVICE_FFF3";
        case PciDevice12AB::DEVICE_FFFF: return "DEVICE_FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12AB device12AB) // TEST: NO
{
    // COMMON_LT((" | device12AB = %u", device12AB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12AB, enumToString(device12AB));

    return res;
}



inline const char8* enumToHumanString(PciDevice12AB device12AB) // TEST: NO
{
    // COMMON_LT((" | device12AB = %u", device12AB)); // Commented to avoid bad looking logs



    switch (device12AB)
    {
        case PciDevice12AB::DEVICE_0000: return "MPG160/Kuroutoshikou ITVC15-STVLP";
        case PciDevice12AB::DEVICE_0002: return "AU8830 [Vortex2] Based Sound Card With A3D Support";
        case PciDevice12AB::DEVICE_0003: return "T507 (DVB-T) TV tuner/capture device";
        case PciDevice12AB::DEVICE_2300: return "Club-3D Zap TV2100";
        case PciDevice12AB::DEVICE_3000: return "MPG-200C PCI DVD Decoder Card";
        case PciDevice12AB::DEVICE_4789: return "MPC788 MiniPCI Hybrid TV Tuner";
        case PciDevice12AB::DEVICE_FFF3: return "MPG600/Kuroutoshikou ITVC16-STVLP";
        case PciDevice12AB::DEVICE_FFFF: return "MPG600/Kuroutoshikou ITVC16-STVLP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AB_PCIDEVICE12AB_H
