// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024744_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024744_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024744: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10024744 = 0x10024744,
    SUBDEVICE_80864D55 = 0x80864D55
};



inline const char8* enumToString(PciSubDevice10024744 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024744::NONE:               return "NONE";
        case PciSubDevice10024744::SUBDEVICE_10024744: return "SUBDEVICE_10024744";
        case PciSubDevice10024744::SUBDEVICE_80864D55: return "SUBDEVICE_80864D55";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024744 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024744 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024744::SUBDEVICE_10024744: return "Rage Pro Turbo AGP";
        case PciSubDevice10024744::SUBDEVICE_80864D55: return "Rage 3D Pro AGP 1X [Intel MU440EX]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024744_H
