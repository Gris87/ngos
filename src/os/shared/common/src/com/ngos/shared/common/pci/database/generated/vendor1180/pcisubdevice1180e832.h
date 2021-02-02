// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE1180E832_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE1180E832_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1180E832: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040A = 0x1028040A,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_17AA21CF = 0x17AA21CF
};



inline const char8* enumToString(PciSubDevice1180E832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1180E832::NONE:               return "NONE";
        case PciSubDevice1180E832::SUBDEVICE_1028040A: return "SUBDEVICE_1028040A";
        case PciSubDevice1180E832::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice1180E832::SUBDEVICE_17AA21CF: return "SUBDEVICE_17AA21CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1180E832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1180E832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1180E832::SUBDEVICE_1028040A: return "Latitude E6410";
        case PciSubDevice1180E832::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice1180E832::SUBDEVICE_17AA21CF: return "ThinkPad T520";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE1180E832_H
