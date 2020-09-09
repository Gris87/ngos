// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCISUBDEVICE1B6F7052_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCISUBDEVICE1B6F7052_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B6F7052: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_18497052 = 0x18497052
};



inline const char8* enumToString(PciSubDevice1B6F7052 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B6F7052::NONE:               return "NONE";
        case PciSubDevice1B6F7052::SUBDEVICE_18497052: return "SUBDEVICE_18497052";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B6F7052 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B6F7052 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B6F7052::SUBDEVICE_18497052: return "QC5000-ITX/PH";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCISUBDEVICE1B6F7052_H
