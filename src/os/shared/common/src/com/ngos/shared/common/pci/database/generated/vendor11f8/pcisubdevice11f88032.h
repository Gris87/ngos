// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCISUBDEVICE11F88032_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCISUBDEVICE11F88032_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11F88032: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C003A = 0x117C003A,
    SUBDEVICE_117C003B = 0x117C003B,
    SUBDEVICE_117C003C = 0x117C003C,
    SUBDEVICE_117C403B = 0x117C403B
};



inline const char8* enumToString(PciSubDevice11F88032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11F88032::NONE:               return "NONE";
        case PciSubDevice11F88032::SUBDEVICE_117C003A: return "SUBDEVICE_117C003A";
        case PciSubDevice11F88032::SUBDEVICE_117C003B: return "SUBDEVICE_117C003B";
        case PciSubDevice11F88032::SUBDEVICE_117C003C: return "SUBDEVICE_117C003C";
        case PciSubDevice11F88032::SUBDEVICE_117C403B: return "SUBDEVICE_117C403B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11F88032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11F88032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11F88032::SUBDEVICE_117C003A: return "Celerity FC-81EN Fibre Channel Adapter";
        case PciSubDevice11F88032::SUBDEVICE_117C003B: return "Celerity FC-82EN Fibre Channel Adapter";
        case PciSubDevice11F88032::SUBDEVICE_117C003C: return "Celerity FC-84EN Fibre Channel Adapter";
        case PciSubDevice11F88032::SUBDEVICE_117C403B: return "ThunderLink FC 1082 Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCISUBDEVICE11F88032_H
