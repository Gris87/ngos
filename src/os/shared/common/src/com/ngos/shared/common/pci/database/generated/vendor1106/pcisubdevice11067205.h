// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11067205_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11067205_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11067205: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1458D000 = 0x1458D000,
    SUBDEVICE_14627061 = 0x14627061
};



inline const char8* enumToString(PciSubDevice11067205 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11067205::NONE:               return "NONE";
        case PciSubDevice11067205::SUBDEVICE_1458D000: return "SUBDEVICE_1458D000";
        case PciSubDevice11067205::SUBDEVICE_14627061: return "SUBDEVICE_14627061";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11067205 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11067205 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11067205::SUBDEVICE_1458D000: return "Gigabyte GA-7VM400(A)M(F) Motherboard";
        case PciSubDevice11067205::SUBDEVICE_14627061: return "MS-7061";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11067205_H
