// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101C_PCIDEVICE101C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101C_PCIDEVICE101C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice101C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0193 = 0x0193,
    DEVICE_0196 = 0x0196,
    DEVICE_0197 = 0x0197,
    DEVICE_0296 = 0x0296,
    DEVICE_3193 = 0x3193,
    DEVICE_3197 = 0x3197,
    DEVICE_3296 = 0x3296,
    DEVICE_4296 = 0x4296,
    DEVICE_9710 = 0x9710,
    DEVICE_9712 = 0x9712,
    DEVICE_C24A = 0xC24A
};



inline const char8* enumToString(PciDevice101C device101C) // TEST: NO
{
    // COMMON_LT((" | device101C = %u", device101C)); // Commented to avoid bad looking logs



    switch (device101C)
    {
        case PciDevice101C::NONE:        return "NONE";
        case PciDevice101C::DEVICE_0193: return "DEVICE_0193";
        case PciDevice101C::DEVICE_0196: return "DEVICE_0196";
        case PciDevice101C::DEVICE_0197: return "DEVICE_0197";
        case PciDevice101C::DEVICE_0296: return "DEVICE_0296";
        case PciDevice101C::DEVICE_3193: return "DEVICE_3193";
        case PciDevice101C::DEVICE_3197: return "DEVICE_3197";
        case PciDevice101C::DEVICE_3296: return "DEVICE_3296";
        case PciDevice101C::DEVICE_4296: return "DEVICE_4296";
        case PciDevice101C::DEVICE_9710: return "DEVICE_9710";
        case PciDevice101C::DEVICE_9712: return "DEVICE_9712";
        case PciDevice101C::DEVICE_C24A: return "DEVICE_C24A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice101C device101C) // TEST: NO
{
    // COMMON_LT((" | device101C = %u", device101C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device101C, enumToString(device101C));

    return res;
}



inline const char8* enumToHumanString(PciDevice101C device101C) // TEST: NO
{
    // COMMON_LT((" | device101C = %u", device101C)); // Commented to avoid bad looking logs



    switch (device101C)
    {
        case PciDevice101C::DEVICE_0193: return "33C193A";
        case PciDevice101C::DEVICE_0196: return "33C196A";
        case PciDevice101C::DEVICE_0197: return "33C197A";
        case PciDevice101C::DEVICE_0296: return "33C296A";
        case PciDevice101C::DEVICE_3193: return "7193";
        case PciDevice101C::DEVICE_3197: return "7197";
        case PciDevice101C::DEVICE_3296: return "33C296A";
        case PciDevice101C::DEVICE_4296: return "34C296";
        case PciDevice101C::DEVICE_9710: return "Pipeline 9710";
        case PciDevice101C::DEVICE_9712: return "Pipeline 9712";
        case PciDevice101C::DEVICE_C24A: return "90C";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101C_PCIDEVICE101C_H
