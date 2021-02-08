// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022790E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022790E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1022790E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8615 = 0x103C8615,
    SUBDEVICE_1043876B = 0x1043876B,
    SUBDEVICE_14627C37 = 0x14627C37,
    SUBDEVICE_17AA5124 = 0x17AA5124,
    SUBDEVICE_EA50CE19 = 0xEA50CE19
};



inline const char8* enumToString(PciSubDevice1022790E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1022790E::NONE:               return "NONE";
        case PciSubDevice1022790E::SUBDEVICE_103C8615: return "SUBDEVICE_103C8615";
        case PciSubDevice1022790E::SUBDEVICE_1043876B: return "SUBDEVICE_1043876B";
        case PciSubDevice1022790E::SUBDEVICE_14627C37: return "SUBDEVICE_14627C37";
        case PciSubDevice1022790E::SUBDEVICE_17AA5124: return "SUBDEVICE_17AA5124";
        case PciSubDevice1022790E::SUBDEVICE_EA50CE19: return "SUBDEVICE_EA50CE19";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1022790E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1022790E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1022790E::SUBDEVICE_103C8615: return "Pavilion Laptop 15-cw1xxx";
        case PciSubDevice1022790E::SUBDEVICE_1043876B: return "PRIME B450M-A Motherboard";
        case PciSubDevice1022790E::SUBDEVICE_14627C37: return "X570-A PRO motherboard";
        case PciSubDevice1022790E::SUBDEVICE_17AA5124: return "ThinkPad E595";
        case PciSubDevice1022790E::SUBDEVICE_EA50CE19: return "mCOM10-L1900";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE1022790E_H
