// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20714_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20714_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19A20714: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3315 = 0x103C3315,
    SUBDEVICE_103C337B = 0x103C337B
};



inline const char8* enumToString(PciSubDevice19A20714 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20714::NONE:               return "NONE";
        case PciSubDevice19A20714::SUBDEVICE_103C3315: return "SUBDEVICE_103C3315";
        case PciSubDevice19A20714::SUBDEVICE_103C337B: return "SUBDEVICE_103C337B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19A20714 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19A20714 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20714::SUBDEVICE_103C3315: return "NC553i 10Gb 2-port FlexFabric Converged Network Adapter";
        case PciSubDevice19A20714::SUBDEVICE_103C337B: return "NC554FLB 10Gb 2-port FlexFabric Converged Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20714_H
