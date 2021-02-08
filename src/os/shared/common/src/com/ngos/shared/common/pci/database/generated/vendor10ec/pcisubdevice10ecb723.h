// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10ECB723_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10ECB723_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10ECB723: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10EC8739 = 0x10EC8739,
    SUBDEVICE_17AAB736 = 0x17AAB736
};



inline const char8* enumToString(PciSubDevice10ECB723 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10ECB723::NONE:               return "NONE";
        case PciSubDevice10ECB723::SUBDEVICE_10EC8739: return "SUBDEVICE_10EC8739";
        case PciSubDevice10ECB723::SUBDEVICE_17AAB736: return "SUBDEVICE_17AAB736";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10ECB723 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10ECB723 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10ECB723::SUBDEVICE_10EC8739: return "Dell Wireless 1801";
        case PciSubDevice10ECB723::SUBDEVICE_17AAB736: return "Z50-75";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10ECB723_H
