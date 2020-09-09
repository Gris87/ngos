// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888012_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888012_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice33888012: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_33888012 = 0x33888012
};



inline const char8* enumToString(PciSubDevice33888012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33888012::NONE:               return "NONE";
        case PciSubDevice33888012::SUBDEVICE_33888012: return "SUBDEVICE_33888012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice33888012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice33888012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33888012::SUBDEVICE_33888012: return "VXPro II Chipset PCI to ISA Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888012_H
