// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE900500C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE900500C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice900500C0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11F620 = 0x0E11F620,
    SUBDEVICE_9005F620 = 0x9005F620
};



inline const char8* enumToString(PciSubDevice900500C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice900500C0::NONE:               return "NONE";
        case PciSubDevice900500C0::SUBDEVICE_0E11F620: return "SUBDEVICE_0E11F620";
        case PciSubDevice900500C0::SUBDEVICE_9005F620: return "SUBDEVICE_9005F620";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice900500C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice900500C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice900500C0::SUBDEVICE_0E11F620: return "Compaq 64-Bit/66MHz Dual Channel Wide Ultra3 SCSI Adapter";
        case PciSubDevice900500C0::SUBDEVICE_9005F620: return "AHA-3960D U160/m";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE900500C0_H
