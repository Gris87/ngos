// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168CFF1D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168CFF1D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168CFF1D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_168CEE1C = 0x168CEE1C
};



inline const char8* enumToString(PciSubDevice168CFF1D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168CFF1D::NONE:               return "NONE";
        case PciSubDevice168CFF1D::SUBDEVICE_168CEE1C: return "SUBDEVICE_168CEE1C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168CFF1D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168CFF1D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168CFF1D::SUBDEVICE_168CEE1C: return "AR9220-AC1A [AVM Fritz!Box FON WLAN 7270 v3]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168CFF1D_H
