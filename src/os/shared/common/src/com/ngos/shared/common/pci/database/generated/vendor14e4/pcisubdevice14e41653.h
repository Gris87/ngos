// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41653_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41653_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41653: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100E3 = 0x0E1100E3,
    SUBDEVICE_17341073 = 0x17341073
};



inline const char8* enumToString(PciSubDevice14E41653 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41653::NONE:               return "NONE";
        case PciSubDevice14E41653::SUBDEVICE_0E1100E3: return "SUBDEVICE_0E1100E3";
        case PciSubDevice14E41653::SUBDEVICE_17341073: return "SUBDEVICE_17341073";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41653 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41653 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41653::SUBDEVICE_0E1100E3: return "NC7761 Gigabit Server Adapter";
        case PciSubDevice14E41653::SUBDEVICE_17341073: return "Primergy Econel 200 D2020 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41653_H
