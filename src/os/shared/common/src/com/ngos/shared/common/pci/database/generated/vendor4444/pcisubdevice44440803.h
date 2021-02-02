// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4444_PCISUBDEVICE44440803_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4444_PCISUBDEVICE44440803_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice44440803: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00704000 = 0x00704000,
    SUBDEVICE_00704001 = 0x00704001,
    SUBDEVICE_00704800 = 0x00704800,
    SUBDEVICE_12AB0000 = 0x12AB0000,
    SUBDEVICE_1461A3CE = 0x1461A3CE,
    SUBDEVICE_1461A3CF = 0x1461A3CF
};



inline const char8* enumToString(PciSubDevice44440803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice44440803::NONE:               return "NONE";
        case PciSubDevice44440803::SUBDEVICE_00704000: return "SUBDEVICE_00704000";
        case PciSubDevice44440803::SUBDEVICE_00704001: return "SUBDEVICE_00704001";
        case PciSubDevice44440803::SUBDEVICE_00704800: return "SUBDEVICE_00704800";
        case PciSubDevice44440803::SUBDEVICE_12AB0000: return "SUBDEVICE_12AB0000";
        case PciSubDevice44440803::SUBDEVICE_1461A3CE: return "SUBDEVICE_1461A3CE";
        case PciSubDevice44440803::SUBDEVICE_1461A3CF: return "SUBDEVICE_1461A3CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice44440803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice44440803 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice44440803::SUBDEVICE_00704000: return "WinTV PVR-350";
        case PciSubDevice44440803::SUBDEVICE_00704001: return "WinTV PVR-250";
        case PciSubDevice44440803::SUBDEVICE_00704800: return "WinTV PVR-350 (V1)";
        case PciSubDevice44440803::SUBDEVICE_12AB0000: return "MPG160";
        case PciSubDevice44440803::SUBDEVICE_1461A3CE: return "M179";
        case PciSubDevice44440803::SUBDEVICE_1461A3CF: return "M179";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4444_PCISUBDEVICE44440803_H
