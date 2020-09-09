// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6C_PCISUBDEVICE1D6C100D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6C_PCISUBDEVICE1D6C100D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1D6C100D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1D6C2001 = 0x1D6C2001
};



inline const char8* enumToString(PciSubDevice1D6C100D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1D6C100D::NONE:               return "NONE";
        case PciSubDevice1D6C100D::SUBDEVICE_1D6C2001: return "SUBDEVICE_1D6C2001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1D6C100D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1D6C100D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1D6C100D::SUBDEVICE_1D6C2001: return "DPDK-Aware Virtual Function [Arkville VF]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6C_PCISUBDEVICE1D6C100D_H
