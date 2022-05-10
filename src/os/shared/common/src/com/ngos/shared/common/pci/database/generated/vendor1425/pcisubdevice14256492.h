// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1425_PCISUBDEVICE14256492_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1425_PCISUBDEVICE14256492_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14256492: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_01DEFFF9 = 0x01DEFFF9
};



inline const char8* enumToString(PciSubDevice14256492 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14256492::NONE:               return "NONE";
        case PciSubDevice14256492::SUBDEVICE_01DEFFF9: return "SUBDEVICE_01DEFFF9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14256492 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14256492 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14256492::SUBDEVICE_01DEFFF9: return "Gimlet T6";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1425_PCISUBDEVICE14256492_H
