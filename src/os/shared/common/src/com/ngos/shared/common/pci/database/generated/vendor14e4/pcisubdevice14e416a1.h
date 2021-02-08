// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416A1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043866E = 0x1043866E
};



inline const char8* enumToString(PciSubDevice14E416A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A1::NONE:               return "NONE";
        case PciSubDevice14E416A1::SUBDEVICE_1043866E: return "SUBDEVICE_1043866E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A1::SUBDEVICE_1043866E: return "PEB-10G/57840-2T 10GBase-T Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A1_H
