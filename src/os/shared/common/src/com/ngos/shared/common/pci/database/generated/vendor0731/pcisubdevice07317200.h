// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07317200_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07317200_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice07317200: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07317201 = 0x07317201,
    SUBDEVICE_07317202 = 0x07317202,
    SUBDEVICE_07317208 = 0x07317208,
    SUBDEVICE_07317212 = 0x07317212,
    SUBDEVICE_07317214 = 0x07317214,
    SUBDEVICE_07317215 = 0x07317215
};



inline const char8* enumToString(PciSubDevice07317200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice07317200::NONE:               return "NONE";
        case PciSubDevice07317200::SUBDEVICE_07317201: return "SUBDEVICE_07317201";
        case PciSubDevice07317200::SUBDEVICE_07317202: return "SUBDEVICE_07317202";
        case PciSubDevice07317200::SUBDEVICE_07317208: return "SUBDEVICE_07317208";
        case PciSubDevice07317200::SUBDEVICE_07317212: return "SUBDEVICE_07317212";
        case PciSubDevice07317200::SUBDEVICE_07317214: return "SUBDEVICE_07317214";
        case PciSubDevice07317200::SUBDEVICE_07317215: return "SUBDEVICE_07317215";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice07317200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice07317200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice07317200::SUBDEVICE_07317201: return "JM7201";
        case PciSubDevice07317200::SUBDEVICE_07317202: return "JM7202";
        case PciSubDevice07317200::SUBDEVICE_07317208: return "JM7200";
        case PciSubDevice07317200::SUBDEVICE_07317212: return "JM7200";
        case PciSubDevice07317200::SUBDEVICE_07317214: return "JM7500";
        case PciSubDevice07317200::SUBDEVICE_07317215: return "JM7200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE07317200_H
