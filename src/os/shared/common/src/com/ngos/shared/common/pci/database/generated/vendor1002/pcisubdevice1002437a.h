// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002437A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002437A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002437A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10024379 = 0x10024379,
    SUBDEVICE_1002437A = 0x1002437A,
    SUBDEVICE_14627141 = 0x14627141,
    SUBDEVICE_14F18800 = 0x14F18800
};



inline const char8* enumToString(PciSubDevice1002437A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002437A::NONE:               return "NONE";
        case PciSubDevice1002437A::SUBDEVICE_10024379: return "SUBDEVICE_10024379";
        case PciSubDevice1002437A::SUBDEVICE_1002437A: return "SUBDEVICE_1002437A";
        case PciSubDevice1002437A::SUBDEVICE_14627141: return "SUBDEVICE_14627141";
        case PciSubDevice1002437A::SUBDEVICE_14F18800: return "SUBDEVICE_14F18800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002437A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002437A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002437A::SUBDEVICE_10024379: return "4379 Serial ATA Controller";
        case PciSubDevice1002437A::SUBDEVICE_1002437A: return "437A Serial ATA Controller";
        case PciSubDevice1002437A::SUBDEVICE_14627141: return "Aspire L250";
        case PciSubDevice1002437A::SUBDEVICE_14F18800: return "Leadtek WinFast TV2000XP Expert";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002437A_H
