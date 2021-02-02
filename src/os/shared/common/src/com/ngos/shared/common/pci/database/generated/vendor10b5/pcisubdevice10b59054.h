// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59054_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59054_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59054: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B52455 = 0x10B52455,
    SUBDEVICE_10B52696 = 0x10B52696,
    SUBDEVICE_10B52717 = 0x10B52717,
    SUBDEVICE_10B52844 = 0x10B52844,
    SUBDEVICE_12C74001 = 0x12C74001,
    SUBDEVICE_12D90002 = 0x12D90002,
    SUBDEVICE_14B4D100 = 0x14B4D100,
    SUBDEVICE_14B4D114 = 0x14B4D114,
    SUBDEVICE_16DF0011 = 0x16DF0011,
    SUBDEVICE_16DF0012 = 0x16DF0012,
    SUBDEVICE_16DF0013 = 0x16DF0013,
    SUBDEVICE_16DF0014 = 0x16DF0014,
    SUBDEVICE_16DF0015 = 0x16DF0015,
    SUBDEVICE_16DF0016 = 0x16DF0016
};



inline const char8* enumToString(PciSubDevice10B59054 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59054::NONE:               return "NONE";
        case PciSubDevice10B59054::SUBDEVICE_10B52455: return "SUBDEVICE_10B52455";
        case PciSubDevice10B59054::SUBDEVICE_10B52696: return "SUBDEVICE_10B52696";
        case PciSubDevice10B59054::SUBDEVICE_10B52717: return "SUBDEVICE_10B52717";
        case PciSubDevice10B59054::SUBDEVICE_10B52844: return "SUBDEVICE_10B52844";
        case PciSubDevice10B59054::SUBDEVICE_12C74001: return "SUBDEVICE_12C74001";
        case PciSubDevice10B59054::SUBDEVICE_12D90002: return "SUBDEVICE_12D90002";
        case PciSubDevice10B59054::SUBDEVICE_14B4D100: return "SUBDEVICE_14B4D100";
        case PciSubDevice10B59054::SUBDEVICE_14B4D114: return "SUBDEVICE_14B4D114";
        case PciSubDevice10B59054::SUBDEVICE_16DF0011: return "SUBDEVICE_16DF0011";
        case PciSubDevice10B59054::SUBDEVICE_16DF0012: return "SUBDEVICE_16DF0012";
        case PciSubDevice10B59054::SUBDEVICE_16DF0013: return "SUBDEVICE_16DF0013";
        case PciSubDevice10B59054::SUBDEVICE_16DF0014: return "SUBDEVICE_16DF0014";
        case PciSubDevice10B59054::SUBDEVICE_16DF0015: return "SUBDEVICE_16DF0015";
        case PciSubDevice10B59054::SUBDEVICE_16DF0016: return "SUBDEVICE_16DF0016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59054 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59054 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59054::SUBDEVICE_10B52455: return "Wessex Techology PHIL-PCI";
        case PciSubDevice10B59054::SUBDEVICE_10B52696: return "Innes Corp AM Radcap card";
        case PciSubDevice10B59054::SUBDEVICE_10B52717: return "Innes Corp Auricon card";
        case PciSubDevice10B59054::SUBDEVICE_10B52844: return "Innes Corp TVS Encoder card";
        case PciSubDevice10B59054::SUBDEVICE_12C74001: return "Intel Dialogic DM/V960-4T1 PCI";
        case PciSubDevice10B59054::SUBDEVICE_12D90002: return "PCI Prosody Card rev 1.5";
        case PciSubDevice10B59054::SUBDEVICE_14B4D100: return "Dektec DTA-100";
        case PciSubDevice10B59054::SUBDEVICE_14B4D114: return "Dektec DTA-120";
        case PciSubDevice10B59054::SUBDEVICE_16DF0011: return "PIKA PrimeNet MM PCI";
        case PciSubDevice10B59054::SUBDEVICE_16DF0012: return "PIKA PrimeNet MM cPCI 8";
        case PciSubDevice10B59054::SUBDEVICE_16DF0013: return "PIKA PrimeNet MM cPCI 8 (without CAS Signaling)";
        case PciSubDevice10B59054::SUBDEVICE_16DF0014: return "PIKA PrimeNet MM cPCI 4";
        case PciSubDevice10B59054::SUBDEVICE_16DF0015: return "PIKA Daytona MM";
        case PciSubDevice10B59054::SUBDEVICE_16DF0016: return "PIKA InLine MM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59054_H
