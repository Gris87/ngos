// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10575600_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10575600_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10575600: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10570300 = 0x10570300,
    SUBDEVICE_10570301 = 0x10570301,
    SUBDEVICE_10570302 = 0x10570302,
    SUBDEVICE_10575600 = 0x10575600,
    SUBDEVICE_13D20300 = 0x13D20300,
    SUBDEVICE_13D20301 = 0x13D20301,
    SUBDEVICE_13D20302 = 0x13D20302,
    SUBDEVICE_14360300 = 0x14360300,
    SUBDEVICE_14360301 = 0x14360301,
    SUBDEVICE_14360302 = 0x14360302,
    SUBDEVICE_144F100C = 0x144F100C,
    SUBDEVICE_14940300 = 0x14940300,
    SUBDEVICE_14940301 = 0x14940301,
    SUBDEVICE_14C80300 = 0x14C80300,
    SUBDEVICE_14C80302 = 0x14C80302,
    SUBDEVICE_16680300 = 0x16680300,
    SUBDEVICE_16680302 = 0x16680302
};



inline const char8* enumToString(PciSubDevice10575600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10575600::NONE:               return "NONE";
        case PciSubDevice10575600::SUBDEVICE_10570300: return "SUBDEVICE_10570300";
        case PciSubDevice10575600::SUBDEVICE_10570301: return "SUBDEVICE_10570301";
        case PciSubDevice10575600::SUBDEVICE_10570302: return "SUBDEVICE_10570302";
        case PciSubDevice10575600::SUBDEVICE_10575600: return "SUBDEVICE_10575600";
        case PciSubDevice10575600::SUBDEVICE_13D20300: return "SUBDEVICE_13D20300";
        case PciSubDevice10575600::SUBDEVICE_13D20301: return "SUBDEVICE_13D20301";
        case PciSubDevice10575600::SUBDEVICE_13D20302: return "SUBDEVICE_13D20302";
        case PciSubDevice10575600::SUBDEVICE_14360300: return "SUBDEVICE_14360300";
        case PciSubDevice10575600::SUBDEVICE_14360301: return "SUBDEVICE_14360301";
        case PciSubDevice10575600::SUBDEVICE_14360302: return "SUBDEVICE_14360302";
        case PciSubDevice10575600::SUBDEVICE_144F100C: return "SUBDEVICE_144F100C";
        case PciSubDevice10575600::SUBDEVICE_14940300: return "SUBDEVICE_14940300";
        case PciSubDevice10575600::SUBDEVICE_14940301: return "SUBDEVICE_14940301";
        case PciSubDevice10575600::SUBDEVICE_14C80300: return "SUBDEVICE_14C80300";
        case PciSubDevice10575600::SUBDEVICE_14C80302: return "SUBDEVICE_14C80302";
        case PciSubDevice10575600::SUBDEVICE_16680300: return "SUBDEVICE_16680300";
        case PciSubDevice10575600::SUBDEVICE_16680302: return "SUBDEVICE_16680302";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10575600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10575600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10575600::SUBDEVICE_10570300: return "SM56 PCI Speakerphone Modem";
        case PciSubDevice10575600::SUBDEVICE_10570301: return "SM56 PCI Voice Modem";
        case PciSubDevice10575600::SUBDEVICE_10570302: return "SM56 PCI Fax Modem";
        case PciSubDevice10575600::SUBDEVICE_10575600: return "SM56 PCI Voice modem";
        case PciSubDevice10575600::SUBDEVICE_13D20300: return "SM56 PCI Speakerphone Modem";
        case PciSubDevice10575600::SUBDEVICE_13D20301: return "SM56 PCI Voice modem";
        case PciSubDevice10575600::SUBDEVICE_13D20302: return "SM56 PCI Fax Modem";
        case PciSubDevice10575600::SUBDEVICE_14360300: return "SM56 PCI Speakerphone Modem";
        case PciSubDevice10575600::SUBDEVICE_14360301: return "SM56 PCI Voice modem";
        case PciSubDevice10575600::SUBDEVICE_14360302: return "SM56 PCI Fax Modem";
        case PciSubDevice10575600::SUBDEVICE_144F100C: return "SM56 PCI Fax Modem";
        case PciSubDevice10575600::SUBDEVICE_14940300: return "SM56 PCI Speakerphone Modem";
        case PciSubDevice10575600::SUBDEVICE_14940301: return "SM56 PCI Voice modem";
        case PciSubDevice10575600::SUBDEVICE_14C80300: return "SM56 PCI Speakerphone Modem";
        case PciSubDevice10575600::SUBDEVICE_14C80302: return "SM56 PCI Fax Modem";
        case PciSubDevice10575600::SUBDEVICE_16680300: return "SM56 PCI Speakerphone Modem";
        case PciSubDevice10575600::SUBDEVICE_16680302: return "SM56 PCI Fax Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10575600_H
