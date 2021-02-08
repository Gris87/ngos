// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000000A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B143 = 0x0E11B143,
    SUBDEVICE_10001000 = 0x10001000
};



inline const char8* enumToString(PciSubDevice1000000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000A::NONE:               return "NONE";
        case PciSubDevice1000000A::SUBDEVICE_0E11B143: return "SUBDEVICE_0E11B143";
        case PciSubDevice1000000A::SUBDEVICE_10001000: return "SUBDEVICE_10001000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000000A::SUBDEVICE_0E11B143: return "Integrated Dual Channel Wide Ultra2 SCSI Controller";
        case PciSubDevice1000000A::SUBDEVICE_10001000: return "LSI53C1510 PCI to Dual Channel Wide Ultra2 SCSI Controller (Nonintelligent mode)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000000A_H
