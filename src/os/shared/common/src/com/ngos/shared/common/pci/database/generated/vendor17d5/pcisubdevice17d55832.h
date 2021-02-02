// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55832_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55832_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D55832: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1337 = 0x103C1337,
    SUBDEVICE_10A98021 = 0x10A98021,
    SUBDEVICE_17D56020 = 0x17D56020,
    SUBDEVICE_17D56021 = 0x17D56021,
    SUBDEVICE_17D56022 = 0x17D56022,
    SUBDEVICE_17D56420 = 0x17D56420,
    SUBDEVICE_17D56421 = 0x17D56421,
    SUBDEVICE_17D56422 = 0x17D56422,
    SUBDEVICE_17D56C20 = 0x17D56C20,
    SUBDEVICE_17D56C21 = 0x17D56C21,
    SUBDEVICE_17D56C22 = 0x17D56C22
};



inline const char8* enumToString(PciSubDevice17D55832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D55832::NONE:               return "NONE";
        case PciSubDevice17D55832::SUBDEVICE_103C1337: return "SUBDEVICE_103C1337";
        case PciSubDevice17D55832::SUBDEVICE_10A98021: return "SUBDEVICE_10A98021";
        case PciSubDevice17D55832::SUBDEVICE_17D56020: return "SUBDEVICE_17D56020";
        case PciSubDevice17D55832::SUBDEVICE_17D56021: return "SUBDEVICE_17D56021";
        case PciSubDevice17D55832::SUBDEVICE_17D56022: return "SUBDEVICE_17D56022";
        case PciSubDevice17D55832::SUBDEVICE_17D56420: return "SUBDEVICE_17D56420";
        case PciSubDevice17D55832::SUBDEVICE_17D56421: return "SUBDEVICE_17D56421";
        case PciSubDevice17D55832::SUBDEVICE_17D56422: return "SUBDEVICE_17D56422";
        case PciSubDevice17D55832::SUBDEVICE_17D56C20: return "SUBDEVICE_17D56C20";
        case PciSubDevice17D55832::SUBDEVICE_17D56C21: return "SUBDEVICE_17D56C21";
        case PciSubDevice17D55832::SUBDEVICE_17D56C22: return "SUBDEVICE_17D56C22";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D55832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D55832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D55832::SUBDEVICE_103C1337: return "PCI-X 266MHz 10GigE SR [AD385A]";
        case PciSubDevice17D55832::SUBDEVICE_10A98021: return "Single Port 10-Gigabit Ethernet II (PCI-X, Fiber)";
        case PciSubDevice17D55832::SUBDEVICE_17D56020: return "Xframe II SR";
        case PciSubDevice17D55832::SUBDEVICE_17D56021: return "Xframe II SR, Low Profile";
        case PciSubDevice17D55832::SUBDEVICE_17D56022: return "Xframe E SR";
        case PciSubDevice17D55832::SUBDEVICE_17D56420: return "Xframe II LR";
        case PciSubDevice17D55832::SUBDEVICE_17D56421: return "Xframe II LR, Low Profile";
        case PciSubDevice17D55832::SUBDEVICE_17D56422: return "Xframe E LR";
        case PciSubDevice17D55832::SUBDEVICE_17D56C20: return "Xframe II CX4";
        case PciSubDevice17D55832::SUBDEVICE_17D56C21: return "Xframe II CX4, Low Profile";
        case PciSubDevice17D55832::SUBDEVICE_17D56C22: return "Xframe E CX4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D5_PCISUBDEVICE17D55832_H
