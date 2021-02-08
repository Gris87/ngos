// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771216_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771216_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10771216: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101E8471 = 0x101E8471,
    SUBDEVICE_101E8493 = 0x101E8493
};



inline const char8* enumToString(PciSubDevice10771216 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771216::NONE:               return "NONE";
        case PciSubDevice10771216::SUBDEVICE_101E8471: return "SUBDEVICE_101E8471";
        case PciSubDevice10771216::SUBDEVICE_101E8493: return "SUBDEVICE_101E8493";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10771216 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10771216 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771216::SUBDEVICE_101E8471: return "QLA12160 on AMI MegaRAID";
        case PciSubDevice10771216::SUBDEVICE_101E8493: return "QLA12160 on AMI MegaRAID";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771216_H
