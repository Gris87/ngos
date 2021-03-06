// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086D132_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086D132_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086D132: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040B = 0x1028040B
};



inline const char8* enumToString(PciSubDevice8086D132 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086D132::NONE:               return "NONE";
        case PciSubDevice8086D132::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086D132 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086D132 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086D132::SUBDEVICE_1028040B: return "Latitude E6510";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086D132_H
