// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCISUBDEVICE11790D01_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCISUBDEVICE11790D01_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11790D01: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11790001 = 0x11790001
};



inline const char8* enumToString(PciSubDevice11790D01 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11790D01::NONE:               return "NONE";
        case PciSubDevice11790D01::SUBDEVICE_11790001: return "SUBDEVICE_11790001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11790D01 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11790D01 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11790D01::SUBDEVICE_11790001: return "FIR Port Type-DO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCISUBDEVICE11790D01_H
