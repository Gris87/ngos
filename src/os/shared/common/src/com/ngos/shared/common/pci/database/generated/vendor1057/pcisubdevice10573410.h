// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10573410_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10573410_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10573410: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_ECC00050 = 0xECC00050,
    SUBDEVICE_ECC00051 = 0xECC00051,
    SUBDEVICE_ECC00060 = 0xECC00060,
    SUBDEVICE_ECC00070 = 0xECC00070,
    SUBDEVICE_ECC00071 = 0xECC00071,
    SUBDEVICE_ECC00072 = 0xECC00072,
    SUBDEVICE_ECC00080 = 0xECC00080,
    SUBDEVICE_ECC00081 = 0xECC00081,
    SUBDEVICE_ECC00090 = 0xECC00090,
    SUBDEVICE_ECC000A0 = 0xECC000A0,
    SUBDEVICE_ECC000B0 = 0xECC000B0,
    SUBDEVICE_ECC00100 = 0xECC00100
};



inline const char8* enumToString(PciSubDevice10573410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10573410::NONE:               return "NONE";
        case PciSubDevice10573410::SUBDEVICE_ECC00050: return "SUBDEVICE_ECC00050";
        case PciSubDevice10573410::SUBDEVICE_ECC00051: return "SUBDEVICE_ECC00051";
        case PciSubDevice10573410::SUBDEVICE_ECC00060: return "SUBDEVICE_ECC00060";
        case PciSubDevice10573410::SUBDEVICE_ECC00070: return "SUBDEVICE_ECC00070";
        case PciSubDevice10573410::SUBDEVICE_ECC00071: return "SUBDEVICE_ECC00071";
        case PciSubDevice10573410::SUBDEVICE_ECC00072: return "SUBDEVICE_ECC00072";
        case PciSubDevice10573410::SUBDEVICE_ECC00080: return "SUBDEVICE_ECC00080";
        case PciSubDevice10573410::SUBDEVICE_ECC00081: return "SUBDEVICE_ECC00081";
        case PciSubDevice10573410::SUBDEVICE_ECC00090: return "SUBDEVICE_ECC00090";
        case PciSubDevice10573410::SUBDEVICE_ECC000A0: return "SUBDEVICE_ECC000A0";
        case PciSubDevice10573410::SUBDEVICE_ECC000B0: return "SUBDEVICE_ECC000B0";
        case PciSubDevice10573410::SUBDEVICE_ECC00100: return "SUBDEVICE_ECC00100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10573410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10573410 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10573410::SUBDEVICE_ECC00050: return "Gina24 rev.0";
        case PciSubDevice10573410::SUBDEVICE_ECC00051: return "Gina24 rev.1";
        case PciSubDevice10573410::SUBDEVICE_ECC00060: return "Layla24";
        case PciSubDevice10573410::SUBDEVICE_ECC00070: return "Mona rev.0";
        case PciSubDevice10573410::SUBDEVICE_ECC00071: return "Mona rev.1";
        case PciSubDevice10573410::SUBDEVICE_ECC00072: return "Mona rev.2";
        case PciSubDevice10573410::SUBDEVICE_ECC00080: return "Mia rev.0";
        case PciSubDevice10573410::SUBDEVICE_ECC00081: return "Mia rev.1";
        case PciSubDevice10573410::SUBDEVICE_ECC00090: return "Indigo";
        case PciSubDevice10573410::SUBDEVICE_ECC000A0: return "Indigo IO";
        case PciSubDevice10573410::SUBDEVICE_ECC000B0: return "Indigo DJ";
        case PciSubDevice10573410::SUBDEVICE_ECC00100: return "3G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10573410_H
