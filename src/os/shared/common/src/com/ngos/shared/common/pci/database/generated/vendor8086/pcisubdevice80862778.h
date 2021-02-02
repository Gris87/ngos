// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862778_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862778_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862778: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801DF = 0x102801DF,
    SUBDEVICE_102801E6 = 0x102801E6
};



inline const char8* enumToString(PciSubDevice80862778 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862778::NONE:               return "NONE";
        case PciSubDevice80862778::SUBDEVICE_102801DF: return "SUBDEVICE_102801DF";
        case PciSubDevice80862778::SUBDEVICE_102801E6: return "SUBDEVICE_102801E6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862778 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862778 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862778::SUBDEVICE_102801DF: return "PowerEdge SC440";
        case PciSubDevice80862778::SUBDEVICE_102801E6: return "PowerEdge 860";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862778_H
