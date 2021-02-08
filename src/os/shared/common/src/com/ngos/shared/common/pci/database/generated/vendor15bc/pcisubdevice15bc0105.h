// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15BC_PCISUBDEVICE15BC0105_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15BC_PCISUBDEVICE15BC0105_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15BC0105: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0022 = 0x117C0022,
    SUBDEVICE_117C0025 = 0x117C0025,
    SUBDEVICE_117C0026 = 0x117C0026
};



inline const char8* enumToString(PciSubDevice15BC0105 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15BC0105::NONE:               return "NONE";
        case PciSubDevice15BC0105::SUBDEVICE_117C0022: return "SUBDEVICE_117C0022";
        case PciSubDevice15BC0105::SUBDEVICE_117C0025: return "SUBDEVICE_117C0025";
        case PciSubDevice15BC0105::SUBDEVICE_117C0026: return "SUBDEVICE_117C0026";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15BC0105 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15BC0105 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15BC0105::SUBDEVICE_117C0022: return "Celerity FC-42XS Fibre Channel Adapter";
        case PciSubDevice15BC0105::SUBDEVICE_117C0025: return "Celerity FC-44ES Fibre Channel Adapter";
        case PciSubDevice15BC0105::SUBDEVICE_117C0026: return "Celerity FC-42ES Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15BC_PCISUBDEVICE15BC0105_H
