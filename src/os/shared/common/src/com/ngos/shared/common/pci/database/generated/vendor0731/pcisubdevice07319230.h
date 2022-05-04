// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07319230_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07319230_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice07319230: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07319230 = 0x07319230,
    SUBDEVICE_07319231 = 0x07319231
};



inline const char8* enumToString(PciSubDevice07319230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice07319230::NONE:               return "NONE";
        case PciSubDevice07319230::SUBDEVICE_07319230: return "SUBDEVICE_07319230";
        case PciSubDevice07319230::SUBDEVICE_07319231: return "SUBDEVICE_07319231";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice07319230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice07319230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice07319230::SUBDEVICE_07319230: return "JM9230";
        case PciSubDevice07319230::SUBDEVICE_07319231: return "JM9230-I";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07319230_H
