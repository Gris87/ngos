// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B48_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B48_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B48: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040A = 0x1028040A,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_144DC06A = 0x144DC06A
};



inline const char8* enumToString(PciSubDevice80863B48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B48::NONE:               return "NONE";
        case PciSubDevice80863B48::SUBDEVICE_1028040A: return "SUBDEVICE_1028040A";
        case PciSubDevice80863B48::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice80863B48::SUBDEVICE_144DC06A: return "SUBDEVICE_144DC06A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B48::SUBDEVICE_1028040A: return "Latitude E6410";
        case PciSubDevice80863B48::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice80863B48::SUBDEVICE_144DC06A: return "R730 Laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B48_H
