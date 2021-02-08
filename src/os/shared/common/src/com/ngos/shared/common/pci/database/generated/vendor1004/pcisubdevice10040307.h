// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040307_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040307_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10040307: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10040703 = 0x10040703,
    SUBDEVICE_10040705 = 0x10040705,
    SUBDEVICE_10040706 = 0x10040706
};



inline const char8* enumToString(PciSubDevice10040307 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040307::NONE:               return "NONE";
        case PciSubDevice10040307::SUBDEVICE_10040703: return "SUBDEVICE_10040703";
        case PciSubDevice10040307::SUBDEVICE_10040705: return "SUBDEVICE_10040705";
        case PciSubDevice10040307::SUBDEVICE_10040706: return "SUBDEVICE_10040706";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10040307 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10040307 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10040307::SUBDEVICE_10040703: return "Philips Rhythmic Edge PSC703";
        case PciSubDevice10040307::SUBDEVICE_10040705: return "Philips Seismic Edge PSC705";
        case PciSubDevice10040307::SUBDEVICE_10040706: return "Philips Acoustic Edge PSC706";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCISUBDEVICE10040307_H
