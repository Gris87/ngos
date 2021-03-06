// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317160_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317160_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11317160: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14589009 = 0x14589009,
    SUBDEVICE_14611455 = 0x14611455
};



inline const char8* enumToString(PciSubDevice11317160 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317160::NONE:               return "NONE";
        case PciSubDevice11317160::SUBDEVICE_14589009: return "SUBDEVICE_14589009";
        case PciSubDevice11317160::SUBDEVICE_14611455: return "SUBDEVICE_14611455";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11317160 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11317160 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317160::SUBDEVICE_14589009: return "E8000 DVB-T/Analog TV/FM tuner";
        case PciSubDevice11317160::SUBDEVICE_14611455: return "AVerTV Hybrid Speedy PCI-E (H788)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317160_H
