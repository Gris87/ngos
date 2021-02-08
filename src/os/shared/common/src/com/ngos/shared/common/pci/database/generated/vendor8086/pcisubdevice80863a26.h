// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A26_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A26_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A26: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D
};



inline const char8* enumToString(PciSubDevice80863A26 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A26::NONE:               return "NONE";
        case PciSubDevice80863A26::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice80863A26::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A26 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A26 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A26::SUBDEVICE_1028028C: return "PowerEdge R410 SATA IDE Controller";
        case PciSubDevice80863A26::SUBDEVICE_1028028D: return "PowerEdge T410 SATA IDE Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A26_H
