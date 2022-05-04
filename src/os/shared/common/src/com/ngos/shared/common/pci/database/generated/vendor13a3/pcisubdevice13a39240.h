// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCISUBDEVICE13A39240_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCISUBDEVICE13A39240_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13A39240: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13A39200 = 0x13A39200
};



inline const char8* enumToString(PciSubDevice13A39240 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13A39240::NONE:               return "NONE";
        case PciSubDevice13A39240::SUBDEVICE_13A39200: return "SUBDEVICE_13A39200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13A39240 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13A39240 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13A39240::SUBDEVICE_13A39200: return "DX2040 Compression and Security Acceleration Card [Panther II]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCISUBDEVICE13A39240_H
