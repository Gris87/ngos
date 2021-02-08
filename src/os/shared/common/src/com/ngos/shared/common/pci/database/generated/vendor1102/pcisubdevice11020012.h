// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020012_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020012_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020012: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020010 = 0x11020010
};



inline const char8* enumToString(PciSubDevice11020012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020012::NONE:               return "NONE";
        case PciSubDevice11020012::SUBDEVICE_11020010: return "SUBDEVICE_11020010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020012::SUBDEVICE_11020010: return "SB1570 SB Audigy Fx";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020012_H
