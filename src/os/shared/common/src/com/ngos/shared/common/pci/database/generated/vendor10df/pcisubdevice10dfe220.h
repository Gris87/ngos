// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE220_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE220_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DFE220: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA1054 = 0x17AA1054,
    SUBDEVICE_17AA1055 = 0x17AA1055
};



inline const char8* enumToString(PciSubDevice10DFE220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFE220::NONE:               return "NONE";
        case PciSubDevice10DFE220::SUBDEVICE_17AA1054: return "SUBDEVICE_17AA1054";
        case PciSubDevice10DFE220::SUBDEVICE_17AA1055: return "SUBDEVICE_17AA1055";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DFE220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DFE220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFE220::SUBDEVICE_17AA1054: return "ThinkServer LPm16002B-M6-L AnyFabric";
        case PciSubDevice10DFE220::SUBDEVICE_17AA1055: return "ThinkServer LPm16004B-M8-L AnyFabric";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFE220_H
