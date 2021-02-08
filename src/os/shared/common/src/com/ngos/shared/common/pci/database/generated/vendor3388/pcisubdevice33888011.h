// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888011_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888011_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice33888011: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_33888011 = 0x33888011
};



inline const char8* enumToString(PciSubDevice33888011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33888011::NONE:               return "NONE";
        case PciSubDevice33888011::SUBDEVICE_33888011: return "SUBDEVICE_33888011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice33888011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice33888011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice33888011::SUBDEVICE_33888011: return "VXPro II Chipset CPU to PCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCISUBDEVICE33888011_H
