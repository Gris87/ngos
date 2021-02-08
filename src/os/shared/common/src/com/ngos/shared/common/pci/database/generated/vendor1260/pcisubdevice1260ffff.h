// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE1260FFFF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE1260FFFF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1260FFFF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12600000 = 0x12600000
};



inline const char8* enumToString(PciSubDevice1260FFFF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1260FFFF::NONE:               return "NONE";
        case PciSubDevice1260FFFF::SUBDEVICE_12600000: return "SUBDEVICE_12600000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1260FFFF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1260FFFF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1260FFFF::SUBDEVICE_12600000: return "Senao 3054MP+ (J) mini-PCI WLAN 802.11g adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE1260FFFF_H
