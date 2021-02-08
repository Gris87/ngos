// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11A0F7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11A0F7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0E11A0F7: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086002A = 0x8086002A,
    SUBDEVICE_8086002B = 0x8086002B
};



inline const char8* enumToString(PciSubDevice0E11A0F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11A0F7::NONE:               return "NONE";
        case PciSubDevice0E11A0F7::SUBDEVICE_8086002A: return "SUBDEVICE_8086002A";
        case PciSubDevice0E11A0F7::SUBDEVICE_8086002B: return "SUBDEVICE_8086002B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0E11A0F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0E11A0F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11A0F7::SUBDEVICE_8086002A: return "PCI Hotplug Controller A";
        case PciSubDevice0E11A0F7::SUBDEVICE_8086002B: return "PCI Hotplug Controller B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11A0F7_H
