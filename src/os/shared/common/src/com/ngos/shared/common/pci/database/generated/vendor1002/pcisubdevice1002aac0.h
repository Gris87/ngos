// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AAC0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AAC0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002AAC0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043AAC0 = 0x1043AAC0
};



inline const char8* enumToString(PciSubDevice1002AAC0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AAC0::NONE:               return "NONE";
        case PciSubDevice1002AAC0::SUBDEVICE_1043AAC0: return "SUBDEVICE_1043AAC0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002AAC0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002AAC0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AAC0::SUBDEVICE_1043AAC0: return "R7260X-DC2OC-2GD5";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AAC0_H
