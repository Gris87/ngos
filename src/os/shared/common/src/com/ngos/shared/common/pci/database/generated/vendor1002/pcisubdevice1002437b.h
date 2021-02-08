// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002437B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002437B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002437B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002437B = 0x1002437B,
    SUBDEVICE_10CF1326 = 0x10CF1326,
    SUBDEVICE_173410B8 = 0x173410B8
};



inline const char8* enumToString(PciSubDevice1002437B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002437B::NONE:               return "NONE";
        case PciSubDevice1002437B::SUBDEVICE_1002437B: return "SUBDEVICE_1002437B";
        case PciSubDevice1002437B::SUBDEVICE_10CF1326: return "SUBDEVICE_10CF1326";
        case PciSubDevice1002437B::SUBDEVICE_173410B8: return "SUBDEVICE_173410B8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002437B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002437B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002437B::SUBDEVICE_1002437B: return "IXP SB4x0 High Definition Audio Controller";
        case PciSubDevice1002437B::SUBDEVICE_10CF1326: return "Fujitsu Lifebook A3040";
        case PciSubDevice1002437B::SUBDEVICE_173410B8: return "Realtek High Definition Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002437B_H
