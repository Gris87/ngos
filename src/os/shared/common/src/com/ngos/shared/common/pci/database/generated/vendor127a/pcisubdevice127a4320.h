// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4320_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4320_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A4320: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12354320 = 0x12354320
};



inline const char8* enumToString(PciSubDevice127A4320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A4320::NONE:               return "NONE";
        case PciSubDevice127A4320::SUBDEVICE_12354320: return "SUBDEVICE_12354320";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A4320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A4320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A4320::SUBDEVICE_12354320: return "Riptide PCI Audio Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4320_H
