// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1AB30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1AB30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C1AB30: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14CD2012 = 0x14CD2012
};



inline const char8* enumToString(PciSubDevice11C1AB30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C1AB30::NONE:               return "NONE";
        case PciSubDevice11C1AB30::SUBDEVICE_14CD2012: return "SUBDEVICE_14CD2012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C1AB30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C1AB30 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C1AB30::SUBDEVICE_14CD2012: return "Hermes2 Mini-PCI WaveLAN a/b/g";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1AB30_H
