// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCISUBDEVICE11F88536_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCISUBDEVICE11F88536_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11F88536: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1BD40081 = 0x1BD40081
};



inline const char8* enumToString(PciSubDevice11F88536 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11F88536::NONE:               return "NONE";
        case PciSubDevice11F88536::SUBDEVICE_1BD40081: return "SUBDEVICE_1BD40081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11F88536 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11F88536 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11F88536::SUBDEVICE_1BD40081: return "PM8536 PFX 96xG3 PCIe Fanout Switch";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCISUBDEVICE11F88536_H
