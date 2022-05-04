// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07319100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07319100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice07319100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07319101 = 0x07319101,
    SUBDEVICE_07319102 = 0x07319102
};



inline const char8* enumToString(PciSubDevice07319100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice07319100::NONE:               return "NONE";
        case PciSubDevice07319100::SUBDEVICE_07319101: return "SUBDEVICE_07319101";
        case PciSubDevice07319100::SUBDEVICE_07319102: return "SUBDEVICE_07319102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice07319100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice07319100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice07319100::SUBDEVICE_07319101: return "JM9100";
        case PciSubDevice07319100::SUBDEVICE_07319102: return "JM9100-I";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07319100_H
