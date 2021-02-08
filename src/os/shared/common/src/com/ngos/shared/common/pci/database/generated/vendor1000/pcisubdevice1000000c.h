// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000000C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10001010 = 0x10001010,
    SUBDEVICE_10001020 = 0x10001020,
    SUBDEVICE_1DE13906 = 0x1DE13906,
    SUBDEVICE_1DE13907 = 0x1DE13907
};



inline const char8* enumToString(PciSubDevice1000000C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000C::NONE:               return "NONE";
        case PciSubDevice1000000C::SUBDEVICE_10001010: return "SUBDEVICE_10001010";
        case PciSubDevice1000000C::SUBDEVICE_10001020: return "SUBDEVICE_10001020";
        case PciSubDevice1000000C::SUBDEVICE_1DE13906: return "SUBDEVICE_1DE13906";
        case PciSubDevice1000000C::SUBDEVICE_1DE13907: return "SUBDEVICE_1DE13907";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000000C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000000C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000C::SUBDEVICE_10001010: return "LSi8951U PCI to Ultra2 SCSI host adapter";
        case PciSubDevice1000000C::SUBDEVICE_10001020: return "LSi8952U PCI to Ultra2 SCSI host adapter";
        case PciSubDevice1000000C::SUBDEVICE_1DE13906: return "DC-390U2B SCSI adapter";
        case PciSubDevice1000000C::SUBDEVICE_1DE13907: return "DC-390U2W";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000C_H
