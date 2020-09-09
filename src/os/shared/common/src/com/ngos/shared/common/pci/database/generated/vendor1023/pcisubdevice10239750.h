// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10239750_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10239750_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10239750: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10149750 = 0x10149750,
    SUBDEVICE_10239750 = 0x10239750
};



inline const char8* enumToString(PciSubDevice10239750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10239750::NONE:               return "NONE";
        case PciSubDevice10239750::SUBDEVICE_10149750: return "SUBDEVICE_10149750";
        case PciSubDevice10239750::SUBDEVICE_10239750: return "SUBDEVICE_10239750";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10239750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10239750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10239750::SUBDEVICE_10149750: return "3DImage 9750";
        case PciSubDevice10239750::SUBDEVICE_10239750: return "3DImage 9750";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10239750_H
