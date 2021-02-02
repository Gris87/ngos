// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10950680_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10950680_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10950680: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10950680 = 0x10950680,
    SUBDEVICE_10953680 = 0x10953680
};



inline const char8* enumToString(PciSubDevice10950680 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10950680::NONE:               return "NONE";
        case PciSubDevice10950680::SUBDEVICE_10950680: return "SUBDEVICE_10950680";
        case PciSubDevice10950680::SUBDEVICE_10953680: return "SUBDEVICE_10953680";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10950680 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10950680 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10950680::SUBDEVICE_10950680: return "SiI 0680 ATA/133 Controller";
        case PciSubDevice10950680::SUBDEVICE_10953680: return "Winic W-680 (Silicon Image 680 based)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10950680_H
