// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10395513_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10395513_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10395513: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190970 = 0x10190970,
    SUBDEVICE_10395513 = 0x10395513,
    SUBDEVICE_10438035 = 0x10438035,
    SUBDEVICE_14627010 = 0x14627010,
    SUBDEVICE_16315513 = 0x16315513,
    SUBDEVICE_17341095 = 0x17341095
};



inline const char8* enumToString(PciSubDevice10395513 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10395513::NONE:               return "NONE";
        case PciSubDevice10395513::SUBDEVICE_10190970: return "SUBDEVICE_10190970";
        case PciSubDevice10395513::SUBDEVICE_10395513: return "SUBDEVICE_10395513";
        case PciSubDevice10395513::SUBDEVICE_10438035: return "SUBDEVICE_10438035";
        case PciSubDevice10395513::SUBDEVICE_14627010: return "SUBDEVICE_14627010";
        case PciSubDevice10395513::SUBDEVICE_16315513: return "SUBDEVICE_16315513";
        case PciSubDevice10395513::SUBDEVICE_17341095: return "SUBDEVICE_17341095";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10395513 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10395513 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10395513::SUBDEVICE_10190970: return "P6STP-FL motherboard";
        case PciSubDevice10395513::SUBDEVICE_10395513: return "SiS5513 EIDE Controller (A, B step)";
        case PciSubDevice10395513::SUBDEVICE_10438035: return "CUSI-FX motherboard";
        case PciSubDevice10395513::SUBDEVICE_14627010: return "MS-6701 motherboard";
        case PciSubDevice10395513::SUBDEVICE_16315513: return "GA-8SIML Rev1.0 Motherboard";
        case PciSubDevice10395513::SUBDEVICE_17341095: return "D2030-A1 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10395513_H
