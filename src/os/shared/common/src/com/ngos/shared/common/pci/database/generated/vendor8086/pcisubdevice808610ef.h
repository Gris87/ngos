// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610EF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610EF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610EF: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102802DA = 0x102802DA,
    SUBDEVICE_15D9060D = 0x15D9060D
};



inline const char8* enumToString(PciSubDevice808610EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610EF::NONE:               return "NONE";
        case PciSubDevice808610EF::SUBDEVICE_102802DA: return "SUBDEVICE_102802DA";
        case PciSubDevice808610EF::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610EF::SUBDEVICE_102802DA: return "OptiPlex 980";
        case PciSubDevice808610EF::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610EF_H
