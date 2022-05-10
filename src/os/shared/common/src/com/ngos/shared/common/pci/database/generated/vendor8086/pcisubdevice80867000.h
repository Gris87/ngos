// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_01DEFFFD = 0x01DEFFFD,
    SUBDEVICE_1AF41100 = 0x1AF41100
};



inline const char8* enumToString(PciSubDevice80867000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867000::NONE:               return "NONE";
        case PciSubDevice80867000::SUBDEVICE_01DEFFFD: return "SUBDEVICE_01DEFFFD";
        case PciSubDevice80867000::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867000::SUBDEVICE_01DEFFFD: return "Propolis Virtual PIIX3 ISA Controller";
        case PciSubDevice80867000::SUBDEVICE_1AF41100: return "Qemu virtual machine";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867000_H
