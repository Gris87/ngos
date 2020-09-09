// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11027003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11027003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11027003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020040 = 0x11020040,
    SUBDEVICE_11020060 = 0x11020060
};



inline const char8* enumToString(PciSubDevice11027003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11027003::NONE:               return "NONE";
        case PciSubDevice11027003::SUBDEVICE_11020040: return "SUBDEVICE_11020040";
        case PciSubDevice11027003::SUBDEVICE_11020060: return "SUBDEVICE_11020060";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11027003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11027003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11027003::SUBDEVICE_11020040: return "SB Audigy Game Port";
        case PciSubDevice11027003::SUBDEVICE_11020060: return "SB Audigy2 MIDI/Game Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11027003_H
