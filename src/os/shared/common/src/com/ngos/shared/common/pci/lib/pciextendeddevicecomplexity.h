#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMPLEXITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMPLEXITY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExtendedDeviceComplexity: u8
{
    SIMPLE_DEVICE = 0,
    BRIDGE_DEVICE = 1
};



inline const char8* enumToString(PciExtendedDeviceComplexity complexity) // TEST: NO
{
    // COMMON_LT((" | complexity = %u", complexity)); // Commented to avoid bad looking logs



    switch (complexity)
    {
        case PciExtendedDeviceComplexity::SIMPLE_DEVICE: return "SIMPLE_DEVICE";
        case PciExtendedDeviceComplexity::BRIDGE_DEVICE: return "BRIDGE_DEVICE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExtendedDeviceComplexity complexity) // TEST: NO
{
    // COMMON_LT((" | complexity = %u", complexity)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%02X (%s)", (u8)complexity, enumToString(complexity));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDDEVICECOMPLEXITY_H
