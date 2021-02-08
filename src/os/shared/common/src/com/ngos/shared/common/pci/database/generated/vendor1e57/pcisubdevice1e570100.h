// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E57_PCISUBDEVICE1E570100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E57_PCISUBDEVICE1E570100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E570100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00000100 = 0x00000100
};



inline const char8* enumToString(PciSubDevice1E570100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E570100::NONE:               return "NONE";
        case PciSubDevice1E570100::SUBDEVICE_00000100: return "SUBDEVICE_00000100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E570100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E570100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E570100::SUBDEVICE_00000100: return "PY8800 64GB Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E57_PCISUBDEVICE1E570100_H
