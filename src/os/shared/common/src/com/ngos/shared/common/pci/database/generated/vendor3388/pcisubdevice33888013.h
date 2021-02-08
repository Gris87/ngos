// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice33888013: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_33888013 = 0x33888013
};



inline const char8* enumToString(PciSubDevice33888013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33888013::NONE:               return "NONE";
        case PciSubDevice33888013::SUBDEVICE_33888013: return "SUBDEVICE_33888013";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice33888013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice33888013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33888013::SUBDEVICE_33888013: return "VXPro II Chipset EIDE Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888013_H
