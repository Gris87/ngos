// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860126_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860126_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860126: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804CC = 0x102804CC,
    SUBDEVICE_17AA21CE = 0x17AA21CE,
    SUBDEVICE_17AA21CF = 0x17AA21CF
};



inline const char8* enumToString(PciSubDevice80860126 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860126::NONE:               return "NONE";
        case PciSubDevice80860126::SUBDEVICE_102804CC: return "SUBDEVICE_102804CC";
        case PciSubDevice80860126::SUBDEVICE_17AA21CE: return "SUBDEVICE_17AA21CE";
        case PciSubDevice80860126::SUBDEVICE_17AA21CF: return "SUBDEVICE_17AA21CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860126 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860126 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860126::SUBDEVICE_102804CC: return "Vostro 3350";
        case PciSubDevice80860126::SUBDEVICE_17AA21CE: return "ThinkPad T420";
        case PciSubDevice80860126::SUBDEVICE_17AA21CF: return "ThinkPad T520";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860126_H
