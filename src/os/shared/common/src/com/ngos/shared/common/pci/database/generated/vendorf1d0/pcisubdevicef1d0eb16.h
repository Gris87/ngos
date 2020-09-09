// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF1D0_PCISUBDEVICEF1D0EB16_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF1D0_PCISUBDEVICEF1D0EB16_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDeviceF1D0EB16: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF1049 = 0x10CF1049
};



inline const char8* enumToString(PciSubDeviceF1D0EB16 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceF1D0EB16::NONE:               return "NONE";
        case PciSubDeviceF1D0EB16::SUBDEVICE_10CF1049: return "SUBDEVICE_10CF1049";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDeviceF1D0EB16 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDeviceF1D0EB16 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceF1D0EB16::SUBDEVICE_10CF1049: return "Corvid HEVC M31";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORF1D0_PCISUBDEVICEF1D0EB16_H
