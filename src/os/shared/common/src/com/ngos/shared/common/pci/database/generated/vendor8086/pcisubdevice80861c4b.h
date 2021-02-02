// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C4B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C4B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861C4B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804B2 = 0x102804B2,
    SUBDEVICE_102804DA = 0x102804DA
};



inline const char8* enumToString(PciSubDevice80861C4B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C4B::NONE:               return "NONE";
        case PciSubDevice80861C4B::SUBDEVICE_102804B2: return "SUBDEVICE_102804B2";
        case PciSubDevice80861C4B::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861C4B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861C4B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C4B::SUBDEVICE_102804B2: return "Vostro 3350";
        case PciSubDevice80861C4B::SUBDEVICE_102804DA: return "Vostro 3750";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C4B_H
