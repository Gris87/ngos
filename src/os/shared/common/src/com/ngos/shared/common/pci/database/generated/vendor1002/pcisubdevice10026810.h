// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026810_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026810_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026810: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B012A = 0x106B012A,
    SUBDEVICE_106B012B = 0x106B012B,
    SUBDEVICE_148C0908 = 0x148C0908,
    SUBDEVICE_16827370 = 0x16827370
};



inline const char8* enumToString(PciSubDevice10026810 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026810::NONE:               return "NONE";
        case PciSubDevice10026810::SUBDEVICE_106B012A: return "SUBDEVICE_106B012A";
        case PciSubDevice10026810::SUBDEVICE_106B012B: return "SUBDEVICE_106B012B";
        case PciSubDevice10026810::SUBDEVICE_148C0908: return "SUBDEVICE_148C0908";
        case PciSubDevice10026810::SUBDEVICE_16827370: return "SUBDEVICE_16827370";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026810 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026810 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026810::SUBDEVICE_106B012A: return "FirePro D300";
        case PciSubDevice10026810::SUBDEVICE_106B012B: return "FirePro D300";
        case PciSubDevice10026810::SUBDEVICE_148C0908: return "Radeon R9 370 OEM";
        case PciSubDevice10026810::SUBDEVICE_16827370: return "Radeon R7 370";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026810_H
