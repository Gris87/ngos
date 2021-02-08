// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771644_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771644_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10771644: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1077E4F8 = 0x1077E4F8
};



inline const char8* enumToString(PciSubDevice10771644 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771644::NONE:               return "NONE";
        case PciSubDevice10771644::SUBDEVICE_1077E4F8: return "SUBDEVICE_1077E4F8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10771644 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10771644 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771644::SUBDEVICE_1077E4F8: return "FastLinQ QL45611H 100GbE Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771644_H
