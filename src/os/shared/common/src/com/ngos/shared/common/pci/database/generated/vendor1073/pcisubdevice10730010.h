// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE10730010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE10730010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10730010: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10730006 = 0x10730006,
    SUBDEVICE_10730010 = 0x10730010
};



inline const char8* enumToString(PciSubDevice10730010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10730010::NONE:               return "NONE";
        case PciSubDevice10730010::SUBDEVICE_10730006: return "SUBDEVICE_10730006";
        case PciSubDevice10730010::SUBDEVICE_10730010: return "SUBDEVICE_10730010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10730010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10730010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10730010::SUBDEVICE_10730006: return "DS-XG PCI Audio CODEC";
        case PciSubDevice10730010::SUBDEVICE_10730010: return "DS-XG PCI Audio CODEC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE10730010_H
