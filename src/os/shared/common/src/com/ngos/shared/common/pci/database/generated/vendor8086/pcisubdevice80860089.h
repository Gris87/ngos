// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860089_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860089_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860089: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861311 = 0x80861311,
    SUBDEVICE_80861316 = 0x80861316
};



inline const char8* enumToString(PciSubDevice80860089 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860089::NONE:               return "NONE";
        case PciSubDevice80860089::SUBDEVICE_80861311: return "SUBDEVICE_80861311";
        case PciSubDevice80860089::SUBDEVICE_80861316: return "SUBDEVICE_80861316";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860089 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860089 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860089::SUBDEVICE_80861311: return "Centrino Advanced-N + WiMAX 6250 2x2 AGN";
        case PciSubDevice80860089::SUBDEVICE_80861316: return "Centrino Advanced-N + WiMAX 6250 2x2 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860089_H
