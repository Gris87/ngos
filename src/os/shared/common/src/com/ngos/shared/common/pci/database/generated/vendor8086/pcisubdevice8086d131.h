// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086D131_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086D131_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086D131: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102802DA = 0x102802DA,
    SUBDEVICE_15D9060D = 0x15D9060D
};



inline const char8* enumToString(PciSubDevice8086D131 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086D131::NONE:               return "NONE";
        case PciSubDevice8086D131::SUBDEVICE_102802DA: return "SUBDEVICE_102802DA";
        case PciSubDevice8086D131::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086D131 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086D131 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086D131::SUBDEVICE_102802DA: return "OptiPlex 980";
        case PciSubDevice8086D131::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086D131_H
