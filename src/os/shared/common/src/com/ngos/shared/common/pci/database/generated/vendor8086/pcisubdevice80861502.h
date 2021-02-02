// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861502_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861502_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861502: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804A3 = 0x102804A3,
    SUBDEVICE_17AA21CE = 0x17AA21CE,
    SUBDEVICE_80863578 = 0x80863578,
    SUBDEVICE_8086357A = 0x8086357A
};



inline const char8* enumToString(PciSubDevice80861502 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861502::NONE:               return "NONE";
        case PciSubDevice80861502::SUBDEVICE_102804A3: return "SUBDEVICE_102804A3";
        case PciSubDevice80861502::SUBDEVICE_17AA21CE: return "SUBDEVICE_17AA21CE";
        case PciSubDevice80861502::SUBDEVICE_80863578: return "SUBDEVICE_80863578";
        case PciSubDevice80861502::SUBDEVICE_8086357A: return "SUBDEVICE_8086357A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861502 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861502 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861502::SUBDEVICE_102804A3: return "Precision M4600";
        case PciSubDevice80861502::SUBDEVICE_17AA21CE: return "ThinkPad T520";
        case PciSubDevice80861502::SUBDEVICE_80863578: return "Server Board S1200BTLR";
        case PciSubDevice80861502::SUBDEVICE_8086357A: return "Server Board S1200BTS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861502_H
