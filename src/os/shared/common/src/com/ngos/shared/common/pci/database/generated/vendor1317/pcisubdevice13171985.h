// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCISUBDEVICE13171985_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCISUBDEVICE13171985_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13171985: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1385511A = 0x1385511A,
    SUBDEVICE_13952103 = 0x13952103
};



inline const char8* enumToString(PciSubDevice13171985 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13171985::NONE:               return "NONE";
        case PciSubDevice13171985::SUBDEVICE_1385511A: return "SUBDEVICE_1385511A";
        case PciSubDevice13171985::SUBDEVICE_13952103: return "SUBDEVICE_13952103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13171985 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13171985 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13171985::SUBDEVICE_1385511A: return "FA511";
        case PciSubDevice13171985::SUBDEVICE_13952103: return "CB100-EZ (4-LED version)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCISUBDEVICE13171985_H
