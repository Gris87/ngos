// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0393_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0393_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0393: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE0412 = 0x10DE0412,
    SUBDEVICE_14620412 = 0x14620412
};



inline const char8* enumToString(PciSubDevice10DE0393 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0393::NONE:               return "NONE";
        case PciSubDevice10DE0393::SUBDEVICE_10DE0412: return "SUBDEVICE_10DE0412";
        case PciSubDevice10DE0393::SUBDEVICE_14620412: return "SUBDEVICE_14620412";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0393 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0393 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0393::SUBDEVICE_10DE0412: return "NX7300GT-TD256EH";
        case PciSubDevice10DE0393::SUBDEVICE_14620412: return "NX7300GT-TD256EH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0393_H
