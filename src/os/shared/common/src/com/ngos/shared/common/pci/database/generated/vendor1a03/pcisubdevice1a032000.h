// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A03_PCISUBDEVICE1A032000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A03_PCISUBDEVICE1A032000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1A032000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15D90832 = 0x15D90832,
    SUBDEVICE_15D91B95 = 0x15D91B95
};



inline const char8* enumToString(PciSubDevice1A032000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1A032000::NONE:               return "NONE";
        case PciSubDevice1A032000::SUBDEVICE_15D90832: return "SUBDEVICE_15D90832";
        case PciSubDevice1A032000::SUBDEVICE_15D91B95: return "SUBDEVICE_15D91B95";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1A032000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1A032000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1A032000::SUBDEVICE_15D90832: return "X10SRL-F";
        case PciSubDevice1A032000::SUBDEVICE_15D91B95: return "H12SSL-i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A03_PCISUBDEVICE1A032000_H
