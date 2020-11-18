// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862522_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862522_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862522: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80863806 = 0x80863806,
    SUBDEVICE_80863810 = 0x80863810
};



inline const char8* enumToString(PciSubDevice80862522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862522::NONE:               return "NONE";
        case PciSubDevice80862522::SUBDEVICE_80863806: return "SUBDEVICE_80863806";
        case PciSubDevice80862522::SUBDEVICE_80863810: return "SUBDEVICE_80863810";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862522::SUBDEVICE_80863806: return "Optane Memory 16GB";
        case PciSubDevice80862522::SUBDEVICE_80863810: return "Optane Memory M10 16GB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862522_H
