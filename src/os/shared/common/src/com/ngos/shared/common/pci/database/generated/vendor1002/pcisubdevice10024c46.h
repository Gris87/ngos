// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C46_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C46_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C46: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020155 = 0x10020155,
    SUBDEVICE_10140155 = 0x10140155,
    SUBDEVICE_102800B1 = 0x102800B1
};



inline const char8* enumToString(PciSubDevice10024C46 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C46::NONE:               return "NONE";
        case PciSubDevice10024C46::SUBDEVICE_10020155: return "SUBDEVICE_10020155";
        case PciSubDevice10024C46::SUBDEVICE_10140155: return "SUBDEVICE_10140155";
        case PciSubDevice10024C46::SUBDEVICE_102800B1: return "SUBDEVICE_102800B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C46 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C46 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C46::SUBDEVICE_10020155: return "IBM Thinkpad A22p";
        case PciSubDevice10024C46::SUBDEVICE_10140155: return "Thinkpad A22p";
        case PciSubDevice10024C46::SUBDEVICE_102800B1: return "Latitude C600";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C46_H
