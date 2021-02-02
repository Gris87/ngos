// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A25_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A25_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A25: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D,
    SUBDEVICE_102802F1 = 0x102802F1
};



inline const char8* enumToString(PciSubDevice80863A25 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A25::NONE:               return "NONE";
        case PciSubDevice80863A25::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice80863A25::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";
        case PciSubDevice80863A25::SUBDEVICE_102802F1: return "SUBDEVICE_102802F1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A25 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A25 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A25::SUBDEVICE_1028028C: return "PERC S100 Controller (PE R410)";
        case PciSubDevice80863A25::SUBDEVICE_1028028D: return "PERC S100 Controller (PE T410)";
        case PciSubDevice80863A25::SUBDEVICE_102802F1: return "PERC S100 Controller (PE R510)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A25_H
