// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F2100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F2100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1F3F2100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1F3F0120 = 0x1F3F0120,
    SUBDEVICE_1F3F0125 = 0x1F3F0125,
    SUBDEVICE_1F3F0180 = 0x1F3F0180,
    SUBDEVICE_1F3F0185 = 0x1F3F0185
};



inline const char8* enumToString(PciSubDevice1F3F2100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F2100::NONE:               return "NONE";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0120: return "SUBDEVICE_1F3F0120";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0125: return "SUBDEVICE_1F3F0125";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0180: return "SUBDEVICE_1F3F0180";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0185: return "SUBDEVICE_1F3F0185";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1F3F2100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1F3F2100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0120: return "HBA 32 Ports";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0125: return "HBA 40 Ports";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0180: return "HBA 16 Ports";
        case PciSubDevice1F3F2100::SUBDEVICE_1F3F0185: return "HBA 8 Ports";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F2100_H
