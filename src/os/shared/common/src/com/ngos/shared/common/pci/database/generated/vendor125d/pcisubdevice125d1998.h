// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1998_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1998_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125D1998: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800B1 = 0x102800B1,
    SUBDEVICE_102800E5 = 0x102800E5,
    SUBDEVICE_102800E6 = 0x102800E6
};



inline const char8* enumToString(PciSubDevice125D1998 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1998::NONE:               return "NONE";
        case PciSubDevice125D1998::SUBDEVICE_102800B1: return "SUBDEVICE_102800B1";
        case PciSubDevice125D1998::SUBDEVICE_102800E5: return "SUBDEVICE_102800E5";
        case PciSubDevice125D1998::SUBDEVICE_102800E6: return "SUBDEVICE_102800E6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125D1998 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125D1998 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1998::SUBDEVICE_102800B1: return "Latitude C600";
        case PciSubDevice125D1998::SUBDEVICE_102800E5: return "Latitude C810";
        case PciSubDevice125D1998::SUBDEVICE_102800E6: return "ES1983S Maestro-3i (Dell Inspiron 8100)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1998_H
